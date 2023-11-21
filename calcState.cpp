// Author: Jonathan M. Blisko
// Date: Started Nov. 15, 2023 - Finished **

/*
Description:
   Function file used to update new state. Input requires the vectors which hold the information
   for alive cells. This allows for complexity to only grow O(N), where N = max(X.size,Y.size),
   instead of O(GRIDSIZE^2). This is much faster and allows for a much larger grid (potentially
   infinite).

   Add section which finds the total size of grid needed to hold alive cell information and mods
   out vectors X and Y by this value to minimize the integer stored within these vectors. For
   example, if min(X,Y) = 1000 and max(X,Y) = 1100, then we only need to have a grid size of 100
   to fully describe the alive cell arrangement.

   Maybe a better idea to the above is to find what is equivalent to the 'center of mass' of all
   alive cells, and recenter (0,0) to that point.
*/

// Headers
#include <iostream>
#include <vector>
#include <algorithm>
#include "calcState.h"


// Functions
void findNeigh(std::vector<int> X, std::vector<int> Y, int i, bool& E, bool& NE, bool& N, bool& NW, bool& W, bool& SW, bool& S, bool& SE,
    bool& EE, bool& NEE, bool& NENE, bool& NEN, bool& NN, bool& NWN, bool& NWNW, bool& NWW, bool& WW, bool& SWW, bool& SWSW,
    bool& SWS, bool& SS, bool& SES, bool& SESE, bool& SEE);
void vecCheck(std::vector<int> X, std::vector<int> Y, int x, int y, bool& contained);

