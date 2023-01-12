#include "player.h"

Player::Player(std::string new_color) {
  color = new_color;
}

std::map<std::string, std::vector<std::vector<int>>> Player::all_valid_moves(Board &board)
{
  std::map<std::string, std::vector<std::vector<int>>> moves_map;
  std::string piece_color = color; 
  if (color == "white") {
    for (int i = 0; i < board.white_pieces.size(); i++) {
      // make key the piece/positon interpolation
      std::stringstream key_stream;
      key_stream << board.white_pieces[i].value << board.white_pieces[i].position[0] << board.white_pieces[i].position[1]; 
      std::string key = key_stream.str();

      //get valid moves and add to map;
      std::vector<std::vector<int>> moves = board.white_pieces[i].valid_moves(board);
      moves_map[key] = moves;
    }
    for (int i = 0; i < board.white_pawns.size(); i++) {
      std::stringstream key_stream;
      key_stream << board.white_pawns[i].value << board.white_pawns[i].position[0] << board.white_pawns[i].position[1];
      std::string key = key_stream.str(); 
      std::vector<std::vector<int>> moves = board.white_pawns[i].valid_moves(board);
      moves_map[key] = moves;
    }
  }
  else {
   for (int i = 0; i < board.black_pieces.size(); i++) {
      // make key the piece/positon interpolation
      std::stringstream key_stream;
      key_stream << board.black_pieces[i].value << board.black_pieces[i].position[0] << board.black_pieces[i].position[1]; 
      std::string key = key_stream.str();

      //get valid moves and add to map;
      std::vector<std::vector<int>> moves = board.black_pieces[i].valid_moves(board);
      moves_map[key] = moves;
    }
    for (int i = 0; i < board.black_pawns.size(); i++) {
      std::stringstream key_stream;
      key_stream << board.black_pawns[i].value << board.black_pawns[i].position[0] << board.black_pawns[i].position[1];
      std::string key = key_stream.str(); 
      std::vector<std::vector<int>> moves = board.black_pawns[i].valid_moves(board);
      moves_map[key] = moves;
    }
  }
  return moves_map;
}

void Player::make_move(std::vector<std::vector<int>> valid_moves) 
{
  
}