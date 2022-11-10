#include <iostream>
#include "board.h" 
#include <vector>
using namespace std;

void Board::create_board() 
{
  // initialize the 2D vector with type Piece with 8 vectors
  vector<vector<Piece> > two_D_vector(8, vector<Piece>(8));

  // assign 2d vector to grid
  grid = two_D_vector;
}

void Board::place_pieces(Board& board) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i > 1 && i < 6) {  
        NullPiece null_piece;
        board.grid[i][j] = null_piece;
      }  
    }
  }
}

void Board::print_board(Board& board) {
  for (int i = 0; i < board.grid.size(); i++) {
    for (int j = 0; j < board.grid[i].size(); j++) {
      std::cout << board.grid[i][j].value << " ";
    }
    std::cout << std::endl;
  }
}

bool Board::move_piece(Board& board, int start_pos[2], int end_pos[2]) {
  int start_x = start_pos[0];
  int start_y = start_pos[1];

  if (board.grid[start_x][start_y].value == "null-piece") return false;

  int end_x = end_pos[0];
  int end_y = end_pos[1];

  if (board.grid[end_x][end_y].value == "placeholder") return false;

  board.grid[end_x][end_y] = board.grid[start_x][start_y];

  NullPiece null_piece;

  board.grid[start_x][start_y] = null_piece;
  return true;
}