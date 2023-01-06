#ifndef _PAWN_
#define _PAWN_
#include "piece.h"
#include "../board/board.h"

class PawnPiece : public Piece 
{
  public:
    std::vector<std::vector<int>> forward_deltas;
    std::vector<std::vector<int>> capturing_deltas;

    PawnPiece(int posX, int posY, std::string add_color, std::string add_symbol);
    std::vector<std::vector<int>> valid_movesP(Board& board);
    bool on_starting_row();
    
  private:
    int forward_dir;
};

#endif
