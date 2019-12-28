
#include "Component.h"
#include "Entity.h"

#include "Path.h"

#ifndef NPC_COMPONENT_H
#define NPC_COMPONENT_H

struct NPCComponent : public Component {
	NPCComponent(Entity *entity_, std::string script_name_, std::string script_, int quest_id_);
	NPCComponent(Entity *new_entity, const NPCComponent &rhs);
	NPCComponent *copy(Entity *new_entity) const;

	~NPCComponent() {}

	void update();

	const int get_type() const { return COMPONENT_NPC; }

	bool is_collision();

	int current_line;
	int quest_id;

	std::vector<Path> pathing;

	std::string script_name;
	std::string script;
};

#endif