#include <iostream>
#include <vector>
#include <algorithm>
#include "board.h" 

Board::Board() {
  std::vector<std::vector<Piece> > two_D_vector(8);

  RookPiece rook_three(7, 0, "white", "R");
  RookPiece rook_four(7, 7, "white", "R");
  KnightPiece knight_three(7, 1, "white", "N");
  KnightPiece knight_four(7, 6, "white", "N");
  BishopPiece bishop_three(7, 2, "white", "B");
  BishopPiece bishop_four(7, 5, "white", "B");
  KingPiece white_king(7, 4, "white", "K"); 
  QueenPiece white_queen(7, 3, "white", "Q");

  white_pieces = {rook_three, knight_three, bishop_three, white_queen, white_king, bishop_four, knight_four, rook_four};

  RookPiece rook_one(0, 0, "black", "r");
  RookPiece rook_two(0, 7, "black", "r");
  KnightPiece knight_one(0, 1, "black", "n");
  KnightPiece knight_two(0, 6, "black", "n");
  BishopPiece bishop_one(0, 2, "black", "b");
  BishopPiece bishop_two(0, 5, "black", "b");
  KingPiece black_king(0, 4, "black", "k");
  QueenPiece black_queen(0, 3, "black", "q");
  

  black_pieces = {rook_one, knight_one, bishop_one, black_queen, black_king, bishop_two, knight_two, rook_two};
 

  for (int i = 0; i < 8; i++) {
    if (i == 0) two_D_vector[i] = black_pieces;
    if (i == 7) two_D_vector[i] = white_pieces;

    if (i == 1 ) {
      for (int j = 0; j < 8; j++) {
        PawnPiece pawn(i, j, "black", "p");
        two_D_vector[i].push_back(pawn);
      } 
    }

    if (i == 6) {
      for (int j = 0; j < 8; j++) {
        PawnPiece pawn(i, j, "white", "P");
        two_D_vector[i].push_back(pawn);
      } 
    }

    if (i > 1 && i < 6) { 
      for (int j = 0; j < 8; j++) { 
        NullPiece null_piece(i, j);
        two_D_vector[i].push_back(null_piece);
      }
    }  
  }

  grid = two_D_vector;
}




