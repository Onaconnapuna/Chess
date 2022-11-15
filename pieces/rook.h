#include "piece.h"

class RookPiece : public Piece 
{

  public:
  
  // std::vector<std::vector<int> > deltas = { {-1, 0}, {0, 1}, {1, 0}, {-1, 0} };
  RookPiece(int posX, int posY, std::string color);

};
