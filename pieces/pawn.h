#ifndef _PAWN_
#define _PAWN_
#include "piece.h"

class PawnPiece : public Piece 
{

  public:
    PawnPiece(int posX, int posY, std::string add_color, std::string add_symbol);
    bool on_starting_row;
};

#endif
