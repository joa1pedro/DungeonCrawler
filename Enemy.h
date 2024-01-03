#pragma once
#include "Sizes.h"

class Enemy
{
	int _health = 100;
	int _damage = 1;
	Sizes _size = Sizes::Small;

public:
	//Constructor
	Enemy(int health, int damage, Sizes size);

	//Getters
	int GetCurrentHealth() {
		return _health;
	}
	int GetDamage() {
		return _damage;
	}
	int GetSize() {
		return _size;
	}

	void TakeDamage(int damage) {
		if (_health <= 0) {
			std::cout << "Enemy is already Dead\n";
			return;
		}
		_health = _health - damage;
	}
};

Enemy::Enemy(int health, int damage, Sizes size) {
	_health = health;
	_size = size;

	// Damage is based on the size of the enemy
	_damage = damage;
}

Enemy CreateRandomEnemy() {
	int randSize = rand() % Sizes::Count; // in the range 1 to enumSize

	int randHealth = rand() % MAX_HEALTH + 1; // in the range 1 to healthMax

	int randDamage = rand() % MAX_DAMAGE + 1; // in the range 1 to damageMax

	return Enemy(randHealth, randDamage, sizeIntToEnum(randSize));
}