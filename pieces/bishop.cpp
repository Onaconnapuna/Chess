#include "bishop.h"
#include <string>

BishopPiece::BishopPiece(int posX, int posY, std::string add_color, std::string add_symbol) : Piece(posX, posY) {
  value = "bishop";
  symbol = add_symbol;
  slideable = true;
  color = add_color;
  deltas = { { -1, 1 }, { 1, 1 }, { -1, -1 }, { 1, -1 } };
}