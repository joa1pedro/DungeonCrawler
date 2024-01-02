#include <iostream>
#include <chrono>
#include <thread>
#include <limits>
#include "Character.h"
#include "Enemy.h"

#define Log(x) std::cout << x << std::endl;


bool ValidClamp(int value)
{
    int minNumberOfEnemies = 1;
    int maxNumberOfEnemies = 99;

    if (value < minNumberOfEnemies) {
        Log("Want a easy life hu? Try a real thing!\n");
        return false;
    }
    else if (value > maxNumberOfEnemies) {
        Log("I Don't think you can handle that many, your just starting. Try a more realistic number!\n");
        return false;
    }
    else return true;
}

int main()
{
    std::string name;
    char anyOption;
    int numberOfEnemies;

    // Flavour Text
    Log("JOUA'S Dungeon Crawler\n\n");
    Log("Whats's your name?\n");

    // Creates new Character
    std::cin >> name;
    Character player = Character(name);
    std::cout << "Are you ready for your Journey " << player.GetName() << "? S/N\n";

    // Waits 3 seconds if player selects something different than S or s
    std::cin >> anyOption;
    if ((anyOption != 's') && (anyOption != 'S')) {
        Log( "\nDoes not matter if you are ready or not...\n");
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
   
    bool validInput = false;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (!validInput) {
        Log( "How many enemies are you fighting?\n");
        std::cin >> numberOfEnemies;

        if (ValidClamp(numberOfEnemies)) {
            validInput = true;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    Log( "That should be good\n");
    return;
}

