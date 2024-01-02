#pragma once
#include <string>

class Character
{
	std::string _name;
	int _health = 100;
	int _damage = 10;

public:
	Character(std::string name, int damage);

	std::string GetName() {
		return _name;
	}

	int GetCurrentHealth() {
		return _health;
	}

	int GetDamage() {
		return _damage;
	}

	void TakeDamage(int damage) {
		if (_health <= 0) {
			std::cout << "Character is already Dead\n";
			return;
		}
		_health = _health - damage;
	}
};

// Constructor for a Character, Health default is 100
Character::Character(std::string name, int damage) {
	_name = name;
	_damage = damage;
}
