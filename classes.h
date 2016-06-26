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

class makeThings {
private:
  unsigned int x1Pos, y1Pos;
  unsigned int x2Pos, y2Pos;
  int direction;
public:

  makeThings(int x1, int y1, int x2, int y2, int dir);
  //~makeThings();
  int getX1Pos() { return x1Pos; }
  int getY1Pos() { return y1Pos; }
  int getX2Pos() { return x2Pos; }
  int getY2Pos() { return y2Pos; }
  int getDirection() { return direction; }
};

makeThings::makeThings(int x1, int y1, int x2, int y2, int dir)
{
  x1Pos = x1;
  y1Pos = y1;
  x2Pos = x2;
  y2Pos = y2;
  direction = dir;
}
