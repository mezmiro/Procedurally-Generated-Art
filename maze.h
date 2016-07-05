#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED

#define PIECE_CORRIDOR 0
#define PIECE_CORNER     1

#define ROTATION_VERTICAL      0
#define ROTATION_HORIZONTAL 1
//Defines the rotation for corner maze pieces, visualized like this:
//Each quadrant is the particular rotation, where the center would be
// walkable space, and the outside is the edge/walls.
/*______________________
|Q2                                    Q1    |
|                                                  |
|                                                  |
|                                                  |
| Q3                                   Q4   |
|______________________|
 */
#define ROTATION_QUAD1            0
#define ROTATION_QUAD2            1
#define ROTATION_QUAD3            2
#define ROTATION_QUAD4            3

class mazePiece {
private:
  CSprite_Image Sprite();
  unsigned int x1Pos, y1Pos;
  unsigned int x2Pos, y2Pos;
  int direction, pieceType, pieceRotation;
public:
  mazePiece(int x1, int y1, int x2, int y2, int dir);
  int getX1Pos() { return x1Pos; }
  int getY1Pos() { return y1Pos; }
  int getX2Pos() { return x2Pos; }
  int getY2Pos() { return y2Pos; }
  void setX1Pos(int X1)  { x1Pos = X1; }
  void setY1Pos(int Y1)   { x1Pos = Y1; }
  void setX2Pos(int X2)  { x1Pos = X2; }
  void setY2Pos(int Y2)   { x1Pos = Y2; }
  int getDirection()     { return direction; }
  int getPieceType()  { return pieceType; }
  int getPieceRotation() { return pieceRotation; }
  void setPieceType(int type)    { pieceType = type; }
  void setPieceRotation(int rotation) { pieceRotation = rotation; }
};

class CMaze {
private:
  std::vector<mazePiece>   mazeCoordSet;
  unsigned int totalPiecesNum;
public:
  unsigned int minPieces, maxPieces;

  void Setup(int minPieces, int maxPieces, int startX1, int startY1,
        int startX2, int startY2, int startDir);
  void initMaze(int minPieces, int maxPieces, int startX1, int startY1,
        int startX2, int startY2, int startDir);
  void addMazePiece(int x, int y, int dir);
  bool validateDirection(int dir, int len);
  void genMazeSet();
  void genPieceTypes();
  void outputTest();

  unsigned int getTotalPiecesNum() { return totalPiecesNum; }
  unsigned int getMazeSize()    { return mazeCoordSet.size(); }
  //unsigned int getSpriteSize()  { return spriteSet.size();    }
  unsigned int getMinMazeSize() { return minPieces; }
  unsigned int getMaxMazeSize() { return maxPieces; }
  void clearMazePieces()
  { mazeCoordSet.erase(mazeCoordSet.begin() + 1, mazeCoordSet.end()); }
};

mazePiece::mazePiece(int x1, int y1, int x2, int y2, int dir)
{
  x1Pos = x1;
  y1Pos = y1;
  x2Pos = x2;
  y2Pos = y2;
  direction = dir;
}

void CMaze::Setup(int minNum, int maxNum, int startX1, int startY1,
             int startX2, int startY2, int startDir)
{
  mazePiece firstPiece(0, 0, 10, 10, _UP);
  mazeCoordSet.push_back(firstPiece);

  //Used for the coord generation function.
  totalPiecesNum = 0;
  minPieces = minNum;
  maxPieces = maxNum;
}

bool CMaze::validateDirection(int dir, int len)
{
  //Check if the new line will be within our screen boundaries.
  switch(dir) {
   case _UP:   {
     if(mazeCoordSet.back().getY2Pos() + len > SCREEN_MAX_Y)
     { return false; }
     else {
        for(unsigned int i = mazeCoordSet.size(); i > 0; i--) {
           if(((mazeCoordSet.back().getX2Pos())       == mazeCoordSet[i-1].getX1Pos()) &&
               (mazeCoordSet.back().getY2Pos() + len) == mazeCoordSet[i-1].getY1Pos())
           { return false; }
        }
     } break; }
   case _DOWN: {
     if(mazeCoordSet.back().getY2Pos() - len < SCREEN_MIN_Y)
     { return false; }
     else {
        for(unsigned int i = mazeCoordSet.size(); i > 0; i--) {
           if(((mazeCoordSet.back().getX2Pos())     == mazeCoordSet[i-1].getX1Pos()) &&
               (mazeCoordSet.back().getY2Pos()-len) == mazeCoordSet[i-1].getY1Pos())
           { return false; }
        }
     } break; }
   case _LEFT: {
     if(mazeCoordSet.back().getX2Pos() - len < SCREEN_MIN_X)
     { return false; }
     else {
        for(unsigned int i = mazeCoordSet.size(); i > 0; i--) {
           if(((mazeCoordSet.back().getX2Pos() - len) == mazeCoordSet[i-1].getX1Pos()) &&
               (mazeCoordSet.back().getY2Pos())       == mazeCoordSet[i-1].getY1Pos())
           { return false; }
        }
     } break; }
   case _RIGHT: {
     if(mazeCoordSet[mazeCoordSet.size()].getX2Pos() + len > SCREEN_MAX_X)
     { return false; }
     else {
        for(unsigned int i = mazeCoordSet.size(); i > 0; i--) {
           if(((mazeCoordSet.back().getX2Pos() + len)  == mazeCoordSet[i-1].getX1Pos()) &&
               (mazeCoordSet.back().getY2Pos())        == mazeCoordSet[i-1].getY1Pos())
           { return false; }
        }
     } break;  }
  }
  return true;
}

