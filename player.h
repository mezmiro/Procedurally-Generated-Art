#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class CPlayer {
private:
  CSprite_Vertex_Generated Sprite();
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

CPlayer::CPlayer()
{

}

#endif // PLAYER_H_INCLUDED
