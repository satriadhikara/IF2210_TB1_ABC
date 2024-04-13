#include "./classes/Main.hpp"
#include <iostream>
using namespace std;

int main()
{
    Main game;
    while (game.getIsRunning())
    {
        try
        {
            cout << "> ";
            string command;
            cin >> command;
            game.runCommand(command);
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }
    return 0;
}
