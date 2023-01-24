#include "player.h"
#include <iostream>

Player::Player(std::string new_color) {
  color = new_color;
}

std::map<std::string, std::vector<std::string>> Player::all_valid_moves(Board &board)
{
  std::map<std::string, std::vector<std::string>> all_moves_map;
  std::map<std::string, std::vector<std::vector<int>>> valid_moves_map;
  std::vector<std::string> alpha_grid = { "A", "B", "C", "D", "E", "F", "G", "H" };
  std::vector<std::string> numeric_grid = { "8", "7", "6", "5", "4", "3", "2", "1" };
  std::string piece_color = color; 
  if (color == "white") {
    for (int i = 0; i < board.white_pieces.size(); i++) {
      // make key the piece/positon interpolation
      std::stringstream key_stream;
      int position_one = board.white_pieces[i].position[0];
      int position_two = board.white_pieces[i].position[1];
      key_stream << board.white_pieces[i].symbol << alpha_grid[position_two] << numeric_grid[position_one]; 
      std::string key = key_stream.str();
      //get valid moves and add to map;
      std::vector<std::vector<int>> moves = board.white_pieces[i].valid_moves(board);
      valid_moves_map[key] = moves;
    }
    for (int i = 0; i < board.white_pawns.size(); i++) {
      std::stringstream key_stream;
      int position_one = board.white_pawns[i].position[0];
      int position_two = board.white_pawns[i].position[1];
      key_stream << board.white_pawns[i].symbol << alpha_grid[position_two] << numeric_grid[position_one];
      std::string key = key_stream.str(); 
      std::vector<std::vector<int>> moves = board.white_pawns[i].valid_moves(board);
      valid_moves_map[key] = moves;
    }
  }
  else {
   for (int i = 0; i < board.black_pieces.size(); i++) {
      // make key the piece/positon interpolation
      std::stringstream key_stream;
       int position_one = board.black_pieces[i].position[0];
      int position_two = board.black_pieces[i].position[1];
      key_stream << board.black_pieces[i].symbol << alpha_grid[position_two] << numeric_grid[position_one]; 
      std::string key = key_stream.str();

      //get valid moves and add to map;
      std::vector<std::vector<int>> moves = board.black_pieces[i].valid_moves(board);
      valid_moves_map[key] = moves;
    }
    for (int i = 0; i < board.black_pawns.size(); i++) {
      std::stringstream key_stream;
      int position_one = board.black_pawns[i].position[0];
      int position_two = board.black_pawns[i].position[1];
      key_stream << board.black_pawns[i].symbol << alpha_grid[position_two] << numeric_grid[position_one];
      std::string key = key_stream.str(); 
      std::vector<std::vector<int>> moves = board.black_pawns[i].valid_moves(board);
      valid_moves_map[key] = moves;
    }
  }

  std::map<std::string, std::vector<std::vector<int>>>::iterator it;
  //iterate over  all the pieces and convert to chess notation
  for (it = valid_moves_map.begin(); it != valid_moves_map.end(); it++) 
  { 
    
    std::string new_key = it->first;
    std::vector<std::string> moves = {};
    for (int i = 0; i < it->second.size(); i++)
    {
      int position_one = it->second[i][0];
      int position_two = it->second[i][1];

      std::string new_key = it->first;
      std::stringstream new_key_stream;
      new_key_stream << alpha_grid[position_two]<< numeric_grid[position_one];
      std::string move = new_key_stream.str();
      moves.push_back(move);
    }
    all_moves_map[new_key] = moves;
  }

  return all_moves_map;
}

std::string Player::display_moves(Board& board, std::map<std::string, std::vector<std::string>> all_moves)
{
  std::string select_piece;
  std::cout << "Select a piece by choosing a Piece with position; Example: KE1"<< std::endl;
  std::map<std::string, std::vector<std::string>>::iterator it;
  int num_it = 1;

  // displaying pieces in terminal
  for (it = all_moves.begin(); it != all_moves.end(); it++ ) 
  {
    if (it->second.size() != 0) 
    { 
      std::cout << num_it << ":" << " " << it->first << "  ";
      num_it+= 1;
    }
  }
  std::cout << std::endl;

  // taking input
  std::cin >> select_piece; 

  std::map<std::string, std::vector<std::string>>::iterator iter;

  for (iter = all_moves.begin(); iter != all_moves.end(); iter++) 
  {
    if (iter->first == select_piece) {
      return select_piece;
    } 
  }
  std::cout << "invalid" << std::endl;
  return "invalid";
}

