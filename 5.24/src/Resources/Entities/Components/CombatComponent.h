#include "Component.h"

#include "Timer.h"

#ifndef COMBAT_COMPONENT_H
#define COMBAT_COMPONENT_H

struct CombatComponent : public Component {
	CombatComponent(Entity *entity_, int max_health_, int max_mana_, int damage_, int armor_, int combat_time);
	CombatComponent(Entity *new_entity, const CombatComponent &rhs);
	CombatComponent *copy(Entity *new_entity) const;

	void update();

	const int get_type() const ;

	void apply_damage(int damage_, const SDL_Color &color);

	void draw_health();

	void start_combat();

	int health;
	int max_health;
	int mana;
	int max_mana;

	int damage;
	int armor;

	bool in_combat;
	Timer combat_timer;
};

#endif