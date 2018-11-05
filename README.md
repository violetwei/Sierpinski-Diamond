# Sierpinski-Diamond
This is a program written in C that prints a modified diamond, 

such that each of the top and bottom half are Sierpiński Triangles.

This program should take two arguments: the height of the diamond, H, and the fractal level, L. 

Again, the diamond has a precise format:

• The level L=1 diamond must be identical to the simple diamond with the given height, H.

• For each level beyond 1, you must sub-divide top and bottom triangles using Sierpiński’s rule. 
  Replace a H/2 triangle whose tip touches the bottom of the original with spaces. 
  This leaves 3 triangles, each with height H/2 and level L-1, one above the missing triangle, and two beside it.
  
• We must continue recursively sub-dividing each remaining triangle until we reach level L=1.
