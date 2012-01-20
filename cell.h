#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "window.h"

const int maxNeighbours = 8;

class Cell {
   bool isAlive;
   int numNeighbours;
   Cell *neighbours[maxNeighbours];
   int x, y, width, height;
   Xwindow *pw;

   // Add other private members if necessary
   int numAlive;                 // Keeps track of the number of alive neighbours

   public:
      Cell();                    // Default constructor
      ~Cell();                   // Destructor

      void setLiving();          // Explicitly sets me to living.
      void setDead();            // Explicitly sets me to dead

      void addNeighbour(Cell *neighbour); // Adds a pointer to one of my
                                          // neighbours to my array.

      void neighbourIsAlive();   // My neighbours will call this, to let me know
                                 // they're alive.

      void alertNeighbours();    // Tell all of my neighbours that I am alive
                                 // (if I'm alive).

      void recalculate();        // Reassess my living-or-dead status, based on
                                 // info from neighbours.

      void setCoords(int X, int Y, int W, int H, Xwindow *PW);

      void draw();               // Draws the cell on the grid window
      void undraw();             // Undraws the cell on the grid window

      friend std::ostream& ::operator<<(std::ostream &out, const Cell &c);
};

#endif
