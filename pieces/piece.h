#ifndef _PIECE_
#define _PIECE_
#include <string>
#include <vector>
class Board;

class Piece {

  public: 
    bool slideable = false;
    std::string value = "placeholder";
    std::string color = "white/black";
    std::string symbol;
    std::vector<int> position;
    std::vector<std::vector<int> > deltas;

    Piece(int posX, int posY);
    // Piece(const Piece& other);
    void add_value(std::string value);
    std::string get_value();
    virtual std::vector<std::vector<int> > valid_moves(Board& board);
    std::vector<std::vector<int> > slideable_squares(Board& board);
    std::vector<std::vector<int>> moves_out_of_check(Board& board);  
    
  private:

    std::vector<std::vector<int> > slideable_moves(Board& board);
    std::vector<std::vector<int> > stepable_moves(Board& board);

};

#endif 
 