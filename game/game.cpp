#include <iostream>
#include "game.h"
#include "../player/player.h"
class Player;

Game::Game() 
{
  current_player = "white";
}

void Game::start_match(Board& board) 
{
  if (current_player == "white") {
      std::cout << "White's Turn" << std::endl;
      player_white.select_move(board);
    } else {
      std::cout << "Black's Turn" << std::endl;
  }

}


// void Game::display_moves(Board& board)
// {
//   if (current_player == "white") {

 
//   }
// }