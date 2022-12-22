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
    bool inboundsX = 0 <= adj_x && adj_x < 8;
    bool inboundsY = 0 <= adj_y && adj_y < 8;
    if (!inboundsX || !inboundsY) continue;

    std::vector<int> adj_pos = { adj_x, adj_y };

    if (board.grid[adj_x][adj_y].color == "null_color" || board.grid[adj_x][adj_y].color != color) {
      moves.push_back(adj_pos);
    }
  }
  return moves;
}

std::vector<std::vector<int>> Piece::slideable_squares(Board& board) {
  
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
      } 
      adj_x += x;
      adj_y += y;
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

std::vector<std::vector<int>> Piece::valid_moves(Board& board) { 
  
  std::vector<std::vector<int> > moves;

  if (slideable == true) {
    moves = slideable_moves(board);
  } else {
    moves = stepable_moves(board);
  }

  return moves;

}

std::vector<std::vector<int>> Piece::moves_out_of_check(Board& board) 
{
  Board board_copy(board);
  int king_startX = position[0];
  int king_startY = position[1];
  std::vector<std::vector<int>> valid_moves_from_check;
  if (color == "white") {
    // iterate over pieces
    for (int i = 0; i < board.white_pieces.size(); i++) {
      Board board_copy(board);
      std::vector<std::vector<int>> moves = board_copy.white_pieces[i].valid_moves(board_copy);
      for (int j = 0; j < moves.size(); j++) {
        int new_posX = moves[j][0];
        int new_posY = moves[j][1];
        std::vector<int> pos = { new_posX, new_posY };
        int pos_arr[2] = { new_posX, new_posY };
        board_copy.move_piece(board.white_pieces[i], pos_arr);
        // std::cout << board.in_check(board.grid[king_startX][king_startY]);

        if (!board.in_check(board.grid[king_startX][king_startY])) {
          valid_moves_from_check.push_back(pos);
        }
      }
    } 
  } else {
     for (int i = 0; i < board.black_pieces.size(); i++) {
      Board board_copy(board);
      std::vector<std::vector<int>> moves = board_copy.black_pieces[i].valid_moves(board_copy);
      for (int j = 0; j < moves.size(); j++) {
        int new_posX = moves[j][0];
        int new_posY = moves[j][1];
        std::vector<int> pos = { new_posX, new_posY };
        int pos_arr[2] = { new_posX, new_posY };
        board_copy.move_piece(board.black_pieces[i], pos_arr);
        // std::cout << board.in_check(board.grid[king_startX][king_startY]);
        if (!board.in_check(board.grid[king_startX][king_startY])) {
          valid_moves_from_check.push_back(pos);
        }
      }
    } 
  }
  // for (int i = 0; i < valid_moves_from_check.size(); i++) {
  //   std::cout << valid_moves_from_check[i][0] << valid_moves_from_check[i][1] << std::endl;
  // }
  return valid_moves_from_check;
}


