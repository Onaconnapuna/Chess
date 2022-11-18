#ifndef _QUEEN_
#define _QUEEN_
#include "piece.h"

class QueenPiece : public Piece 
{

  public:
  QueenPiece(int posX, int posY, std::string add_color, std::string add_symbol);

};

#endif
