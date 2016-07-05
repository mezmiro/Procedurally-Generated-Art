#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

class CEnemy  {
private:
  unsigned int HP, MP, ATK, DEF;
  unsigned int xPos, yPos;
  unsigned int width, height;

public:
  CEnemy(unsigned int hp, unsigned int mp,
         unsigned int atk, unsigned int def,
         unsigned int x, unsigned int y,
         unsigned int w, unsigned int h) {
    HP = hp;
    MP = mp;
    ATK = atk;
    DEF = def;
    xPos = x;
    yPos = y;
    w = width;
    h = height;
   }
  unsigned int getHP()  { return HP;  }
  unsigned int getMP()  { return MP;  }
  unsigned int getAtk() { return ATK; }
  unsigned int getDef() { return DEF; }
  void reduceHP(unsigned int hp)   { HP -= hp; }
  void reduceMP(unsigned int mp)   { MP -= mp; }
  void increaseHP(unsigned int hp) { HP += hp; }
  void increaseMP(unsigned int mp) { MP += mp; }
};

#endif // ENEMY_H_INCLUDED
