#include "queen.h"
#include <string>

QueenPiece::QueenPiece(int posX, int posY, std::string add_color, std::string add_symbol) : Piece(posX, posY) {
  value = "queen";
  symbol = add_symbol;
  color = add_color;
  slideable = true;
  deltas = { {-1, 0}, {0, 1}, {1, 0}, {0, -1},{ -1, 1 }, { 1, 1 }, { -1, -1 }, { 1, -1 } };
}