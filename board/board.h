#include <vector>
#include "../pieces/piece.h"
using namespace std;

class Board {

  public: 

  vector<vector<Piece>> grid;

  void create_board();

};