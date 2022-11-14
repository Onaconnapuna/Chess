#include <vector>
#include "../pieces/piece.h"
#include "../pieces/null_piece.h"
using namespace std;

class Board {

  public: 

    vector<vector<Piece>> grid;

    void create_board();
    void place_pieces();
    void print_board();
    bool move_piece(Board& board, int start_pos[2], int end_pos[2]);

};