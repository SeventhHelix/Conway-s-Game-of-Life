/*
 * =====================================================================================
 *
 *       Filename:  grid.cc
 *
 *    Description:  Methods for a grid of cells in Conway's Game of Life
 *
 *         Author:  Jeff Dyck
 *
 * =====================================================================================
 */

#include "grid.h"
#include "cell.h"
#include <unistd.h>  // Used for sleep
#include <ctime>     // Used for random numbers
#include <cstdlib>   // Used for random numbers


/*
 * Clears the entire grid
 * Deletes each cell, the grid array, then itself entirely
 */
void Grid::clearGrid() {
   for (int i=0; i < this->gridSize; i++) {
      delete[] this->theGrid[i];
   }

   delete[] this->theGrid;
   delete this->pw;
   return;
}

/*
 * Grid constructor
 */
   Grid::Grid() { 
      this->gridSize = 0;
      this->theGrid = new Cell*[0];
      return;
   }



/*
 * Grid destructor
 */
Grid::~Grid() {    
   this->clearGrid();
   delete this->pw;
   return;
}


/*
 * Sets up a new n x n grid, clearing the old grid.
 * Initializes each cell, then tells each cell who its neighbours are 
 */
void Grid::init(int n) {

   // Clears the previous grid to prepare for the new one
   this->clearGrid();

   // Creates the new window
   // Done here so that it only opens when 'new' is given in input
   this->pw = new Xwindow(500,500);

   // Sets up the new grid
   this->gridSize = n;
   this->theGrid = new Cell*[n];    
   for (int i=0; i<n; i++) {
      this->theGrid[i] = new Cell[n];
   }

   // Sets up each cell in the grid with the proper neighbours 
   for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {

         // Sets this cell's coordinates for the window
         this->theGrid[i][j].setCoords(i, j, 500/n, 500/n, pw);

         // Loops over each neighbour of the cell, skipping out-of-bounds cells
         for (int ii = std::max(0, i-1); ii <= std::min(i+1, n-1); ii++) {
            for (int jj = std::max(0, j-1); jj <= std::min(j+1, n-1); jj++) {
               if (ii != i || jj != j) {
                  // Sets the cell's neighbour
                  this->theGrid[i][j].addNeighbour(&(this->theGrid[ii][jj]));
               } // if

            }  // for jj 
         }     // for ii

      } // for j
   }    // for i

   return;
}


/*
 * Calls for each cell to alert their neighbours of their status
 * Then calls each cell to recalculate their own status
 */
void Grid::tick() {
   for (int i=0; i<this->gridSize; i++) {
      for (int j=0; j<this->gridSize; j++) {
         this->theGrid[i][j].alertNeighbours();
      }
   }

   for (int i=0; i<this->gridSize; i++) {
      for (int j=0; j<this->gridSize; j++) {
         this->theGrid[i][j].recalculate();
      }
   }

   return;
}


/*
 * Turns on the specified cell
 */
void Grid::turnOn(int i, int j) {
   this->theGrid[i][j].setLiving();
   return;
}

/*
 * Sets random cells to living status
 */
void Grid::randomCells(int percentAlive) {

   std::srand((unsigned)time(0));

   for (int i=0; i < (this->gridSize); i++) {
      for (int j=0; j < (this->gridSize); j++) {

         if (std::rand()%100 <= percentAlive) this->theGrid[i][j].setLiving();
         else  this->theGrid[i][j].setDead();

      } // for
   }   // for

}

/*
 * Prints the grid every n milliseconds
 */
void Grid::autoTick(int n) {
   while (true) {    // Would be better to set up some sort of check to stop once the grid is dead
      this->tick();
      usleep(n*1000);
   }
}


/*
 * Overloads the << operator
 * Prints out the grid by printing out each cell row by row
 */
std::ostream& operator<<(std::ostream &out, const Grid &g) {
   for (int i=0; i < (g.gridSize); i++) {
      for (int j=0; j < (g.gridSize); j++) {
         out << g.theGrid[j][i]; 
      }
      out << std::endl;
   } // for

   return out;
}

