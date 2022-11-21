#ifndef _KING_
#define _KING_
#include "piece.h"

class KingPiece : public Piece 
{

  public:
    KingPiece(int posX, int posY, std::string add_color, std::string add_symbol);

};

#endif
