#include <string>
// #include "null_piece.h"
using namespace std;

class Piece {

  public: 

  string value;

  Piece() {
    value = "placeholder";
  };
  void add_value(Piece& piece,string value) {
    piece.value = value;
  };

}; 

class NullPiece : public Piece 
{

  public:
  NullPiece() {
    value = "null-piece";
  };

};
