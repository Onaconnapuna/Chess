#include <string>
#include "piece.h"
#include <vector>

Piece::Piece(int posX, int posY, std::string value, std::string color) {
  value = value;
  color = color;
  position = { posX, posY };
}

void Piece::add_value(Piece& piece, std::string value) {
  piece.value = value;
}
