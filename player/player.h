#ifndef _PLAYER_
#define _PLAYER_
#include <string>

class Player {

  public:

    std::string color;
    Player(std::string new_color);
    void make_move();

};

#endif