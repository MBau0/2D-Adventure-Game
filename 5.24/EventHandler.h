#include <list>
#include <map>
#include <typeindex>

#include "HandlerFunction.h"
#include "MemberHandlerFunction.h"

#include <iostream>

#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

typedef std::list<HandlerFunction *> HandlerList;

class EventHandler {
public:
	EventHandler() {}
	~EventHandler() {
		for (auto it = _subscribers.begin(); it != _subscribers.end(); it++) {
			for (auto itt = it->second.begin(); itt != it->second.end(); itt++) {
				delete *itt;
			}
		}
	}

	template <typename EventType>
	void publish(EventType *event) {
		if (_subscribers.find(typeid(EventType)) == _subscribers.end()) {
			return;
		}

		for (auto &handler : _subscribers[typeid(EventType)]) {
			if (handler != nullptr) {
				handler->execute(event);
			}
		}
	}

	template<class T, class EventType>
	void subscribe(T *instance, void (T::*memberFunction)(EventType *)) {
		_subscribers[typeid(EventType)].push_back(new MemberHandlerFunction<T, EventType>(instance, memberFunction));
	}

	template <class T, class EventType>
	void unsubscribe(T *instance, void (T::*memberFunction)(EventType *)) {
		HandlerList *handlers = &_subscribers[typeid(EventType)];

		for (auto it = handlers->begin(); it != handlers->end(); it++) {
			MemberHandlerFunction<T, EventType> *handler = static_cast<MemberHandlerFunction<T, EventType> *>(*it);

			if (handler->getInstance() == instance && handler->getMemberFunction() == memberFunction) {
				delete (*it);
				handlers->erase(it);
				break;
			}
		}
	}
private:
	std::map<std::type_index, HandlerList> _subscribers;
};

#endif