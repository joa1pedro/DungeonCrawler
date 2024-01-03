#pragma once
#include <string>

class Character
{
private:
	std::string _name;
	int _health = 100;
	int _damage = 10;

public:
	//Constructor
	Character(std::string name, int damage);

	//Getters
	const std::string& GetName();

	int GetCurrentHealth();

	int GetDamage();

	//Methods
	void TakeDamage(int damage);
};