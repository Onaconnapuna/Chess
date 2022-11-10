#ifndef _PIECE_
#define _PIECE_
#include <string>
using namespace std;

class Piece {

  public: 
    string value;

    Piece();
    void add_value(Piece& piece, string value);

};

#endif 
