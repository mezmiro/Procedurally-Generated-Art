//Used in the gameState var.
#define INTRO_STATE               0
#define PLAY_STATE                1
#define YOU_WIN_STATE         2
#define GAME_OVER_STATE 3
#define EXIT_STATE                  4


#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class CGame   {
public:
  CPlayer Player;
  std::vector<CLevel> Levels;
  CGame();
  int getLevelNum();
  void addLevel(int minPieces, int maxPieces, int xPos, int yPos, int xEnd, int yEnd, int dir);
};

CGame::CGame() {
  Levels.reserve(3);
  CLevel lvl;
   lvl.Setup(20,30,0,0,10,10,_UP);
   Levels.push_back(lvl);
}

void CGame::addLevel(int minPieces, int maxPieces, int xPos, int yPos, int xEnd, int yEnd, int dir) {
  CLevel lvl;
   lvl.Setup(minPieces, maxPieces, xPos, yPos, xEnd, yEnd, _UP);
  Levels.push_back(lvl);

}

int CGame::getLevelNum()  {
    return Levels.size();
}

#endif // GAME_H_INCLUDED
