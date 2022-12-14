#ifndef _BOARD_
#define _BOARD_
#include <vector>
#include <memory>
#include <boost/any.hpp>
#include "boost/any.hpp"
#include "../pieces/piece.h"
#include "../pieces/null_piece.h"
#include "../pieces/rook.h"
#include "../pieces/bishop.h"
#include "../pieces/knight.h"
#include "../pieces/queen.h"
#include "../pieces/king.h"
#include "../pieces/pawn.h"
class Piece;
class PawnPiece;

class Board {

  public: 
    std::vector<std::vector<Piece>> grid;
    std::vector<Piece> white_pieces;
    std::vector<Piece> black_pieces;
    std::vector<PawnPiece> white_pawns;
    std::vector<PawnPiece> black_pawns;

    Board();
    Board(const Board& other);
    // Board& operator=(const Board& rhs);
    void print_board();
    bool move_piece(Piece& piece, int end_pos[2]);
    bool in_check(Piece& king);
    bool checkmate(Piece& king);

};

#endif