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
        // NullPiece piece;
        Piece piece;
        piece.add_value("nil-square");
        board.grid[i][j] = piece;
      }  
    }
  }
}