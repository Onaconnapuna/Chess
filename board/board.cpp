#include <iostream>
#include "board.h" 
#include <vector>
using namespace std;

void Board::create_board() {

  std::vector<std::vector<Piece> > two_D_vector(8);

  RookPiece rook_three(7, 0, "white", "R");
  RookPiece rook_four(7, 7, "white", "R");
  KnightPiece knight_three(7, 1, "white", "N");
  KnightPiece knight_four(7, 6, "white", "N");
  BishopPiece bishop_three(7, 2, "white", "B");
  BishopPiece bishop_four(7, 5, "white", "B");
  KingPiece white_king(7, 3, "white", "K");
  QueenPiece white_queen(7, 4, "white", "Q");

  std::vector<Piece> white_pieces = {rook_three, knight_three, bishop_three, white_queen, white_king, bishop_four, knight_four, rook_four};

  RookPiece rook_one(0, 0, "black", "r");
  RookPiece rook_two(0, 7, "black", "r");
  KnightPiece knight_one(0, 1, "black", "n");
  KnightPiece knight_two(0, 6, "black", "n");
  BishopPiece bishop_one(0, 2, "black", "b");
  BishopPiece bishop_two(0, 5, "black", "b");
  KingPiece black_king(0, 3, "black", "k");
  QueenPiece black_queen(0, 4, "black", "q");
  

  std::vector<Piece> black_pieces = {rook_one, knight_one, bishop_one, black_queen, black_king, bishop_two, knight_two, rook_two};


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
  for (int i = 0; i < grid.size(); i++) {
    std::cout << i;
    for (int j = 0; j < grid[i].size(); j++) {
      std::cout << " " << grid[i][j].symbol << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "  ";
  for (int i = 0; i < 8; i++) {
    std:: cout << i << "  ";
  }
  std::cout << std::endl;
}

bool Board::move_piece(int start_pos[2], int end_pos[2]) {
  int start_x = start_pos[0];
  int start_y = start_pos[1];

  if (grid[start_x][start_y].value == "empty_space") return false;

  int end_x = end_pos[0];
  int end_y = end_pos[1];

  if (grid[end_x][end_y].value == "placeholder") return false;

  grid[end_x][end_y] = grid[start_x][start_y];

  NullPiece null_piece(start_x, start_y);

  grid[start_x][start_y] = null_piece;
  return true;
}

bool Board::in_check(Piece& king) {

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {

    }
  }

}