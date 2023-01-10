#include <iostream>
#include <vector>
#include <algorithm>
#include "board.h" 
#include <boost/any.hpp>

Board::Board() {
  // std::vector<std::vector<std::unique_ptr<Piece>>> two_D_vector(8);
  std::vector<std::vector<Piece>> two_D_vector(8);

  RookPiece rook_three(7, 0, "white", "R");
  RookPiece rook_four(7, 7, "white", "R");
  KnightPiece knight_three(7, 1, "white", "N");
  KnightPiece knight_four(7, 6, "white", "N");
  BishopPiece bishop_three(7, 2, "white", "B");
  BishopPiece bishop_four(7, 5, "white", "B");
  KingPiece white_king(7, 4, "white", "K"); 
  QueenPiece white_queen(7, 3, "white", "Q");

  // RookPiece* rook_three = new RookPiece (7, 0, "white", "R");
  // RookPiece* rook_four = new RookPiece (7, 7, "white", "R");
  // KnightPiece* knight_three = new KnightPiece (7, 1, "white", "N");
  // KnightPiece* knight_four = new KnightPiece (7, 6, "white", "N");
  // BishopPiece* bishop_three = new BishopPiece(7, 2, "white", "B");
  // BishopPiece* bishop_four = new BishopPiece (7, 5, "white", "B");
  // KingPiece* white_king = new KingPiece (7, 4, "white", "K"); 
  // QueenPiece* white_queen = new QueenPiece(7, 3, "white", "Q");


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
  
  two_D_vector[0] = black_pieces;
  two_D_vector[7] = white_pieces;

  for (int i = 1; i < 7; i++) {

    if (i == 1 ) {
      for (int x = 0; x < 8; x++) {
        PawnPiece pawn(1, x, "black", "p");
        two_D_vector[1].push_back(pawn);
        black_pawns.push_back(pawn);
      } 
    }

    if (i == 6) {
      for (int y = 0; y < 8; y++) {
        PawnPiece pawn(6, y, "white", "P");
        two_D_vector[6].push_back(pawn);
        white_pawns.push_back(pawn);
      } 
    }


    if (i > 1 && i < 6) { 
      for (int k = 0; k < 8; k++) { 
        NullPiece null_piece(i, k);
        two_D_vector[i].push_back(null_piece);
      }
    }  
    
  }
  grid = two_D_vector;
}

Board::Board(const Board& other) 
  : grid(other.grid), white_pieces(other.white_pieces), white_pawns(other.white_pawns), black_pieces(other.black_pieces), black_pawns(other.black_pawns)
{

}




void Board::print_board() {
  std::vector<std::string> alpha = { "A", "B", "C", "D", "E", "F", "G", "H" };
  std::vector<int> nums = { 8, 7, 6, 5, 4, 3, 2, 1};
  for (int i = 0; i < 8; i++) {
    std::cout << nums[i];
    for (int j = 0; j < grid[i].size(); j++) {
      std::cout << "  " << grid[i][j].symbol << "  ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }

  std::cout << "   ";
  for (int i = 0; i < 8; i++) {
    std:: cout << alpha[i] << "    ";
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
    for (int i = 0; i < black_pieces.size(); i++) {

      if (black_pieces[i].slideable == true) {
        valid_moves = black_pieces[i].valid_moves(*this);
      }
       for (int i = 0; i < valid_moves.size(); i++) {
        if (valid_moves[i][0] == king.position[0] && valid_moves[i][1] == king.position[1]) return true;
      }
      valid_moves.clear();
    }
  } else {
    for (int i = 0; i < white_pieces.size(); i++) {
      if (black_pieces[i].slideable == true) {
      valid_moves = white_pieces[i].valid_moves(*this);
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
  Board board_copy(*this);
  bool zero_moves = true;
  // find all valid moves for the king
  // if there are no valid squares, 
  // somehow find a way to see if any of same color pieces can block,
  // if thats not possible, return true;
  // std::string color = king.color;
  std::vector<std::vector<int>> king_moves;
  int king_startX = king.position[0];
  int king_startY = king.position[1];
  king_moves = king.valid_moves(*this);
  for (int i = 0; i < king_moves.size(); i++) {
    // std::cout << king_moves[i][0] << king_moves[i][1] << std::endl;
    int king_x = king_moves[i][0];
    int king_y = king_moves[i][1];
    int king_moves[2] = { king_x, king_y };
    board_copy.move_piece(king, king_moves);
    if (!board_copy.in_check(king)) zero_moves = false;
  }
    // move king back to original position;
    int king_start[2] = { king_startX, king_startY };
    board_copy.move_piece(king, king_start);
  // bool zero_moves = true; 
  // std::vector<std::vector<int>> invalid_squares;
  // std::vector<std::vector<int>> moves;
  // std::vector<std::vector<int>> escape_moves; 

  // if (color == "white") {
  //   // iterate over the black pieces vector 
  //   for (int i = 0; i < black_pieces.size(); i++) {
  //     if (black_pieces[i].slideable == true) {
  //       moves = black_pieces[i].slideable_squares(*this);
  //     } else { 
  //       moves = black_pieces[i].valid_moves(*this);
  //     }
  //     // adding all valid moves from blacks pieces to invalid squares for white
  //     invalid_squares.insert(std::end(invalid_squares), std::begin(moves), std::end(moves));
  //   }
  //   // for (int i = 0; i < invalid_squares.size(); i++) {
  //   //   std::cout << invalid_squares[i][0] << invalid_squares[i][1] << std::endl;
  //   // }
  //   // now iterate over kings moves to see if all moves are included in invalid squares
  //   for (int j = 0; j < king_moves.size(); j++) {
  //     // if any move of kings is not included in invalid squares, king must not be in checkmate 
  //     if (std::find(invalid_squares.begin(), invalid_squares.end(), king_moves[j]) == invalid_squares.end() ) {
  //       // zero_moves = false;
      
  //       // std::cout << "found move" << std::endl;
  //       escape_moves.push_back(king_moves[j]);
  //     } 
  //   }
  // } else {
  //   for (int i = 0; i < white_pieces.size(); i++) {
  //     if (white_pieces[i].slideable == true) {
  //       moves = white_pieces[i].slideable_squares(*this);
  //     } else {
  //       moves = white_pieces[i].valid_moves(*this);
  //     }
  //     // adding all valid moves from white pieces to invalid squares for white
  //     invalid_squares.insert(std::end(invalid_squares), std::begin(moves), std::end(moves));
  //   }
  //   // now iterate over kings moves to see if all moves are included in invalid squares
  //   for (int j = 0; j < king_moves.size(); j++) {
  //     // if any move of kings is not included in invalid squares, king must not be in checkmate 
  //     if (std::find(invalid_squares.begin(), invalid_squares.end(), king_moves[j]) == invalid_squares.end() ) {
  //       escape_moves.push_back(king_moves[j]);
  //     } 
  //   }
   
  // }

  // std::cout << escape_moves[0][0] << escape_moves[0][1] << std::endl;
  std::vector<std::vector<int>> blocking_moves = king.moves_out_of_check(*this);
  // std::cout << zero_moves << " " << blocking_moves.size() << std::endl;
  // for (int k = 0; k < blocking_moves.size(); k++) {
  //     std::cout << blocking_moves[k][0] << blocking_moves[k][1] << std::endl;
  //   }
  // std::cout << escape_moves.size() << std::endl;
  // std::cout << blocking_moves.size() << std::endl;
  // std::cout << zero_moves << std::endl; 
   if (zero_moves == true && blocking_moves.size() == 0) {
      return true;
   } else {
      return false;
   }

} 