std::vector<int> Player::select_move(Board &board, std::map<std::string, std::vector<std::string>> all_moves, std::string piece) 
{
  std::vector<int> move_coords;

  std::vector<std::string> alpha_grid = { "A", "B", "C", "D", "E", "F", "G", "H" };
  std::vector<std::string> numeric_grid = {"8", "7", "6", "5", "4", "3", "2", "1" };

  std::string move;
  std::cout << "Select a move for that piece, type cancel to go back to pieces:" << std::endl;
  for (int i = 0; i < all_moves[piece].size(); i++) 
  {
    std::cout << all_moves[piece][i] << " "; 
  }
  std::cout << std::endl;

  std::cin >> move;


  // if the move is not found in the moves arr;
  if (std::find(all_moves[piece].begin(), all_moves[piece].end(), move) == all_moves[piece].end()) {  
    // our invalid flag will be { 8, 8 };
    move_coords.push_back(9);
    move_coords.push_back(9);
  }
  
  if (move == "cancel") {
    move_coords.push_back(9);
    move_coords.push_back(9);
  }
  // converting chars to strings so that we may check for == in for loop;

  char coord_one_char = move[0];
  char coord_two_char = move[1];

  int coord_one;
  int coord_two;
  // int coord_two = coord_two_char - '0';
  std::string s_coord(1, coord_one_char);
  std::string s_coord_two(1, coord_two_char);
 
  for (int i = 0; i < alpha_grid.size(); i++) {
    if (s_coord == alpha_grid[i]) {
      coord_one = i;
    }
  }

  for (int i = 0; i < numeric_grid.size(); i++) {
    if (s_coord_two == numeric_grid[i]) {
      coord_two = i;
    }
  }

  move_coords.push_back(coord_two);
  move_coords.push_back(coord_one);
  std::cout << "Move Coord from Select Move: " << coord_one << coord_two << std::endl; 
  return move_coords;

}

bool Player::make_move(Board& board) 
{ 
  std::string player_color = color;
  std::map<std::string, std::vector<std::string>> all_moves = all_valid_moves(board);
  std::string selected_piece = display_moves(board, all_moves);
  if (selected_piece == "invalid") return false;


  // reformate select moves to take the map, reformat display moves to call itself;


  // the funtion is not completely working because the rest of the func needs to resolve from recursion
  std::vector<int> selected_move = select_move(board, all_moves, selected_piece);
  if (selected_move[0] && selected_move[1] == 9) return false;
  // std::cout << selected_move[0] << selected_move[1] << std::endl;
  std::vector<std::string> alpha_grid = { "A", "B", "C", "D", "E", "F", "G", "H" };
  std::vector<std::string> numeric_grid = { "8", "7", "6", "5", "4", "3", "2", "1" };

  char piece_symbol_c = selected_piece[0];
  std::string piece_symbol(1, piece_symbol_c);

  char coord_one_char = selected_piece[1];
  char coord_two_char = selected_piece[2];

  int coord_one;
  int coord_two;

  std::string s_coord(1, coord_one_char);
  std::string s_coord_two(1, coord_two_char);

  for (int i = 0; i < alpha_grid.size(); i++) {
    if (s_coord == alpha_grid[i]) {
      coord_one = i;
    }
  }

  for (int i = 0; i < numeric_grid.size(); i++) {
    if (s_coord_two == numeric_grid[i]) {
      coord_two = i;
    }
  }
  
  // from here we will make move with board.move_piece
  if (player_color == "white") {
    for (int i = 0; i < board.white_pieces.size(); i++) {
      if (board.white_pieces[i].symbol == piece_symbol)
        if (board.white_pieces[i].position[0] == coord_two && board.white_pieces[i].position[1] == coord_one) 
        {
          int coord_arr[2] = { selected_move[0], selected_move[1] };
          board.move_piece(board.white_pieces[i], coord_arr);
          return true;
        }
    }
    for (int i = 0; i < board.white_pawns.size(); i++) {
      if (board.white_pawns[i].position[0] == coord_two && board.white_pawns[i].position[1] == coord_one) 
      {
        int coord_arr[2] = { selected_move[0] , selected_move[1] };
        board.move_piece(board.white_pawns[i], coord_arr);
        return true;
      }
    }
  } else {
   for (int i = 0; i < board.black_pieces.size(); i++) {
      if (board.black_pieces[i].symbol == piece_symbol)
        if (board.black_pieces[i].position[0] == coord_one && board.black_pieces[i].position[1] == coord_two) 
        {
          int coord_arr[2] = { coord_two, coord_one };
          board.move_piece(board.black_pieces[i], coord_arr);
          return true;
        }
    }
    for (int i = 0; i < board.black_pawns.size(); i++) {
      if (board.black_pawns[i].position[0] == coord_one && board.black_pawns[i].position[1] == coord_two) 
      {
        int coord_arr[2] = { coord_one, coord_two };
        board.move_piece(board.black_pawns[i], coord_arr);
        return true;
      }
    }
  }
  return false;
}
