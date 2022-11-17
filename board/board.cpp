#include <iostream>
#include "board.h" 
#include <vector>
using namespace std;

void Board::create_board() {

  std::vector<std::vector<Piece> > two_D_vector(8);

  RookPiece rook_three(0, 0, "white");
  RookPiece rook_four(0, 7, "white");
  KnightPiece knight_three(0, 1, "white");
  KnightPiece knight_four(0, 6, "white");
  BishopPiece bishop_three(0, 2, "white");
  BishopPiece bishop_four(0, 5, "white");
  KingPiece white_king(0, 3, "white");
  QueenPiece white_queen(0, 4, "white");

  std::vector<Piece> white_pieces = {rook_three, knight_three, bishop_three, white_queen, white_king, bishop_four, knight_four, rook_four};

  RookPiece rook_one(0, 0, "black");
  RookPiece rook_two(0, 7, "black");
  KnightPiece knight_one(0, 1, "black");
  KnightPiece knight_two(0, 6, "black");
  BishopPiece bishop_one(0, 2, "black");
  BishopPiece bishop_two(0, 5, "black");
  KingPiece black_king(0, 3, "black");
  QueenPiece black_queen(0, 4, "black");
  

  std::vector<Piece> black_pieces = {rook_one, knight_one, bishop_one, black_queen, black_king, bishop_two, knight_two, rook_two};


  for (int i = 0; i < 8; i++) {
    if (i == 0) two_D_vector[i] = black_pieces;
    if (i == 7) two_D_vector[i] = white_pieces;

    if (i == 1 ) {
      for (int j = 0; j < 8; j++) {
        PawnPiece pawn(i, j, "black");
        two_D_vector[i].push_back(pawn);
      } 
    }

    if (i == 6) {
      for (int j = 0; j < 8; j++) {
        PawnPiece pawn(i, j, "white");
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
    for (int j = 0; j < grid[i].size(); j++) {
      std::cout << grid[i][j].value << " ";
    }
    std::cout << std::endl;
  }
}

bool Board::move_piece(Board& board, int start_pos[2], int end_pos[2]) {
  int start_x = start_pos[0];
  int start_y = start_pos[1];

  if (board.grid[start_x][start_y].value == "empty_space") return false;

  int end_x = end_pos[0];
  int end_y = end_pos[1];

  if (board.grid[end_x][end_y].value == "placeholder") return false;

  board.grid[end_x][end_y] = board.grid[start_x][start_y];

  NullPiece null_piece(start_x, start_y);

  board.grid[start_x][start_y] = null_piece;
  return true;
}