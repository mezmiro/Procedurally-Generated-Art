#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

class CForest {
private:
  //forestType defines which permutation we're using.
  //  Ex: 3-squares in a line, 6 squares in a rectangle, 4 squares in a half-ish cross.
  //forestSide defines if we're on the right or left side of the corridor, or if we're on a corner.
  int forestType;
  int forestSide;
public:
  void makeForest();
  int getForestType();
  int getForestSide();
};

void CForest::makeForest() {

}

class CWater { };
class COil { };
class CWeb { };

class CTerrainArea {
private:

public:
  void setupArea(int level);
};
void CTerrainArea::setupArea(int level) {
  switch(level)  {
    //Level 1: Forest areas only.
  case 0:
    {

     break;
    }
    //Level 2: Forest and water areas only.
  case 1:
   {

    break;
   }
   //Forest, water, and oil areas only.
   //Maybe webs if we have time.
  case 2:
   {

     break;
   }
  }
}

class CTerrain {
private:
    std::vector<CTerrainArea> Area;
public:
  void Setup();
};

void CTerrain::Setup()
{

}


#endif // TERRAIN_H_INCLUDED
