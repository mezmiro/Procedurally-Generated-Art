#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#endif // CLASSES_H_INCLUDED

#define _UP    1
#define _DOWN  2
#define _LEFT  3
#define _RIGHT 4

#define SCREEN_MIN_X 0
#define SCREEN_MIN_Y 0
#define SCREEN_MAX_X 500
#define SCREEN_MAX_Y 500

#define MIN_PIECES 20
#define MAX_PIECES 35

#define MAZE_PIECE_WIDTH  50
#define MAZE_PIECE_HEIGHT 50
//Sprite types, used in the construction of a CSprite class.
#define SQUARE_CORRIDOR 0
#define SQUARE_CORNER   1
#define SQUARE_WATER    2
#define SQUARE_OIL      3
#define SQUARE_TREE     4
#define SQUARE_STONE    5
#define SQUARE_WEB      6


class CSprite {
private:
  std::string texFilePath;
  unsigned int width;
  unsigned int height;
public:
  CSprite(int type, int width, int height);
  std::string getTexFilePath();
  unsigned int getWidth();
  unsigned int getHeight();
};

class mazePiece {
private:
  unsigned int x1Pos, y1Pos;
  unsigned int x2Pos, y2Pos;
  int direction;
public:
  CSprite sprite();
  mazePiece();
  mazePiece(int x1, int y1, int x2, int y2, int dir);
  int getX1Pos() { return x1Pos; }
  int getY1Pos() { return y1Pos; }
  int getX2Pos() { return x2Pos; }
  int getY2Pos() { return y2Pos; }
  int getDirection() { return direction; }

};

mazePiece::mazePiece(int x1, int y1, int x2, int y2, int dir)
{
  x1Pos = x1;
  y1Pos = y1;
  x2Pos = x2;
  y2Pos = y2;
  direction = dir;
}

class CMaze {
private:
  std::vector<mazePiece> mazeCoordSet();
  std::vector<CSprite>   spriteSet();
  //std::vector<mazePiece> classSet1(1,mazePiece(startX1,startY1,startX2,startY2, startDir));
  //std::vector<CSprite> mazeBazeSpriteSet(1,CSprite(SQUARE_CORRIDOR, MAZE_PIECE_WIDTH, MAZE_PIECE_HEIGHT));
public:
  CMaze(int minPieces, int maxPieces, int startX1, int startY1,
        int startX2, int startY2, int startDir);
  void addMazePiece();
};

class CEnemy  {
private:
  int HP, Atk, Def;
public:
  CEnemy();
  int getHP();
  int getAtk();
  int getDef();
};

class CPlayer {
private:
  int HP, Atk, Def;
  int xPos, yPos;
public:
  CPlayer();
  int getHP();
  int getAtk();
  int getDef();
  int getXPos();
  int getYPos();

};

class CLevel  {
private:
  int levelNum;
  //Reqs: min pieces, max pieces.
  //CMaze Maze();
public:
  CLevel();
  int getLevelNum();
};

class CGame   {
private:
  //If we decide to implement this.
  int difficulty;

  CGame();
  CLevel Lvl1();
  CLevel Lvl2();
  CLevel Lvl3();
  CLevel Lvl4();
public:

};
