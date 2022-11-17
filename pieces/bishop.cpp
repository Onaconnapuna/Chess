#include "bishop.h"
#include <string>

BishopPiece::BishopPiece(int posX, int posY, std::string add_color) : Piece(posX, posY) {
  value = "bishop";
  slideable = true;
  color = add_color;
  deltas = { { -1, 1 }, { 1, 1 }, { -1, -1 }, { 1, -1 } };
}