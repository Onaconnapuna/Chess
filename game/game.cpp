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
      std::cout << "Whites turn" << std::endl;
    } else {
      
  }


  }


void Game::display_moves(Board& board)
{
  if (current_player == "white") {


  }
}