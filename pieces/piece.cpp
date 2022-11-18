#include <string>
#include "piece.h"
#include <vector>
#include <string>
#include "../board/board.h"
#include <iostream>

Piece::Piece(int posX, int posY) {
  position = { posX, posY };
}

void Piece::add_value(std::string value) {
  value = value;
}

std::string Piece::get_value() {
  return value;
}

std::vector<std::vector<int>> Piece::stepable_moves(Board& board) {

  std::vector<std::vector<int> > moves;
  for (int i = 0; i < deltas.size(); i++) {
    int x = deltas[i][0];
    int y = deltas[i][1];

    int board_x = position[0];
    int board_y = position[1];

    int adj_x = x + board_x;
    int adj_y = y + board_y;

    std::vector<int> adj_pos = { adj_x, adj_y };

    if (board.grid[adj_x][adj_y].color == "null_color" || board.grid[adj_x][adj_y].color != color) {
      moves.push_back(adj_pos);
    }
  }
  return moves;
}

std::vector<std::vector<int>> Piece::slideable_moves(Board& board) {
  
  std::vector<std::vector<int> > moves;
  bool valid_space = false;
  for (int i = 0; i < deltas.size(); i++) {
    int x = deltas[i][0];
    int y = deltas[i][1];
    int board_x = position[0];
    int board_y = position[1];

    int adj_x = x + board_x;
    int adj_y = y + board_y;
    valid_space = true;
    while (valid_space) {
      std::vector<int> adj_pos = { adj_x, adj_y }; 
      bool inboundsX = 0 <= adj_x && adj_x < 8;
      bool inboundsY = 0 <= adj_y && adj_y < 8;

      if (!inboundsX || !inboundsY) {
        valid_space = false;
        break;
      }

      if (board.grid[adj_x][adj_y].color == color) {
        valid_space = false;
        break;
      } else if (board.grid[adj_x][adj_y].color == "null_color") {
        moves.push_back(adj_pos);
      } else if (board.grid[adj_x][adj_y].color != color) {
        moves.push_back(adj_pos);
        valid_space = false;
        break;
      } 
      adj_x += x;
      adj_y += y;
    } 
  }

  return moves;
}

