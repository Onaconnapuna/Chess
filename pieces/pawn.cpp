#include "pawn.h"
#include <string>

PawnPiece::PawnPiece(int posX, int posY, std::string add_color, std::string add_symbol) : Piece(posX, posY) {
  value = "pawn";
  symbol = add_symbol;
  color = add_color;
  slideable = false;
  deltas = { { 1, 0 }, {2, 0}, { 1, -1 }, { 1, 1} };
  on_starting_row = false;
}