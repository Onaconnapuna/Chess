#ifndef _GAME_
#define _GAME_ 
#include "../board/board.h"
#include "../player/player.h"
class Game {

  public: 
    Board board;
    Player player_white;
    Player player_black; 
    std::string current_player = "white";

    Game();
    void start_match(Board& board);
    void display_moves(Board& board);
    
};



#endif


