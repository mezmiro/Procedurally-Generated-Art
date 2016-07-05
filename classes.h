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
