#ifndef _GAME_
#define _GAME_ 
#include "../board/board.h"
#include "../player/player.h"
class Game {

  public: 
    Board board;

    Game();
    void start_match(Board& board);
    
};



#endif


