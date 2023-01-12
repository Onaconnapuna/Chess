#ifndef _GAME_
#define _GAME_ 
#include "../board/board.h"
#include "../player/player.h"
class Game {

  public: 
    Board board;
    Player player_white = Player("white");
    Player player_black = Player("black"); 
    std::string current_player;
    Game();
    bool game_over = false;
    void start_match(Board& board);
    void display_moves(Board& board);
    
};



#endif


