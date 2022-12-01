#ifndef _PLAYER_
#define _PLAYER_
#include <string>

class Player {

  public:

    std::string color = "null_color";
    // Player(std::string add_color);
    void add_color(Player& player, std::string new_color);

};

#endif