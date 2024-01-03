#pragma once
#include <iostream>
#include "Sizes.h"
#include "Enemy.h"
#include "Constants.h"

// Constructor
Enemy::Enemy(int health, int damage, Sizes size) {
	_health = health;
	_size = size;

	// Damage is based on the size of the enemy
	_damage = damage;
}

//Getters
int Enemy::GetCurrentHealth() {
	return _health;
}
int Enemy::GetDamage() {
	return _damage;
}
int Enemy::GetSize() {
	return _size;
}

void Enemy::TakeDamage(int damage) {
	if (_health <= 0) {
		std::cout << "Enemy is already Dead\n";
		return;
	}
	_health = _health - damage;
}

Enemy RandomEnemyFactory() {
	int randSize = rand() % Sizes::Count; // in the range 1 to enumSize

	int randHealth = rand() % MAX_HEALTH + 1; // in the range 1 to healthMax

	int randDamage = rand() % MAX_DAMAGE + 1; // in the range 1 to damageMax

	return Enemy(randHealth, randDamage, sizeIntToEnum(randSize));
}