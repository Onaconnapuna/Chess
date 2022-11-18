#include "null_piece.h"
#include <string>
NullPiece::NullPiece(int posX, int posY) : Piece(posX, posY) {
  value = "empty_space";
  color = "null_color";
  symbol = " ";
}