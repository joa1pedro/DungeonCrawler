#include <iostream>
#include <chrono>
#include <thread>
#include <limits>

using namespace std;

bool ValidClamp(int value)
{
    int minNumberOfEnemies = 1;
    int maxNumberOfEnemies = 99;

    if (value < minNumberOfEnemies) {
        cout << "Want a easy life hu? Try a real thing!\n";
        return false;
    }
    else if (value > maxNumberOfEnemies) {
        cout << "I Don't think you can handle that many, your just starting. Try a more realistic number!\n";
        return false;
    }
    else return true;   
}

int main()
{
    string name;
    char whatever;
    int numberOfEnemies;


    // Main Story Line
    cout << "JOUA'S DUNGEON\n";
    cout << "\n";

    cout << "Whats's your name?\n";
    cin >> name;

    cout << "Are you ready for your Journey? S/N\n";
    cin >> whatever;

    if ((whatever != 's') && (whatever != 'S')) {
        cout << "\nDoes not matter if you are ready or not...\n";
        this_thread::sleep_for(chrono::seconds(3));
    }
        
    bool validInput = false;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (!validInput) {
        cout << "How many enemies are you fighting?\n";
        cin >> numberOfEnemies;

        if (ValidClamp(numberOfEnemies)) {
            validInput = true;
        }
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    cout << "That should be good\n";
    
}

