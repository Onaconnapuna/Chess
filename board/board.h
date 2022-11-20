#ifndef _BOARD_
#define _BOARD_
#include <vector>
#include "../pieces/piece.h"
#include "../pieces/null_piece.h"
#include "../pieces/rook.h"
#include "../pieces/bishop.h"
#include "../pieces/knight.h"
#include "../pieces/queen.h"
#include "../pieces/king.h"
#include "../pieces/pawn.h"

class Board {

  public: 

    std::vector<std::vector<Piece>> grid;

    void create_board();
    void print_board();
    bool move_piece(int start_pos[2], int end_pos[2]);
    bool in_check(Piece& king);

};

#endif