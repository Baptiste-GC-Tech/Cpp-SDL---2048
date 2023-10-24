// Cpp--Console--2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <conio.h>
#include <string>

// Value of input
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 1

//Function move tile with keyboard
int main()
{
    char players = 0;
    std::cout << "Does a action";

    char key = _getch();
    int value = key;

    while (value != KEY_X)
    {
        switch (_getch())
        {
        case KEY_DOWN:
            std::cout << players << "KeyDown \n\n";
            break;
        case KEY_UP:
            std::cout << players << "KeyUp \n\n";
            break;
        case KEY_LEFT:
            std::cout << players << "KeyLeft \n\n";
            break;
        case KEY_RIGHT:
            std::cout << players << "KeyRight \n\n";
            break;
        }
        key = _getch();
        value = key;
    }
    return 0;
}
