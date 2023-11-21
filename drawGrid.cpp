// Author: Jonathan M. Blisko
// Updates: Started Nov. 17, 2023

/*
Description:
   This function file prints the current grid state. This is done using only the vectors which hold the
   information of alive cells. If the grid prints empty then either every cell is dead or the alive cells
   are outside of the gridsize. Update the global constant GRIDSIZE to enlarge the grid.
*/

// Headers
#include <cstdio>
#include <vector>
#include <algorithm>
#include "drawGrid.h"

void drawGrid(std::vector<int> X, std::vector<int> Y, int gS)
{
    int ubound = floor(gS / 2);
    int lbound = ubound - gS;
    int print;

    for (int i = ubound; i > lbound; i--)
    {
        for (int j = lbound; j < ubound; j++)
        {
            // This part can be optimized better, currently it is doing twice what it needs to. Possibly 2D vector array containing the pairs (X,Y).
            if (find(X.begin(), X.end(), j) != X.end() && find(Y.begin(), Y.end(), i) != Y.end())
            {
                print = 0;

                for (int k = 0; k < std::min(X.size(), Y.size()); k++)
                {
                    if (X[k] == j && Y[k] == i) {
                        printf(" x ");
                        print++;
                    }
                }

                if (!print)
                    printf(" . ");
            }
            else
                printf(" . ");
        }
        printf("\n");
    }
}
