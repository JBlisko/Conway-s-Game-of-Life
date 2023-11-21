// Author: Jonathan M. Blisko
// Date: Started Nov. 08, 2023 - Finished **
// MIT License


/*
Ideas:
 - Input random values
 - Use boltzmann distribution/random chance for reproduction
 - Use the logistic map to see if chaos can present itself
 - Create a way for shapes to interact with rigid/moveable boundaries
 - Quantify thermodynamic values (entropy, enthalpy, gibbs, pressure, etc.), is there an equivalent to an equation of state that can be deduced?
 - Implement ML
 - Add different species
 - Make in 3D
 - Place on toroids, sphere, Mobius strip, etc. by gluing the edges together with a periodic boundary condition
*/


// Headers
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm> // Remove when calcState is finished
#include "calcState.h"
#include "drawGrid.h"


// Global constants
const int GRIDSIZE = 20; // Best to use odd values for a symmetric grid
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
bool checkInt(std::string input);
bool checkValid(int x, int y);
bool checkDead(std::vector<int> X, std::vector<int> Y); // Function to check if all cells are dead. Just input the vectors and see if they are empty.
void test(int input, bool check); // Used for testing


int main(void)
{
    //int in = 3;
    //bool in2 = 1;
    //test(in, in2);
    //system("pause");

    static int x, y;
    std::vector<int> X, Y;
    std::string input;
    class cellType type;

    std::cout << "\n\n ~~~~~~~~~~~~~~~ John Conway's 'Game of Life' ~~~~~~~~~~~~~~~\n\n";
    std::cout << "This is an introdctory c++ implementation of John Conway's 'Game of Life' in 2D.";
    std::cout << std::endl << std::endl;

    std::cout << "This is a simple demonstration of cellular automata. The grid consists of alive and dead cells which abide by the following rules:\n\n";

    std::cout << "   - Rule 1: Any live cell with fewer than two live neighbours dies, as if by underpopulation.\n";
    std::cout << "   - Rule 2: Any live cell with two or three live neighbours lives on to the next generation.\n";
    std::cout << "   - Rule 3: Any live cell with more than three live neighbours dies, as if by overpopulation.\n";
    std::cout << "   - Rule 4: Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.\n\n";

    std::cout << "This example is printed with a grid size of " << GRIDSIZE << " ranging from " << BOUND - GRIDSIZE << " to " << BOUND << ", but in principle the grid should be of infinite size.";
    std::cout << std::endl;

Input:
    std::cout << "Input the number of starting coordinates or 'f' to use input file:";
    std::cout << std::endl;
    
    std::cin >> input;
    
    if (checkInt(input))
    {
        int i = 0;
        bool check = true;
        while (check)
        {
            std::cout << "Input integer coordinates for grid point number " << i + 1 << " (in the format x y):" << std::endl;

            if (!(std::cin >> x >> y) || !checkValid(x, y))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR: Enter valid input." << std::endl;
                system("pause");
            }
            else
            {
                int dup = 0;

                for (int j = 0; j < std::min(X.size(), Y.size()); j++)
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
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "ERROR: Coordinate already used, please input new unique value." << std::endl;
                    system("pause");
                }
            }

            if (i == stoi(input))
                check = false;
        }
    }
    else if (input == "f")
    {
        std::cout << 2;
    }
    else
    {
        std::cout << "\nERROR: Please give a valid input.\n\n";

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
    calcState(X, Y);
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


bool checkInt(std::string str) {
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


bool checkDead(std::vector<int> X, std::vector<int> Y)
{
    if (X.size() == 0 || Y.size() == 0)
        return true;
    return false;
}


void test(int input, bool check)
{
    if (!check)
        std::cout << "Not check\n";
    if (check)
        std::cout << "Check\n";

    for (int i = 0; i < input + 1; i++)
    {
        switch (i) {
        case 0:
            std::cout << i << std::endl;
            break;

        case 1:
            std::cout << i << std::endl;
            break;

        case 2:
            std::cout << i << std::endl;
            break;

        case 3:
            std::cout << i << std::endl;
            break;
        }

        std::cout << "New line" << std::endl;
    }
}