#pragma once
#include "Sizes.h"

class Enemy
{
	int _health;
	int _damage;
	Sizes _size;

public:
	Enemy(int health, Sizes size);
};

Enemy::Enemy(int health, Sizes size) {
	_health = health;
	_size = size;
}