Conway's Game of Life
=====================

A graphical implementation of Conway's Game of Life, using X. 

How to play
-----------
Commands:
      
new n    -     Creates a new nxn grid and opens a 500x500px window

init     -     Enters initialization mode. Takes sets of two numbers x and y and turns that cell on. The init mode ends when -1 -1 is read.
Ex: init 0 0 1 1 2 2 -1 -1
Turns on cells (0,0) (1,1) (2,2) and exits initialization mode

print    -     Prints the current grid in the terminal window

step     -     Runs one tick of the grid and updates the window


steps n  -     Runs n ticks of the graphical window

random n -     Randomly turns n% of the grid on and (100-n)% off

auto n   -     Automatically steps every n milliseconds (Will run infinitely. Only way to stop is to Ctrl-c or end the process)

Compiling and running
---------------------

To compile and run: 
      <blockquote>
      <p>$ make</p>
      <p>$ ./life-graphical</p>
      <p></blockquote>

Common running procedure:
      <blockquote>
      <p>./life-graphical</p>
         <p>new x</p>
         <p>random y</p>
         <p>auto z</p>
      </blockquote>


Notes
-----

This program leaks memory due to the implementation of the Xwindow class.
