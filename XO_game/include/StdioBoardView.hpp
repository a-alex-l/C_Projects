#pragma once

#include "Board.hpp"

class StdioBoardView {
private:
    Board field;

public:
    void do_game_cycle();

private:
    void take_turn(int &x, int &y, data player);

    void print_board();

};
