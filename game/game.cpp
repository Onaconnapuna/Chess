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
    bool move_made = player_white.make_move(board);
    while (!move_made)  {
      std::cout << move_made << std::endl;
      move_made = player_white.make_move(board);
      board.print_board();
    }
  } else {
    bool move_made = player_black.make_move(board);
    while (!move_made) player_black.make_move(board);
  }

}


// void Game::display_moves(Board& board)
// {
//   if (current_player == "white") {

 
//   }
// }