void calcState(std::vector<int>& X, std::vector<int>& Y)
{
    std::vector<int> tempX, tempY;
    bool E, NE, N, NW, W, SW, S, SE, EE, NEE, NENE, NEN, NN, NWN, NWNW, NWW, WW, SWW, SWSW, SWS, SS, SES, SESE, SEE;
    int neigh;
    int birth;
    bool containedTemp;
    bool containedCurr;

    // Iterate through all values (X,Y)
    for (int i = 0; i < std::min(X.size(), Y.size()); i++) {
        neigh = 0;

        E = 0, NE = 0, N = 0, NW = 0, W = 0, SW = 0, S = 0, SE = 0, EE = 0, NEE = 0, NENE = 0, NEN = 0,
            NN = 0, NWN = 0, NWNW = 0, NWW = 0, WW = 0, SWW = 0, SWSW = 0, SWS = 0, SS = 0, SES = 0, SESE = 0, SEE = 0;

        findNeigh(X, Y, i, E, NE, N, NW, W, SW, S, SE, EE, NEE, NENE, NEN, NN, NWN, NWNW, NWW, WW, SWW, SWSW, SWS, SS, SES, SESE, SEE);

        if (E) neigh++;
        if (NE) neigh++;
        if (N) neigh++;
        if (NW) neigh++;
        if (W) neigh++;
        if (SW) neigh++;
        if (S) neigh++;
        if (SE) neigh++;

        if (neigh == 2 || neigh == 3) {
            tempX.push_back(X[i]);
            tempY.push_back(Y[i]);
        }

        for (int j = 1; j < 9; j++) {
            birth = 1; // We start at 1 since we know that every cell checked will have at least one neighboring live cell
            containedTemp = 0;
            containedCurr = 0;

            switch (j) {
            case 1:
                vecCheck(tempX, tempY, X[i] + 1, Y[i], containedTemp);
                vecCheck(X, Y, X[i] + 1, Y[i], containedCurr);

                if (!containedTemp && !containedCurr)
                {
                    if (NE) birth++;
                    if (N) birth++;
                    if (S) birth++;
                    if (SE) birth++;
                    if (EE) birth++;
                    if (NEE) birth++;
                    if (SEE) birth++;
                    if (birth == 3) {
                        tempX.push_back(X[i] + 1);
                        tempY.push_back(Y[i]);
                    }
                }
                
                break;

            case 2:
                vecCheck(tempX, tempY, X[i] + 1, Y[i] + 1, containedTemp);
                vecCheck(X, Y, X[i] + 1, Y[i] + 1, containedCurr);

                if (!containedTemp && !containedCurr)
                {
                    if (E) birth++;
                    if (N) birth++;
                    if (EE) birth++;
                    if (NEE) birth++;
                    if (NENE) birth++;
                    if (NEN) birth++;
                    if (NN) birth++;
                    if (birth == 3) {
                        tempX.push_back(X[i] + 1);
                        tempY.push_back(Y[i] + 1);
                    }
                }
                
                break;

            case 3:
                vecCheck(tempX, tempY, X[i], Y[i] + 1, containedTemp);
                vecCheck(X, Y, X[i], Y[i] + 1, containedCurr);

                if (!containedTemp && !containedCurr)
                {
                    if (E) birth++;
                    if (NE) birth++;
                    if (NW) birth++;
                    if (W) birth++;
                    if (NEN) birth++;
                    if (NN) birth++;
                    if (NWN) birth++;
                    if (birth == 3) {
                        tempX.push_back(X[i]);
                        tempY.push_back(Y[i] + 1);
                    }
                }
                
                break;

            case 4:
                vecCheck(tempX, tempY, X[i] - 1, Y[i] + 1, containedTemp);
                vecCheck(X, Y, X[i] - 1, Y[i] + 1, containedCurr);
                
                if (!containedTemp && !containedCurr)
                {
                    if (N) birth++;
                    if (W) birth++;
                    if (NN) birth++;
                    if (NWN) birth++;
                    if (NWNW) birth++;
                    if (NWW) birth++;
                    if (WW) birth++;
                    if (birth == 3) {
                        tempX.push_back(X[i] - 1);
                        tempY.push_back(Y[i] + 1);
                    }
                }
                
                break;

            case 5:
                vecCheck(tempX, tempY, X[i] - 1, Y[i], containedTemp);
                vecCheck(X, Y, X[i] - 1, Y[i], containedCurr);

                if (!containedTemp && !containedCurr)
                {
                    if (N) birth++;
                    if (NW) birth++;
                    if (SW) birth++;
                    if (S) birth++;
                    if (NWW) birth++;
                    if (WW) birth++;
                    if (SWW) birth++;
                    if (birth == 3) {
                        tempX.push_back(X[i] - 1);
                        tempY.push_back(Y[i]);
                    }
                }
                
                break;

            case 6:
                vecCheck(tempX, tempY, X[i] - 1, Y[i] - 1, containedTemp);
                vecCheck(X, Y, X[i] - 1, Y[i] - 1, containedCurr);
                
                if (!containedTemp && !containedCurr)
                {
                    if (W) birth++;
                    if (S) birth++;
                    if (WW) birth++;
                    if (SWW) birth++;
                    if (SWSW) birth++;
                    if (SWS) birth++;
                    if (SS) birth++;
                    if (birth == 3) {
                        tempX.push_back(X[i] - 1);
                        tempY.push_back(Y[i] - 1);
                    }
                }
                
                break;

            case 7:
                vecCheck(tempX, tempY, X[i], Y[i] - 1, containedTemp);
                vecCheck(X, Y, X[i], Y[i] - 1, containedCurr);
                
                if (!containedTemp && !containedCurr)
                {
                    if (W) birth++;
                    if (SW) birth++;
                    if (SE) birth++;
                    if (E) birth++;
                    if (SWS) birth++;
                    if (SS) birth++;
                    if (SES) birth++;
                    if (birth == 3) {
                        tempX.push_back(X[i]);
                        tempY.push_back(Y[i] - 1);
                    }
                }
                
                break;

            case 8:
                vecCheck(tempX, tempY, X[i] + 1, Y[i] - 1, containedTemp);
                vecCheck(X, Y, X[i] + 1, Y[i] - 1, containedCurr);
                
                if (!containedTemp && !containedCurr)
                {
                    if (E) birth++;
                    if (S) birth++;
                    if (EE) birth++;
                    if (SS) birth++;
                    if (SES) birth++;
                    if (SESE) birth++;
                    if (SEE) birth++;
                    if (birth == 3) {
                        tempX.push_back(X[i] + 1);
                        tempY.push_back(Y[i] - 1);
                    }
                }

                break;
            }
        }
    }

    // Clear and reassign values to vectors X and Y
    X.clear();
    Y.clear();
    X = tempX;
    Y = tempY;

    return;
}


