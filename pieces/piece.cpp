#include <string>
#include "piece.h"
#include <vector>
#include <string>
#include "../board/board.h"
#include <iostream>

Piece::Piece(int posX, int posY) {
  position = { posX, posY };
}

// Piece::Piece(const Piece& other) : 

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

// std::vector<std::vector<int>> Piece::valid_movesP(Board& board, PawnPiece& pawn) 
// {
//    std::cout << "was called" << std::endl;
//   std::vector<std::vector<int>> moves;
//   std::cout << "declared moves" << std::endl;
//   int board_x = position[0];
//   int board_y = position[1];
//   std::cout << "declared board pos" << std::endl;
//   if (pawn.on_starting_row()) {
//     for (int i = 0; i < pawn.forward_deltas.size(); i++) {
//       int x = deltas[i][0];
//       int y = deltas[i][1];
//       int adj_x = x + board_x;
//       int adj_y = y + board_y;
//       if (board.grid[adj_x][adj_y].value == "null_piece") {
//         std::vector<int> move = { adj_x, adj_y };
//         moves.push_back(move);
//       }
//     }
//   } else {
//     int adj_x = board_x;
//     int adj_y = board_y;
//     if (board.grid[adj_x + 1][adj_y].value == "null_piece") {
//       std::vector<int> move = { adj_x, adj_y };
//       moves.push_back(move);
//     }
//   }

//   std::cout << "checked starting row" << std::endl;
  
//   for (int i = 0; i < pawn.capturing_deltas.size(); i++) {
//     int x = pawn.capturing_deltas[i][0];
//     int y = pawn.capturing_deltas[i][1];
//     int adj_x = x + board_x;
//     int adj_y = y + board_y;
//     std::cout << "checking capturing deltas" << std::endl;
//     if (board.grid[adj_x][adj_y].color != "null_color" && board.grid[adj_x][adj_y].color != color) {
//       std::vector<int> move = { adj_x, adj_y };
//       moves.push_back(move);
//     }
//   }

//   return moves;
// }

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

std::vector<std::vector<int>> Piece::slideable_moves(Board& board) 
{
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

std::vector<std::vector<int>> Piece::valid_moves(Board& board) 
{ 
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
      if (board_copy.white_pieces[i].value == "king") continue;
      int piece_startX = board_copy.white_pieces[i].position[0];
      int piece_startY = board_copy.white_pieces[i].position[1];
      //find each valid move for every piece
      std::vector<std::vector<int>> moves = board_copy.white_pieces[i].valid_moves(board_copy);
      for (int j = 0; j < moves.size(); j++) {
        int new_posX = moves[j][0];
        int new_posY = moves[j][1];
        std::vector<int> pos = { new_posX, new_posY };
        int pos_arr[2] = { new_posX, new_posY };
        board_copy.move_piece(board_copy.white_pieces[i], pos_arr);
        if (!board_copy.in_check(board_copy.grid[king_startX][king_startY])) {
          valid_moves_from_check.push_back(pos);
        }
      }
      int start_pos[2] = { piece_startX, piece_startY };
      board_copy.move_piece(board_copy.white_pieces[i], start_pos);
    } 
  } else {
    // do the same but for black
     for (int i = 0; i < board.black_pieces.size(); i++) {
      if (board_copy.black_pieces[i].value == "king") continue;
      int piece_startX = board_copy.black_pieces[i].position[0];
      int piece_startY = board_copy.black_pieces[i].position[1];
      std::vector<std::vector<int>> moves = board_copy.black_pieces[i].valid_moves(board_copy);
      for (int j = 0; j < moves.size(); j++) {
        int new_posX = moves[j][0];
        int new_posY = moves[j][1];
        std::vector<int> pos = { new_posX, new_posY };
        int pos_arr[2] = { new_posX, new_posY };
        board_copy.move_piece(board_copy.black_pieces[i], pos_arr);
        if (!board.in_check(board.grid[king_startX][king_startY])) {
          valid_moves_from_check.push_back(pos);
        }
      }
      int start_pos[2] = { piece_startX, piece_startY };
      board_copy.move_piece(board_copy.black_pieces[i], start_pos);
    } 
  }
  // for (int i = 0; i < valid_moves_from_check.size(); i++) {
  //   std::cout << valid_moves_from_check[i][0] << valid_moves_from_check[i][1] << std::endl;
  // }
  return valid_moves_from_check;
}


