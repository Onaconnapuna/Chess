#include <vector>
#include "../pieces/piece.h"
#include "../pieces/null_piece.h"
using namespace std;

class Board {

  public: 

    vector<vector<Piece>> grid;

    void create_board();
    void place_pieces(Board &board);

};