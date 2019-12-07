
#include <iostream>
#include "StdioBoardView.hpp"

void StdioBoardView::do_game_cycle() {
    int x, y;
    data player = X;
    for (int step = 1; step <= 100; step++) {
        print_board();
        take_turn(x, y, player);
        if (player == X) player = O;
        else player = X;
        if (field.get_state(x, y) != NoOne) break;
    }
    if (field.get_state(x, y) == X)      std::cout << "X wins!\n";
    if (field.get_state(x, y) == O)      std::cout << "O wins!\n";
    if (field.get_state(x, y) == NoOne)  std::cout << "Draw.\n";
}

void StdioBoardView::take_turn(int &x, int &y, data player) {
    if (player == X) std::cout << "X move: ";
    else std::cout << "O move: ";
    std::cin >> x >> y;
    if (field.can_move(x, y))
        field.move(x, y, player);
    else {
        std::cout << "Bad move!\n";
        take_turn(x, y, player);
    }
}

void StdioBoardView::print_board() {
    std::cout << "\n";
    for (int i = 0; i < FISIZE; i++) {
        for (int j = 0; j < FISIZE; j++) {
            if (field.field[i][j] == X) std::cout << "X";
            if (field.field[i][j] == O) std::cout << "O";
            if (field.field[i][j] == NoOne) std::cout << ".";
        }
        std::cout << "\n";
    }
}
