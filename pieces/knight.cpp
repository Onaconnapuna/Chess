#include "knight.h"
#include <string>

KnightPiece::KnightPiece(int posX, int posY, std::string add_color, std::string add_symbol) : Piece(posX, posY) {
  value = "knight";
  symbol = add_symbol;
  color = add_color;
  slideable = false;
  deltas = { { -2, 1 }, { -2, -1 }, { 2, -1 }, { 2, 1 }, { 1 , 2}, { 1, -2 }, { -1, 2 }, {-1, -2 } };
}