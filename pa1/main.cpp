/**
 * @file main.cpp
 * A simple C++ program that manipulates an image.
 *
 * @author CS 221: Basic Algorithms and Data Structures
 **/

#include "grid.h"
#include "block.h"
#include <iostream>
#include "cs221util/PNG.h"
using namespace cs221util;
using namespace std;

int main() {
  PNG pngin,result,expected;
  pngin.readFromFile("images/rosegarden.png");
  result.readFromFile("images/rosegarden.png");

  //basic block functionality
  Block b(pngin,20,30,150,150);	// grab a 150x150 block at (20,30) in pngin
  b.greyscale();		// Change the block to grey
  b.render(result,20,30);	// Put the block in a new image at (20,30)
  result.writeToFile("images/out-main-blocktest.png");

  expected.readFromFile("images/given-blocktest-basic.png");
  if (expected == result) cout<< "blocktest-basic PASSED" << endl;
  else cout << "blocktest-basic FAILED" << endl;

  //grid rotateR
  Grid g1(pngin,4,5);	// image, number of columns, rows.
  g1.rotateR(3, 1);	// rotate row 3 by 1
  result = g1.render();
  result.writeToFile("images/out-main-rotateR.png");

  //grid rotateR1
  Grid gg(pngin,4,5);	// image, number of columns, rows.
  gg.rotateR(0, 2);	
  result = gg.render();
  result.writeToFile("images/out-main-rotateR1.png");

  expected.readFromFile("images/given-rotateR.png");
  if (expected == result) cout<< "gridtest-rotateR PASSED" << endl;
  else cout << "gridtest-rotateR FAILED" << endl;

  //grid rotateC
  Grid g2(pngin,4,5);	// image, number of columns, rows.
  g2.rotateC(1, 1);	// rotate column 1 by 1
  result = g2.render();
  result.writeToFile("images/out-main-rotateC.png");

  expected.readFromFile("images/given-rotateC.png");
  if (expected == result) cout<< "gridtest-rotateC PASSED" << endl;
  else cout << "gridtest-rotateC FAILED" << endl;

  //grid combined
   pngin.readFromFile("images/123456789.png");
  Grid g11(pngin,3,3);
  g11.rotateR(0, 2);
  g11.rotateC(2, 1);
  result = g11.render();
  result.writeToFile("images/out-test-puzzle.png");

  //grid copy
  Grid g3(pngin,4,5);
  Grid g3g3(g3);
  
  //grid puzzle
  pngin.readFromFile("images/123456789.png");
  Grid g(pngin,3,3);

  /* Define this macro in the file grid.h */
  PUZZLE_SOLUTION

  result = g.render();
  result.writeToFile("images/out-main-puzzle.png");

  expected.readFromFile("images/given-puzzle.png");
  if (expected == result) cout<< "puzzle PASSED" << endl;
  else cout << "puzzle FAILED" << endl;

  return 0;
}
