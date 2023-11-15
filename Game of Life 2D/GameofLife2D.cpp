// Author: Jonathan M. Blisko
// Date: Nov. 08, 2023

#include <iostream>
#include <fstream>
//#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

// Classes
struct cellType
{
    int val;
};

// Constants
const int gridSize = 100;

// Functions
bool checkInt(string input);
bool checkValid(int x, int y);
void calcState(bool oldState[gridSize + 1][gridSize + 1], bool newState[gridSize + 1][gridSize + 1], int gS);

int main()
{
    static int x, y;
    int bound = floor(gridSize / 2);
    static bool oldState[gridSize + 1][gridSize + 1] = {};
    static bool newState[gridSize + 1][gridSize + 1] = {};
    string input;

    cout << "\n\n ~~~~~~~~~~~~~~~ John Conway's 'Game of Life' ~~~~~~~~~~~~~~~\n\n";
    cout << "This is an introdctory c++ implementation of John Conway's 'Game of Life' in 2D.";
    cout << endl << endl;

    cout << "This is a simple demonstration of cellular automata. The grid consists of alive and dead cells which abide by the following rules:\n\n";

    cout << "   - Rule 1: Any live cell with fewer than two live neighbours dies, as if by underpopulation.\n";
    cout << "   - Rule 2: Any live cell with two or three live neighbours lives on to the next generation.\n";
    cout << "   - Rule 3: Any live cell with more than three live neighbours dies, as if by overpopulation.\n";
    cout << "   - Rule 4: Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.\n\n";

    cout << "This example is printed with a grid size of " << gridSize << " ranging from " << -gridSize / 2 << " to " << gridSize / 2 << ", but in principle the grid should be of infinite size.";
    cout << endl;

Input:
    cout << "Input the number of starting coordinates or 'f' to use input file:";
    cout << endl;

    cin >> input;
    
    if (checkInt(input))
    {
        int i = 0;
        bool check = true;
        while (check)
        {
            cout << "Input integer coordinates for grid point number " << i + 1 << " (in the format x y):" << endl;
            
            if(!(cin >> x >> y) || !checkValid(x,y))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "ERROR: Enter valid input." << endl;
                system("pause");
            }
            else
            {
                oldState[x + bound][y + bound] = 1;
                i++;
            }
            if (i == stoi(input))
                check = false;
        }

        
    }
    else if (input == "f")
    {
        cout << 2;
    }
    else
    {
        cout << "\nERROR: Please give a valid input.\n\n";

        goto Input;
    }

    return(0);
}


bool checkInt(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}


bool checkValid(int x, int y)
{
    if ((x > gridSize + 1) || (y > gridSize + 1))
        return false;
    return true;
}


void calcState(bool oldState[gridSize + 1][gridSize + 1], bool newState[gridSize + 1][gridSize + 1], int gS)
{
    for (int i = 0; i < gS; i++)
    {
        n++;
    }
    printf("%d", n);
    return;
}
