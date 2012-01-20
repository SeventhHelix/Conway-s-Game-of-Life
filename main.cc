/*
 * =====================================================================================
 *
 *       Filename:  a4q3.cc
 *
 *    Description:  Runs Conway's Game of Life
 *                  Takes user input to create a grid of n cells and runs the simulation
 *                  with the grid. Adds a graphical display on top of Q1.
 *
 *         Author:  Jeff Dyck
 *
 * =====================================================================================
 */


#include <iostream>
#include "cell.h"
#include "grid.h"

using namespace std;

int main() {
   int n;
   int x = 0;
   int y = 0;
   string cmd;

   Grid *grd = new Grid();

   while (cin >> cmd) {

      if (cmd == "new") {
         cin >> n;
         grd->init(n);

      } else if (cmd == "init") {
         cin >> x >> y;
         while (x != -1 && y != -1) {
            grd->turnOn(x, y);   
            cin >> x >> y;
         }

      } else if (cmd == "print") {
         cout << *grd;

      } else if (cmd == "step" ) {
         grd->tick();

      } else if (cmd == "steps") {
         cin >> n;
         for (int i=0; i < n; i++) {
            grd->tick();
         }

      } else if (cmd == "random") {
         cin >> n;
         grd->randomCells(n);

      } else if (cmd == "auto" ) {
         cin >> n;
         grd->autoTick(n);

      } else {
         cout << "Unrecognized command" << endl;
      }

   }  //while

   delete grd; 
   
   return 0;
}
