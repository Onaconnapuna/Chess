#ifndef _PLAYER_
#define _PLAYER_
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "../board/board.h"
class Board;

class Player {

  public:

    std::string color;
    Player(std::string new_color);
    std::map<std::string, std::vector<std::string>> all_valid_moves(Board& board);
    std::string display_moves(Board &board, std::map<std::string, std::vector<std::string>> all_moves);
    std::vector<int> select_move(Board &board);
    // void make_move(std::map<std::string, std::vector<std::vector<std::string>>> moves, Board& board);

};

#endif