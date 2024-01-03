#pragma once
#include <iostream>
#include "Character.h"

// Constructor for a Character, Health default is 100
Character::Character(std::string name, int damage) {
	_name = name;
	_damage = damage;
}

//Getters
const std::string& Character::GetName() {
	return _name;
}

int Character::GetCurrentHealth() {
	return _health;
}

int Character::GetDamage() {
	return _damage;
}

//Methods
void Character::TakeDamage(int damage) {
	if (_health <= 0) {
		std::cout << "Character is already Dead\n";
		return;
	}
	_health = _health - damage;
}