#include <string>
#include "piece.h"
#include <vector>
#include <string>

Piece::Piece(int posX, int posY) {
  position = { posX, posY };
}

void Piece::add_value(std::string value) {
  value = value;
}

std::string Piece::get_value() {
  return value;
}