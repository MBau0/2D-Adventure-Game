#include "Environment.h"

#include <cassert>

#include "Clock.h"
#include "Log.h"
#include "Window.h"
#include "ScriptManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "UIManager.h"

Environment *Environment::_instance = nullptr;

Environment::Environment() :
	_mode					( NULL ),
	_clock					( nullptr ),
	_log					( nullptr ),
	_window					( nullptr ),
	_script_manager			( nullptr ),
	_resource_manager		( nullptr ),
	_input_manager			( nullptr ),
	_ui_manager				( nullptr )
{
	assert(!_instance);
	_instance = this;
}

Environment::~Environment() {
	shutdown();
	_instance = nullptr;
}

void Environment::shutdown() {
	delete _ui_manager;
	_ui_manager = nullptr;

	delete _input_manager;
	_input_manager = nullptr;

	delete _resource_manager;
	_resource_manager = nullptr;

	delete _script_manager;
	_script_manager = nullptr;

	delete _window;
	_window = nullptr;

	delete _log;
	_log = nullptr;

	delete _clock;
	_clock = nullptr;
}

Environment &Environment::get(){
	assert(_instance);
	return *_instance;
}

void Environment::set_mode(int mode) {
	_mode = mode;
}

void Environment::set_clock(Clock *clock) {
	_clock = clock;
}

void Environment::set_log(Log *log) {
	_log = log;
}

void Environment::set_window(Window *window) {
	_window = window;
}

void Environment::set_script_manager(ScriptManager *scriptManager) {
	_script_manager = scriptManager;
}

void Environment::set_resource_manager(ResourceManager *resourceManager) {
	_resource_manager = resourceManager;
}

void Environment::set_input_manager(InputManager *inputManager) {
	_input_manager = inputManager;
}

void Environment::set_ui_manager(UIManager *uiManager) {
	_ui_manager = uiManager;
}

int Environment::get_mode() {
	return _mode;
}

Clock *Environment::get_clock() {
	return _clock;
}

Log *Environment::get_log() {
	return _log;
}

Window *Environment::get_window() {
	return _window;
}

ScriptManager *Environment::get_script_manager() {
	return _script_manager;
}

ResourceManager *Environment::get_resource_manager() {
	return _resource_manager;
}

InputManager *Environment::get_input_manager() {
	return _input_manager;
}

UIManager *Environment::get_ui_manager() {
	return _ui_manager;
}