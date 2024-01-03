#pragma once
#include "Sizes.h"

class Enemy {
	private:
		int _health = 100;
		int _damage = 1;
		Sizes _size = Sizes::Small;

	public:
		//Constructor
		Enemy(int health, int damage, Sizes size);

		//Getters
		int GetCurrentHealth();

		int GetDamage();

		int GetSize();

		//Methods
		void TakeDamage(int damage);
};

Enemy RandomEnemyFactory();