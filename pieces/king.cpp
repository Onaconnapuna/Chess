#include "king.h"
#include <string>

KingPiece::KingPiece(int posX, int posY, std::string add_color, std::string add_symbol) : Piece(posX, posY) {
  value = "king";
  symbol = add_symbol;
  color = add_color;
  slideable = false;
  deltas = { { 1, 1 }, { 1 , -1}, { -1, 1 }, { -1, -1 }, { 1, 0 }, { -1, 0 }, { 0, -1}, { 0, 1} };
}