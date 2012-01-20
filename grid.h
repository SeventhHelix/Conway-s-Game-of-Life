#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include "cell.h"
#include "window.h"

class Grid {
  Cell **theGrid;  // The actual grid.
  int gridSize;    // Size of the grid.
  Xwindow *pw;      // Pointer to the window

  void clearGrid();   // Frees the grid.

 public:
  Grid();
  ~Grid();

  void init(int n); // Sets up an n x n grid.  Clears old grid, if necessary.
                    // Initializes every cell in the grid, and tells each
                    // cell who its neighbours are.

  void tick();      // Runs one iteration of the simulation.
                    // Tells each cell to alert its neighbours, and then
                    // tells each cell to recalculate.

  void turnOn(int i, int j);  // Sets cell at i, j to living.

  void randomCells(int percentAlive);   // Randomly sets cells to living

  void autoTick(int n); // Automatically steps, waiting n milliseconds in between

  friend std::ostream& ::operator<<(std::ostream &out, const Grid &g);
};

#endif
