#include <iostream>
#include <chrono>
#include <thread>
#include <limits>
#include <vector>
#include <random>

#include "Constants.h"
#include "Character.h"
#include "Enemy.h"
#include "Sizes.h"

#define Log(x) std::cout << x << std::endl;

bool ValidEnemyClamp(int value)
{
    if (value < MIN_ENEMIES) {
        Log("Want a easy life hu? Try a real thing!\n");
        return false;
    }
    else if (value > MAX_ENEMIES) {
        Log("I Don't think you can handle that many, your just starting. Try a more realistic number!\n");
        return false;
    }
    else return true;
}

Enemy CreateRandomEnemy() {
    int randSize = rand() % Sizes::Count; // in the range 1 to enumSize

    int randHealth = rand() % MAX_HEALTH + 1; // in the range 1 to healthMax

    int randDamage = rand() % MAX_DAMAGE + 1; // in the range 1 to damageMax

    if (randSize == 0) {
        return Enemy(randHealth, randDamage, Sizes::Small);
    }
    if (randSize == 1) {
        return Enemy(randHealth, randDamage, Sizes::Medium);
    }
    if (randSize == 2) {
        return Enemy(randHealth, randDamage, Sizes::Large);
    }
}

std::vector<Enemy> CreateEnemies(int numberOfEnemies) {

    std::vector<Enemy> enemies = std::vector<Enemy>();

    for (int i = 0; i < numberOfEnemies; i++) {
        enemies.push_back(CreateRandomEnemy());
        /*std::cout << "Enemy " << i << ": " << enemies[i].GetCurrentHealth()
            << " Health and " << enemies[i].GetDamage() 
            << " Damage (" << sizeEnumToStr(enemies[i].GetSize())  << " Size)\n";
        */
    }

    return enemies;
}

// Return true if you have won the battle, false if you have died.
bool Battle(Character& character, Enemy& enemy) {
    // Early Exit in case of battling without HP
    if (character.GetCurrentHealth() <= 0) {
        Log("Oh dear you died");
        return false;
    }

    // While the enemy still has HP
    while (enemy.GetCurrentHealth() > 0) {
        
        // Player Attacks First
        enemy.TakeDamage(character.GetDamage());

        //Enemy Survived, then he attacks
        if (enemy.GetCurrentHealth() > 0) {
            character.TakeDamage(enemy.GetDamage());

            // If you died, return false
            if (character.GetCurrentHealth() <= 0) {
                Log("Oh dear you died");
                return false;
            }
        }
    }
    
    // Successful combat, you won against this foe
    return true;
}

int main()
{
    // Flavour Text
    Log("JOUA'S Dungeon Crawler\n\n");
    Log("Whats's your name?\n");

    // Creates new Character with Name and Damage
    std::string name;
    std::cin >> name;
    Character player = Character(name, 20);

    // Get the number of Enemies, clamped by MIN and MAX (see Constants.h)
    bool validInput = false;
    int numberOfEnemies;
    while (!validInput) {
        Log( "\nHow many enemies you think you can fight?\n");
        std::cin >> numberOfEnemies;

        if (ValidEnemyClamp(numberOfEnemies)) {
            validInput = true;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Allocate the Enemies
    std::vector<Enemy> enemies = CreateEnemies(numberOfEnemies);

    // Array representing how many enemies have been defeated
    int enemiesDefeated[3] = {
        0,  // index 0 = Small enemies
        0,  // index 1 = Medium enemies
        0,  // index 2 = Large enemies
    };

    // Battle each of them.
    bool victory = true;
    for (int i = 0; i < enemies.size(); i++) {
        if (player.GetCurrentHealth() <= 0) {
            // Early exit if you have died
            victory = false;
            break;
        }

        bool playerWon = Battle(player, enemies[i]);
        if (playerWon) {
            enemiesDefeated[enemies[i].GetSize()] ++;
        }
    }

    // Log the Results
    if (victory) {
        Log("Victory against " << numberOfEnemies << " Enemies!");
    }

    Log("Enemies Slain: ");
    for (int i = 0; i < Sizes::Count; i++) {
       Log(sizeEnumToStr(i) << ": " << enemiesDefeated[i]);
    };
}

