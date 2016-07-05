#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

class CLevel  {
private:
  bool Complete;
public:
  void Setup(int minPiece, int maxPiece, int startX, int startY, int endX, int endY, int dir);
  bool getComplete();
   CMaze    Maze;
   CTerrain Terrain;
};

void CLevel::Setup(int minPiece, int maxPiece, int startX, int startY, int endX, int endY, int dir)
{
  Complete = false;
  Maze.Setup(minPiece, maxPiece, startX, startY, endX, endY, dir);
  Terrain.Setup();
}

bool CLevel::getComplete()
{  return Complete; }

#endif // LEVEL_H_INCLUDED
