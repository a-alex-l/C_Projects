#pragma once

const int FISIZE = 10;

enum data {
    X = 1,
    O = -1,
    NoOne = 0
};

class Board {
public:
    data field[FISIZE][FISIZE];

    Board();

    bool can_move(int x, int y);

    void move(int x, int y, data sign);

    data get_state(int x, int y);

private:
    int test(int x, int y, int plusx, int plusy);
};
