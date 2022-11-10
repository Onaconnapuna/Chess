#include <string>
#include "piece.h"
using namespace std;

Piece::Piece() {
  value = "placeholder";
}

void Piece::add_value(Piece& piece, string value) {
  piece.value = value;
}
