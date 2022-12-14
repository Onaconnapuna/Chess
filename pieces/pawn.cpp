#include "pawn.h"
#include <iostream>
#include <string>
#include <vector>

PawnPiece::PawnPiece(int posX, int posY, std::string add_color, std::string add_symbol) : Piece(posX, posY) {
  value = "pawn";
  symbol = add_symbol;
  color = add_color;
  if (color == "white") forward_dir = -1;
    else forward_dir = 1;
  slideable = false;
  forward_deltas = { { forward_dir, 0 }, { forward_dir + forward_dir, 0} };
  capturing_deltas = { { forward_dir, -forward_dir }, { forward_dir, forward_dir} };
}



bool PawnPiece::on_starting_row() 
{
  bool starting;
  if (color == "white") {
    position[0] == 6 ? starting = true : starting = false;
  } else {
    position[1] == 1 ? starting = true : starting = false;
  }
  return starting;
}

std::vector<std::vector<int>> PawnPiece::valid_moves(Board& board) 
{
  std::vector<std::vector<int>> moves;
  int board_x = position[0];
  int board_y = position[1];
  // checkin if on starting pos, if so checking the first 2 positions.
  if (on_starting_row()) {
    for (int i = 0; i < forward_deltas.size(); i++) {
      int x = forward_deltas[i][0];
      int y = forward_deltas[i][1];
      int adj_x = x + board_x;
      int adj_y = y + board_y;
      if (board.grid[adj_x][adj_y].value == "empty_space") {
        std::vector<int> move = { adj_x, adj_y };
        moves.push_back(move);
      }
    }
    // check if piece can move in its forward dir;
  } else {
    int adj_x = board_x;
    int adj_y = board_y;
    bool inboundsX = 0 <= adj_x < 8;
    if (inboundsX && board.grid[adj_x + forward_dir][adj_y].value == "empty_space") {
      std::vector<int> move = { adj_x, adj_y };
      moves.push_back(move);
    }
  }
  
  for (int i = 0; i < capturing_deltas.size(); i++) {
    int x = capturing_deltas[i][0];
    int y = capturing_deltas[i][1];
    int adj_x = x + board_x;
    int adj_y = y + board_y;

    bool inboundsX = 0 <= adj_x && adj_x < 8; 
    bool inboundsY = 0 <= adj_y && adj_y < 8;

    if (inboundsX && inboundsY && board.grid[adj_x][adj_y].color != "null_color" && board.grid[adj_x][adj_y].color != color) {
      std::vector<int> move = { adj_x, adj_y };
      moves.push_back(move);
    }
  }

  return moves;
} 