void CMaze::addMazePiece(int x, int y, int dir)
{
  //Generates new coords based on the prior vector positions,
  // and new X/Y positions generated.
  mazePiece newPiece(mazeCoordSet[mazeCoordSet.size()-1].getX2Pos(),
                     mazeCoordSet[mazeCoordSet.size()-1].getY2Pos(),
                     x, y, dir);
  mazeCoordSet.push_back(newPiece);
}

void CMaze::genMazeSet()
{
  mazeCoordSet.reserve(MAX_PIECES);
    int newX = mazeCoordSet[0].getX2Pos();
    int newY = mazeCoordSet[0].getY2Pos();
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
            addMazePiece(mazeCoordSet[mazeCoordSet.size()-1].getX2Pos(), newY, newDirection);
           break; }
        case _DOWN: {
            newY -= lineLength;
            addMazePiece(mazeCoordSet[mazeCoordSet.size()-1].getX2Pos(), newY, newDirection);
            break;  }
        case _RIGHT: {
            newX += lineLength;
            addMazePiece(newX, mazeCoordSet[mazeCoordSet.size()-1].getY2Pos(), newDirection);
            break;   }
        case _LEFT:  {
            newX -= lineLength;
            addMazePiece(newX, mazeCoordSet[mazeCoordSet.size()-1].getY2Pos(), newDirection);
            break;   }
      }
    }
  }
}

/***************************************************************/
/******         Generates Maze Piece Types             ******/
/***************************************************************/
void CMaze::genPieceTypes()
{
   //Set the initial piece size. Right now this is always the same piece,
   // so this is the easy way. Later on if we have time, this will be incorporated into
   // the genMaze function to be more efficient.
   mazeCoordSet[0].setPieceType(PIECE_CORRIDOR);
   mazeCoordSet[0].setPieceRotation(ROTATION_VERTICAL);
   for(unsigned int i = 0; i < mazeCoordSet.size() - 1; i++)
   {
      /*****************Corridor Maze Pieces***************/
      //Case where two adjacent pieces are both going up, or down.
      if((mazeCoordSet[i].getDirection() == _UP) && (mazeCoordSet[i+1].getDirection() == _UP)  ||
         (mazeCoordSet[i].getDirection() == _DOWN) && (mazeCoordSet[i+1].getDirection() == _DOWN))
      {
        mazeCoordSet[i].setPieceType(PIECE_CORRIDOR);
        mazeCoordSet[i].setPieceRotation(ROTATION_VERTICAL);
      }
      //Case where two adjacent pieces are both going left, or right.
      if((mazeCoordSet[i].getDirection() == _LEFT) && (mazeCoordSet[i+1].getDirection() == _LEFT)  ||
         (mazeCoordSet[i].getDirection() == _RIGHT) && (mazeCoordSet[i+1].getDirection() == _RIGHT))
      {
        mazeCoordSet[i].setPieceType(PIECE_CORRIDOR);
        mazeCoordSet[i].setPieceRotation(ROTATION_HORIZONTAL);
      }
      /*****************Corner Maze Pieces*****************/
      //Case where pieces are in two series: Left->Down, or Up->Right.
      if((mazeCoordSet[i].getDirection() == _LEFT) && (mazeCoordSet[i+1].getDirection() == _DOWN)  ||
         (mazeCoordSet[i].getDirection() == _UP)     && (mazeCoordSet[i+1].getDirection() == _RIGHT))
      {
        mazeCoordSet[i].setPieceType(PIECE_CORNER);
        mazeCoordSet[i].setPieceRotation(ROTATION_QUAD2);
      }
      //Case where pieces are in two series: Down->Right, or Left->Up.
      if((mazeCoordSet[i].getDirection() == _DOWN) && (mazeCoordSet[i+1].getDirection() == _RIGHT)  ||
         (mazeCoordSet[i].getDirection() == _LEFT)    && (mazeCoordSet[i+1].getDirection() == _UP))
      {
        mazeCoordSet[i].setPieceType(PIECE_CORNER);
        mazeCoordSet[i].setPieceRotation(ROTATION_QUAD3);
      }
      //Case where pieces are in two series: Right->Down, or Up->Left.
      if((mazeCoordSet[i].getDirection() == _RIGHT) && (mazeCoordSet[i+1].getDirection() == _DOWN)  ||
         (mazeCoordSet[i].getDirection() == _UP)       && (mazeCoordSet[i+1].getDirection() == _LEFT))
      {
        mazeCoordSet[i].setPieceType(PIECE_CORNER);
        mazeCoordSet[i].setPieceRotation(ROTATION_QUAD1);
      }
      //Case where pieces are in two series: Right->Up, or Down->Left.
      if((mazeCoordSet[i].getDirection() == _RIGHT) && (mazeCoordSet[i+1].getDirection() == _UP)  ||
         (mazeCoordSet[i].getDirection() == _DOWN) && (mazeCoordSet[i+1].getDirection() == _LEFT))
      {
        mazeCoordSet[i].setPieceType(PIECE_CORNER);
        mazeCoordSet[i].setPieceRotation(ROTATION_QUAD4);
      }
   }
}
void CMaze::outputTest() {
  //Output for testing.
  for(unsigned int i = 0; i < mazeCoordSet.size(); i++) {
    std::cout << "i: "   << i << std::endl
              << "X1: "  << mazeCoordSet[i].getX1Pos()
              << " Y1: " << mazeCoordSet[i].getY1Pos()
              << " X2: " << mazeCoordSet[i].getX2Pos()
              << " Y2: " << mazeCoordSet[i].getY2Pos() << std::endl
              << "Direction: " << mazeCoordSet[i].getDirection() << std::endl << std::endl;
  }
   std::cin.get();
}


#endif // MAZE_H_INCLUDED