void Board::print_board() {
  std::vector<std::string> alpha = { "A", "B", "C", "D", "E", "F", "G", "H" };
  std::vector<int> nums = { 8, 7, 6, 5, 4, 3, 2, 1};
  for (int i = 0; i < grid.size(); i++) {
    std::cout << nums[i];
    for (int j = 0; j < grid[i].size(); j++) {
      std::cout << " " << grid[i][j].symbol << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "  ";
  for (int i = 0; i < 8; i++) {
    std:: cout << alpha[i] << "  ";
  }
  std::cout << std::endl;
}

bool Board::move_piece(Piece& piece, int end_pos[2]) {
  int start_x = piece.position[0];
  int start_y = piece.position[1];
  std::string color = piece.color;

  if (grid[start_x][start_y].value == "empty_space") return false;

  int end_x = end_pos[0];
  int end_y = end_pos[1];

  std::string end_color = grid[end_x][end_y].color;

  if (grid[end_x][end_y].value == "placeholder") return false;
  if (grid[end_x][end_y].color == color) return false;

  piece.position[0] = end_x;
  piece.position[1] = end_y;

  grid[end_x][end_y] = piece;

  if (color == "white") { 
    // changing the position of the piece within the white pieces array
    for (int i = 0; i < white_pieces.size(); i++) {
      if (white_pieces[i].position[0] == start_x && white_pieces[i].position[1] == start_y) { 
        white_pieces[i].position[0] = end_x;
        white_pieces[i].position[1] = end_y;
      }
      if (end_color == "black") {
        // if end pos was opposite piece, deleting piece from the opposite color pieces array
        for (int i = 0; i < black_pieces.size(); i++) {
          if (black_pieces[i].position[0] == end_x && black_pieces[i].position[1] == end_y) {
            black_pieces.erase(black_pieces.begin() + i);
          }
        } 
      } 
    } 
  } else if (color == "black") {
      for (int i = 0; i < black_pieces.size(); i++) {
        if (black_pieces[i].position[0] == start_x && black_pieces[i].position[1] == start_y) { 
          black_pieces[i].position[0] = end_x;
          black_pieces[i].position[1] = end_y;
        }
        if (end_color == "white") {
          for (int i = 0; i < white_pieces.size(); i++) {
            if (white_pieces[i].position[0] == end_x && white_pieces[i].position[1] == end_y) {
              white_pieces.erase(black_pieces.begin() + i);
            }
          } 
        } 
      } 
    } 

  NullPiece null_piece(start_x, start_y);

  grid[start_x][start_y] = null_piece;
  return true;
}

bool Board::in_check(Piece& king) {
  std::string color = king.color;
  std::vector<std::vector<int>> valid_moves;

  if (color == "white") {
    for (int i = 0; i < this->black_pieces.size(); i++) {

      if (this->black_pieces[i].slideable == true) {
        valid_moves = this->black_pieces[i].valid_moves(*this);
      }
       for (int i = 0; i < valid_moves.size(); i++) {
        if (valid_moves[i][0] == king.position[0] && valid_moves[i][1] == king.position[1]) return true;
      }
      valid_moves.clear();
    }
  } else {
    for (int i = 0; i < this->white_pieces.size(); i++) {
      if (this->black_pieces[i].slideable == true) {
      valid_moves = this->white_pieces[i].valid_moves(*this);
      }
      for (int i = 0; i < valid_moves.size(); i++) {
        if (valid_moves[i][0] == king.position[0] && valid_moves[i][1] == king.position[1]) return true;
      }
      valid_moves.clear();
    }
  }

  return false;
}


bool Board::checkmate(Piece& king) {
  // find all valid moves for the king
  // if there are no valid squares, 
  // somehow find a way to see if any of same color pieces can block,
  // if thats not possible, return true;
  std::string color = king.color;
  std::vector<std::vector<int>> king_moves;
  king_moves = king.valid_moves(*this);
  // for (int i = 0; i < king_moves.size(); i++) {
  //     std::cout << king_moves[i][0] << king_moves[i][1] << std::endl;
  // }

  std::vector<std::vector<int>> invalid_squares;
  std::vector<int> pos = { 5, 5 };
  invalid_squares.push_back(pos);
  std::vector<std::vector<int>> moves;

  if (color == "white") {
    // iterate over the black pieces vector 
    for (int i = 0; i < this->black_pieces.size(); i++) {
      if (this->black_pieces[i].slideable == true) {
        moves = this->black_pieces[i].slideable_squares(*this);
      } else { 
        moves = this->black_pieces[i].valid_moves(*this);
      }
      // adding all valid moves from blacks pieces to invalid squares for white
      invalid_squares.insert(std::end(invalid_squares), std::begin(moves), std::end(moves));
    }
    for (int i = 0; i < invalid_squares.size(); i++) {
      std::cout << invalid_squares[i][0] << invalid_squares[i][1] << std::endl;
    }
    // now iterate over kings moves to see if all moves are included in invalid squares
    for (int i = 0; i < king_moves.size(); i++) {
      // if any move of kings is not included in invalid squares, king must not be in checkmate 
      if (std::find(invalid_squares.begin(), invalid_squares.end(), king_moves[i]) == invalid_squares.end() ) {
        return false;
      } 
    }
      return true;
  } else {
    for (int i = 0; i < this->white_pieces.size(); i++) {
      if (this->white_pieces[i].slideable == true) {
        moves = this->white_pieces[i].slideable_squares(*this);
      } else {
        moves = this->white_pieces[i].valid_moves(*this);
      }
      // adding all valid moves from white pieces to invalid squares for white
      invalid_squares.insert(std::end(invalid_squares), std::begin(moves), std::end(moves));
    }
    // now iterate over kings moves to see if all moves are included in invalid squares
    for (int i = 0; i < king_moves.size(); i++) {
      // if any move of kings is not included in invalid squares, king must not be in checkmate 
      if (std::find(invalid_squares.begin(), invalid_squares.end(), king_moves[i]) == invalid_squares.end() ) {
        return false;
      } 
    }
    return true;
  }
} 