#include <vector>
#include "../pieces/piece.cpp"
using namespace std;

class Board {

  public: 

    vector<vector<Piece>> grid;

    void create_board();
    void place_pieces(Board& board);
    void print_board(Board& board);

};