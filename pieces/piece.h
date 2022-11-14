#ifndef _PIECE_
#define _PIECE_
#include <string>
#include <vector>

class Piece {

  public: 
    std::string value = "placeholder";
    std:: string color = "white/black";
    std::vector<int> position;

    Piece(int posX, int posY);


    void add_value(std::string value);
    std::string get_value();

};

#endif 
