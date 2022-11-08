#include "board.h" 
#include "../pieces/piece.h"
#include <vector>
using namespace std;

void Board::create_board() 
{
  // initialize an empty 2D vector
  // vector<vector<int>> two_D_grid;

  // initialize empty 1D vector
  // vector<Piece> one_D_grid(8, Piece);

  // add 8 rows of the 1D vector into the empty 2D
  // for (int i = 0; i < 8; i++) {
  //   two_D_grid.push_back(one_D_grid);
  // }

  vector<vector<int> > two_D_vector(8, vector<int>(8));

  grid = two_D_vector;
}