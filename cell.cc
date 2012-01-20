/*
 * =====================================================================================
 *
 *       Filename:  cell.cc
 *
 *    Description:  Methods used by each cell in Conway's Game of Life 
 *
 *         Author:  Jeff Dyck
 *
 * =====================================================================================
 */

#include "cell.h"

/*
 * Cell constructor
 */
Cell::Cell () {  
   this->isAlive = false;
   this->numNeighbours = 0;
   this->numAlive = 0;
   for (int i=0; i<maxNeighbours; i++) {
      this->neighbours[i] = NULL;
   }
   this->pw = NULL;
}

/*
 * Cell destructor
 */
Cell::~Cell() {   
   // delete this->pw;     // NOT SURE IF NEEDED
}


/*
 * Sets the cell to living
 */
void Cell::setLiving() {
   this->isAlive = true;
   this->draw();
   return;
}

void Cell::setDead() {
   this->isAlive = false;
   this->undraw();
   return;
}

/*
 * Adds a pointer to one of the cell's neighbours to the array
 */
void Cell::addNeighbour(Cell *neighbour) {
   for (int i=0; i < maxNeighbours; i++) {
      if (this->neighbours[i] == NULL) {
         this->neighbours[i] = neighbour;
         this->numNeighbours += 1;
         return;
      }
   } // for

   return;
}

/*
 * If the cell is alive, tell all neighbours that the cell is alive
 */
void Cell::alertNeighbours() {   
   if (this->isAlive) {
      for (int i=0; i < this->numNeighbours; i++) {
            this->neighbours[i]->neighbourIsAlive();
      } 
   } // if

   return;
}


/*
 * Will be called by the cell's neighbours to tell it theyre alive
 */
void Cell::neighbourIsAlive() {  
   this->numAlive += 1;
   return;
}


/*
 * Reassess the cell's living-or-dead status based on the number of living neighbours
 */
void Cell::recalculate() { 
   if (this->isAlive) {    
      if (!(this->numAlive == 2 || this->numAlive == 3)) {
         this->isAlive = false;
         this->undraw();
      }
   } else {
      if (this->numAlive == 3) {
         this->isAlive = true;
         this->draw();
      }
   }

   // Resets numAlive so it can be recalculated next time
   this->numAlive = 0;  
   return;
}

/*
 * Sets the coordinates for the cell and gives a pointer to the window
 */
void Cell::setCoords(int X, int Y, int W, int H, Xwindow *PW) {
   this->x = X;
   this->y = Y;
   this->width = W;
   this->height = H;
   this->pw = PW;
}

/*
 * Draws the cell's box on the window depending on it's coordinates
 */

void Cell::draw() {
   (this->pw)->fillRectangle((this->x * this->width), (this->y * this->height), 
                              this->width, this->height);
   return;
}

/*
 * Removes the cell's box drawn on the window by drawing a white box
 */
void Cell::undraw() {
   (this->pw)->fillRectangle((this->x * this->width), (this->y * this->height), 
                              this->width, this->height, 0);
   return;
}



/*
 * Overloads the << operator
 * Prints X if the cell is alive, _ if it's dead
 */
std::ostream& operator<<(std::ostream &out, const Cell &c) {
   if (c.isAlive)   out << 'X';
   else out << '_';

   return out;
}

