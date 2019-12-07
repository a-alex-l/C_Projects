#include <iostream>
#include "StdioBoardView.hpp"
#include "BoardTest.hpp"

using namespace std;


int main() {
    BoardTest test;
    test.run_all_tests();
    test.show_final_result();

    StdioBoardView game;
    game.do_game_cycle();
}
