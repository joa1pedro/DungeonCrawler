#pragma once
#include <string>

class Character
{
	std::string _name;
	int _health = 100;

public:
	Character(std::string name);

	std::string GetName() {
		return _name;
	}

	int  GetCurrentHealth() {
		return _health;
	}
};

// Constructor with only name, Health default is 100
Character::Character(std::string name) {
	_name = name;
}
