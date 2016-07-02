/***************************************************************************
*Random Map Generation
* -Made for the _HappieCat game dev challenge for procedurally generated art.
* -Code structure is iffy at the moment, as it's kind of slapped together
*   for now.
****************************************************************************/


#include "classes.h"

void outputTest();
bool validateDirection(int dir, int len);
void addMazePiece(int x, int y, int dir);
void genMazeSet();

std::vector<mazePiece> classSet(1,mazePiece(0,0,0,10, _UP));
unsigned int totalPiecesNum = 0;

int main()
{
  do {
    genMazeSet();
    totalPiecesNum = classSet.size();

    if((totalPiecesNum < MIN_PIECES) || (totalPiecesNum > MAX_PIECES))
    { classSet.erase(classSet.begin() + 1,classSet.end()); totalPiecesNum = 1; }
  } while((totalPiecesNum < MIN_PIECES) || (totalPiecesNum > MAX_PIECES));

  outputTest();
  std::cin.get();

  return 0;
}

void genMazeSet()
{
  classSet.reserve(MAX_PIECES);
    int newX = classSet[0].getX2Pos();
    int newY = classSet[0].getY2Pos();
    int newDirection = _DOWN;
    int lineLength = 10;

  srand(time(NULL));
  //Create and assign vals for new classes within the vector.
  for(unsigned int i = 1; i < 50; i++) {
    //Gen new direction randomly.
    newDirection = rand() % 4 + 1;
    //Create the new X2 and Y2 positions based on the new direction.
    if(validateDirection(newDirection, lineLength)) {
      switch(newDirection) {
        case _UP: {
            newY += lineLength;
            addMazePiece(classSet[classSet.size()-1].getX2Pos(), newY, newDirection);
           break; }
        case _DOWN: {
            newY -= lineLength;
            addMazePiece(classSet[classSet.size()-1].getX2Pos(), newY, newDirection);
            break;  }
        case _RIGHT: {
            newX += lineLength;
            addMazePiece(newX, classSet[classSet.size()-1].getY2Pos(), newDirection);
            break;   }
        case _LEFT:  {
            newX -= lineLength;
            addMazePiece(newX, classSet[classSet.size()-1].getY2Pos(), newDirection);
            break;   }
      }
    }
  }

}

void addMazePiece(int x, int y, int dir) {
  //Generates new coords based on the prior vector positions,
    // and new X/Y positions generated.
    mazePiece newPiece(classSet[classSet.size()-1].getX2Pos(),
                        classSet[classSet.size()-1].getY2Pos(),
                        x, y, dir);
    //In cases where we made mazes with less than MIN_PIECES elements,
    // we must assign the class directly instead of pushing the class
    // to the vector like normal.

    classSet.push_back(newPiece);
}

bool validateDirection(int dir, int len)
{
  //Check if the new line will be within our screen boundaries.
  switch(dir) {
   case _UP:   {
     if(classSet.back().getY2Pos() + len > SCREEN_MAX_Y)
     { return false; }
     else {
        for(unsigned int i = classSet.size(); i > 0; i--) {
           if(((classSet.back().getX2Pos())       == classSet[i-1].getX1Pos()) &&
               (classSet.back().getY2Pos() + len) == classSet[i-1].getY1Pos())
           { return false; }
        }
     } break; }
   case _DOWN: {
     if(classSet.back().getY2Pos() - len < SCREEN_MIN_Y)
     { return false; }
     else {
        for(unsigned int i = classSet.size(); i > 0; i--) {
           if(((classSet.back().getX2Pos())     == classSet[i-1].getX1Pos()) &&
               (classSet.back().getY2Pos()-len) == classSet[i-1].getY1Pos())
           { return false; }
        }
     } break; }
   case _LEFT: {
     if(classSet.back().getX2Pos() - len < SCREEN_MIN_X)
     { return false; }
     else {
        for(unsigned int i = classSet.size(); i > 0; i--) {
           if(((classSet.back().getX2Pos() - len) == classSet[i-1].getX1Pos()) &&
               (classSet.back().getY2Pos())       == classSet[i-1].getY1Pos())
           { return false; }
        }
     } break; }
   case _RIGHT: {
     if(classSet[classSet.size()].getX2Pos() + len > SCREEN_MAX_X)
     { return false; }
     else {
        for(unsigned int i = classSet.size(); i > 0; i--) {
           if(((classSet.back().getX2Pos() + len)  == classSet[i-1].getX1Pos()) &&
               (classSet.back().getY2Pos())        == classSet[i-1].getY1Pos())
           { return false; }
        }
     } break;  }
  }
  return true;
}

void outputTest() {
  //Output for testing.
  for(unsigned int i = 0; i < classSet.size(); i++) {
    std::cout << "i: " << i << std::endl
              << "X1: " << classSet[i].getX1Pos()
              << " Y1: " << classSet[i].getY1Pos()
              << " X2: " << classSet[i].getX2Pos()
              << " Y2: " << classSet[i].getY2Pos() << std::endl
              << "Direction: " << classSet[i].getDirection() << std::endl << std::endl;
  }
   std::cin.get();
}
