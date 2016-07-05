/***************************************************************************
*Random Map Generation
* -Made for the _HappieCat game dev challenge for procedurally generated art.
* -Code structure is iffy at the moment, as it's kind of slapped together
*   for now.
****************************************************************************/

#include "classes.h"
#include "sprite.h"
#include "maze.h"
#include "terrain.h"
#include "enemy.h"
#include "player.h"
#include "level.h"
#include "game.h"

void makeTheStuff();

unsigned int gameState = 1;
unsigned int totalPiecesNum = 0;

int main()
{
  CGame Game;

  while(gameState != EXIT_STATE)
  {
    switch(gameState) {
    case INTRO_STATE: {
      //Random thought - Can we/do games load resources while the "intro movie/cinematic" is playing?
      //Like in a separate thread.. hmm.

      break;
    }
    case PLAY_STATE: {
      switch(Game.getLevelNum() - 1) {
        case 0: {
          /*****************************************/
          //                 Level 1 Flow
          /*****************************************/
          //Prepare necessary values/assets.
          //Gen maze coords, maze sprite types(hall,corner,rotation).
          //Gen terrain types, positions.
          do {
            Game.Levels[0].Maze.genMazeSet() ;
            totalPiecesNum = Game.Levels[0].Maze.getMazeSize();

            if((totalPiecesNum < Game.Levels[0].Maze.getMinMazeSize()) || (totalPiecesNum > Game.Levels[0].Maze.getMaxMazeSize()))
            {
              Game.Levels[0].Maze.clearMazePieces();
              totalPiecesNum = 1;
            }
          } while((totalPiecesNum < Game.Levels[0].Maze.getMinMazeSize()) || (totalPiecesNum > Game.Levels[0].Maze.getMaxMazeSize()));


            //Check if the player beat this level, and go to the next.
            if(Game.Levels[Game.getLevelNum() -1].getComplete())
            { Game.addLevel(51, 70, 0, 0, 10, 10, _UP); }
          //Level 1 rendering / gameplay.

          //Check if the player beat this level, and go to the next.
          if(Game.Levels[Game.getLevelNum() -1].getComplete())
          { Game.addLevel(31, 50, 0, 0, 10, 10, _UP); }

          //Reset the game state for development, as we are still making most of this.
          gameState = 4;
          break;
        }
        case 1:  {
          /*****************************************/
          //                 Level 2 Flow
          /*****************************************/
          //Prepare necessary values/assets.
          //Gen maze coords, maze sprite types(hall,corner,rotation).
          //Gen terrain types, positions.
          //Level 2 rendering / gameplay.



          break;
        }
        case 2:  {
          /*****************************************/
          //                 Level 3 Flow
          /*****************************************/
          //Prepare necessary values/assets.
          //Gen maze coords, maze sprite types(hall,corner,rotation).
          //Gen terrain types, positions.

          //Level 3 rendering / gameplay.

          //Check if the player won.
          if(Game.Levels[Game.getLevelNum() -1].getComplete())
          {  gameState = YOU_WIN_STATE; }
          break;
          }
      } } }
  }
  //Generate the maze coord set.
  //Game.Levels[0].Maze.genMazeSet() ;
  do {
    Game.Levels[0].Maze.genMazeSet() ;
    //Game.genMazeSet();
    totalPiecesNum = Game.Levels[0].Maze.getMazeSize();

    if((totalPiecesNum < Game.Levels[0].Maze.getMinMazeSize()) || (totalPiecesNum > Game.Levels[0].Maze.getMaxMazeSize()))
    {
      Game.Levels[0].Maze.clearMazePieces();
      totalPiecesNum = 1;
    }
  } while((totalPiecesNum < Game.Levels[0].Maze.getMinMazeSize()) || (totalPiecesNum > Game.Levels[0].Maze.getMaxMazeSize()));

  Game.Levels[0].Maze.outputTest();

    std::cin.get();
  return 0;
}
