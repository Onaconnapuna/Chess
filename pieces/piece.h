#ifndef _PIECE_
#define _PIECE_
#include <string>
#include <vector>
using namespace std;

class Piece {

  public: 
    string value;
    string color;
    std::vector<int> position;

    Piece(int posX, int posY, std::string value = "placeholder", std::string color = "whiteblack");
    void add_value(Piece& piece, string value);

};

#endif 
