# Conway's Game of Life
This repo gives a C++ implementation of John H. Conway's 'Game of Life', which is a very basic model of cellular automata. These are discrete models for the propogation of information through the creation and annihilation of cells.

This solution utilizes vectors $v_x$ and $v_y$ containing the coordinates of all alive cells, drastically reducing the memory needed for allocation. Although the grid frame is fixed, the use of vectors allow for a grid size on the bounds $v\in(-1,073,741,823, 1,073,741,823)$
