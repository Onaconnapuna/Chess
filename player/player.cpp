#include "player.h"
#include <iostream>

Player::Player(std::string new_color) {
  color = new_color;
}

std::map<std::string, std::vector<std::string>> Player::all_valid_moves(Board &board)
{
  std::map<std::string, std::vector<std::string>> all_moves_map;
  std::map<std::string, std::vector<std::vector<int>>> valid_moves_map;
  std::string piece_color = color; 
  if (color == "white") {
    for (int i = 0; i < board.white_pieces.size(); i++) {
      // make key the piece/positon interpolation
      std::stringstream key_stream;
      key_stream << board.white_pieces[i].value << board.white_pieces[i].position[0] << board.white_pieces[i].position[1]; 
      std::string key = key_stream.str();
      //get valid moves and add to map;
      std::vector<std::vector<int>> moves = board.white_pieces[i].valid_moves(board);
      // for (int j = 0; j < moves.size(); j++) {
      //   std::cout << moves[j][0] << moves[j][1] << std::endl;
      // }
      valid_moves_map[key] = moves;
    }
    for (int i = 0; i < board.white_pawns.size(); i++) {
      std::stringstream key_stream;
      key_stream << board.white_pawns[i].value << board.white_pawns[i].position[0] << board.white_pawns[i].position[1];
      std::string key = key_stream.str(); 
      std::vector<std::vector<int>> moves = board.white_pawns[i].valid_moves(board);
      valid_moves_map[key] = moves;
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
      valid_moves_map[key] = moves;
    }
    for (int i = 0; i < board.black_pawns.size(); i++) {
      std::stringstream key_stream;
      key_stream << board.black_pawns[i].value << board.black_pawns[i].position[0] << board.black_pawns[i].position[1];
      std::string key = key_stream.str(); 
      std::vector<std::vector<int>> moves = board.black_pawns[i].valid_moves(board);
      valid_moves_map[key] = moves;
    }
  }


  std::vector<std::string> alpha_grid = { "A", "B", "C", "D", "E", "F", "G", "H" };
  std::vector<std::string> numeric_grid = { "8", "7", "6", "5", "4", "3", "2", "1" };
  std::map<std::string, std::vector<std::vector<int>>>::iterator it;
  //iterate over  all the pieces and convert to chess notation
  for (it = valid_moves_map.begin(); it != valid_moves_map.end(); it++) 
  { 
    
    std::string new_key = it->first;
    std::vector<std::string> moves = {};
    for (int i = 0; i < it->second.size(); i++)
    {
      // std::cout << it->second[i][0] << it->second[i][1] << std::endl;
      int position_one = it->second[i][0];
      int position_two = it->second[i][1];

      // int position_two;
      // if (it -> second[i][1] == 0) {
      //   position_two = 0 ;
      // } else {
      //   position_two = 8 - it->second[i][1]; 
      // }
      // std::cout << position_one << position_two << std::endl;

      std::string new_key = it->first;
      std::stringstream new_key_stream;
      new_key_stream << alpha_grid[position_two] << " " << numeric_grid[position_one];
      std::string move = new_key_stream.str();
      moves.push_back(move);
    }
    all_moves_map[new_key] = moves;
  }

  return all_moves_map;
}

// void Player::make_move(std::map<std::string, std::vector<std::vector<int>>> moves, Board& board) 
// {
//   std::vector<std::string> numeric_grid = { "1", "2", "3", "4", "5", "6", "7", "8" }; 
//   std::vector<std::string> alpha_grid = { "A", "B", "C", "D", "E", "F", "G", "H" };
//   std::map<std::string, std::vector<std::vector<int>>>::iterator it = moves.begin();
//   while (it != moves.end()) {

//     ++it;
//   } 
// }