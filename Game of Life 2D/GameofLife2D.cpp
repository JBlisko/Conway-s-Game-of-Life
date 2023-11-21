// Author: Jonathan M. Blisko
// Date: Started Nov. 08, 2023 - Finished **
// MIT License


// Standard headers
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm> // Remove when calcState is finished
//#include <sstream>
//#include <cstdlib>

// User-defined headers
#include "calcState.h"
#include "drawGrid.h"

// Standard Namespace
using namespace std;

// Global constants
const int GRIDSIZE = 10; // Best to use odd values for a symmetric grid
const int BOUND = floor(GRIDSIZE / 2);

// User defined types
class cellType
{
public:
    int val;

private:
    char type;
    void initType() {
        switch (val) {
        case 1:
            type = 'D';
            break;
        case 2:
            type = 'A';
            break;
        default:
            type = 'D';
            break;
        }
    }
};


// Functions
bool checkInt(string input);
bool checkValid(int x, int y);
bool checkDead(vector<int> X, vector<int> Y); // Function to check if all cells are dead. Just input the vectors and see if they are empty.
void test(int input, bool check); // Used for testing


int main(void)
{
    //int in = 3;
    //bool in2 = 1;
    //test(in, in2);
    //system("pause");

    static int x, y;
    vector<int> X, Y;
    //static bool oldState[GRIDSIZE + 1][GRIDSIZE + 1] = {};
    //static bool newState[GRIDSIZE + 1][GRIDSIZE + 1] = {};
    //bool** oldState = new bool* [GRIDSIZE + 1];
    //bool** newState = new bool* [GRIDSIZE + 1];
    string input;
    class cellType type;

    cout << "\n\n ~~~~~~~~~~~~~~~ John Conway's 'Game of Life' ~~~~~~~~~~~~~~~\n\n";
    cout << "This is an introdctory c++ implementation of John Conway's 'Game of Life' in 2D.";
    cout << endl << endl;

    cout << "This is a simple demonstration of cellular automata. The grid consists of alive and dead cells which abide by the following rules:\n\n";

    cout << "   - Rule 1: Any live cell with fewer than two live neighbours dies, as if by underpopulation.\n";
    cout << "   - Rule 2: Any live cell with two or three live neighbours lives on to the next generation.\n";
    cout << "   - Rule 3: Any live cell with more than three live neighbours dies, as if by overpopulation.\n";
    cout << "   - Rule 4: Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.\n\n";

    cout << "This example is printed with a grid size of " << GRIDSIZE << " ranging from " << -GRIDSIZE / 2 << " to " << GRIDSIZE / 2 << ", but in principle the grid should be of infinite size.";
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

            if (!(cin >> x >> y) || !checkValid(x, y))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "ERROR: Enter valid input." << endl;
                system("pause");
            }
            else
            {
                int dup = 0;

                for (int j = 0; j < min(X.size(), Y.size()); j++)
                {
                    if (X[j] == x && Y[j] == y) {
                        dup++;
                    }
                }

                if (!dup)
                {
                    X.push_back(x);
                    Y.push_back(y);
                    i++;
                }
                else
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "ERROR: Coordinate already used, please input new unique value." << endl;
                    system("pause");
                }
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

    drawGrid(X, Y, GRIDSIZE);
    system("pause");
    calcState(X, Y);
    drawGrid(X, Y, GRIDSIZE);
    system("pause");
    calcState(X, Y);
    drawGrid(X, Y, GRIDSIZE);
    system("pause");

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
    if ((abs(x) > BOUND + 1) || (abs(y) > BOUND + 1))
        return false;
    return true;
}


bool checkDead(vector<int> X, vector<int> Y)
{
    if (X.size() == 0 || Y.size() == 0)
        return true;
    return false;
}


void test(int input, bool check)
{
    if (!check)
        cout << "Not check\n";
    if (check)
        cout << "Check\n";

    for (int i = 0; i < input + 1; i++)
    {
        switch (i) {
        case 0:
            cout << i << endl;
            break;

        case 1:
            cout << i << endl;
            break;

        case 2:
            cout << i << endl;
            break;

        case 3:
            cout << i << endl;
            break;
        }

        cout << "New line" << endl;
    }
}