void findNeigh(std::vector<int> X, std::vector<int> Y, int i, bool& E, bool& NE, bool& N, bool& NW, bool& W, bool& SW, bool& S, bool& SE,
    bool& EE, bool& NEE, bool& NENE, bool& NEN, bool& NN, bool& NWN, bool& NWNW, bool& NWW, bool& WW, bool& SWW, bool& SWSW,
    bool& SWS, bool& SS, bool& SES, bool& SESE, bool& SEE)
{
    for (int n = 0; n < std::min(X.size(), Y.size()); n++)
    {
        if (X[n] == X[i] + 1 && Y[n] == Y[i]) E = 1;
        else if (X[n] == X[i] + 1 && Y[n] == Y[i] + 1) NE = 1;
        else if (X[n] == X[i] && Y[n] == Y[i] + 1) N = 1;
        else if (X[n] == X[i] - 1 && Y[n] == Y[i] + 1) NW = 1;
        else if (X[n] == X[i] - 1 && Y[n] == Y[i]) W = 1;
        else if (X[n] == X[i] - 1 && Y[n] == Y[i] - 1) SW = 1;
        else if (X[n] == X[i] && Y[n] == Y[i] - 1) S = 1;
        else if (X[n] == X[i] + 1 && Y[n] == Y[i] - 1) SE = 1;
        else if (X[n] == X[i] + 2 && Y[n] == Y[i]) EE = 1;
        else if (X[n] == X[i] + 2 && Y[n] == Y[i] + 1) NEE = 1;
        else if (X[n] == X[i] + 2 && Y[n] == Y[i] + 2) NENE = 1;
        else if (X[n] == X[i] + 1 && Y[n] == Y[i] + 2) NEN = 1;
        else if (X[n] == X[i] && Y[n] == Y[i] + 2) NN = 1;
        else if (X[n] == X[i] - 1 && Y[n] == Y[i] + 2) NWN = 1;
        else if (X[n] == X[i] - 2 && Y[n] == Y[i] + 2) NWNW = 1;
        else if (X[n] == X[i] - 2 && Y[n] == Y[i] + 1) NWW = 1;
        else if (X[n] == X[i] - 2 && Y[n] == Y[i]) WW = 1;
        else if (X[n] == X[i] - 2 && Y[n] == Y[i] - 1) SWW = 1;
        else if (X[n] == X[i] - 2 && Y[n] == Y[i] - 2) SWSW = 1;
        else if (X[n] == X[i] - 1 && Y[n] == Y[i] - 2) SWS = 1;
        else if (X[n] == X[i] && Y[n] == Y[i] - 2) SS = 1;
        else if (X[n] == X[i] + 1 && Y[n] == Y[i] - 2) SES = 1;
        else if (X[n] == X[i] + 2 && Y[n] == Y[i] - 2) SESE = 1;
        else if (X[n] == X[i] + 2 && Y[n] == Y[i] - 1) SEE = 1;
    }
}


void vecCheck(std::vector<int> X, std::vector<int> Y, int x, int y, bool& contained) {
    for (int i = 0; i < std::min(X.size(), Y.size()); i++)
    {
        if (X[i] == x && Y[i] == y) {
            contained = 1;
            break;
        }
    }
}
