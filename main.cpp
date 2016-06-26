/********************************************************************
*Vector Testing
*-Just some training so we can dev a few algorithms later,
* as I forgot how to work with these nifty things.
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "classes.h"
#include <cmath>

void outputTest();
void makeNewThings(int i, int x, int y, int dir);

//Create 10 ints. Is there a default value?
//If supplied, the 2nd arg sets the default value.
//Ints are zero if unsupplied. The default ctor is called
// when making a vector of classes.
std::vector<int> test(10,5);
//Non-specified size.
std::vector<int> test1;
std::vector<makeThings> classSet(1,makeThings(0,0,0,10, _UP));

int main()
{
  classSet.reserve(50);
    int newX = classSet[0].getX2Pos();
    int newY = classSet[0].getY2Pos();
    int newDirection = _DOWN;
    int lineLength = 10;

  srand(time(NULL));
  //Create and assign vals for new classes within the vector.
  for(unsigned int i = 1; i < 30; i++)
  {
    //Gen new direction randomly.
    newDirection = rand() % 4 + 1;

    //Create the new X2 and Y2 positions based on the new direction.
    if(abs(classSet[i-1].getDirection()-classSet[i].getDirection()) != 1) {
      switch(newDirection) {
        case _UP: {
          if((classSet[i-1].getY2Pos() + lineLength) < SCREEN_MAX_Y)
          {
            newY = classSet[i-1].getY2Pos() + lineLength;
            makeNewThings(i, classSet[i-1].getX2Pos(),newY,newDirection);
          } break;
        } ,,,f6
        case _DOWN: {
          if((classSet[i-1].getY2Pos() - lineLength) > SCREEN_MIN_Y)
          {
            newY = classSet[i-1].getY2Pos() - lineLength;
            makeNewThings(i, classSet[i-1].getX2Pos(),newY,newDirection);
          } break;
        }
        case _RIGHT: {
          if((classSet[i-1].getX2Pos() + lineLength) < SCREEN_MAX_X)
          {
            newX = classSet[i-1].getX2Pos() + lineLength;
            makeNewThings(i, newX,classSet[i-1].getY2Pos(),newDirection);
          } break;
        }
        case _LEFT:  {
          if((classSet[i-1].getX2Pos() - lineLength) > SCREEN_MIN_X)
          {
            newX = classSet[i-1].getX2Pos() - lineLength;
            makeNewThings(i, newX,classSet[i-1].getY2Pos(),newDirection);
          } break;
        }
      }
    }
  }
  outputTest();
  return 0;
}
  void makeNewThings(int i, int x, int y, int dir) {
    //Generates new coords based on the prior vector positions,
      // and new X/Y positions generated.
      makeThings newThing(classSet[i].getX2Pos(),
                          classSet[i].getY2Pos(),
                          x, y, dir);
      classSet.push_back(newThing);
  }

void outputTest() {
  //Output for testing.
  for(unsigned int i = 0; i < classSet.size(); i++) {
    std::cout << "i: " << i << std::endl
              << "X1: " << classSet[i].getX1Pos()
              << " Y1: " << classSet[i].getY1Pos() << std::endl
              << "X2: " << classSet[i].getX2Pos()
              << " Y2: " << classSet[i].getY2Pos() << std::endl
              << "Direction: " << classSet[i].getDirection() << std::endl << std::endl;
  }
   std::cin.get();
}


