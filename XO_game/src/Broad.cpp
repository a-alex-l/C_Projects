#include "Board.hpp"

Board::Board() {
    for (int i = 0; i < FISIZE; i++)
        for (int j = 0; j < FISIZE; j++)
            field[i][j] = NoOne;
}

bool Board::can_move(int x, int y) {
    return 0 <= x && x < FISIZE && 0 <= y && y < FISIZE && field[x][y] == NoOne;
}

void Board::move(int x, int y, data sign) {
    field[x][y] = sign;
}

data Board::get_state(int x, int y) {
    bool winner = false;
    winner |= 3 < test(x, y, 1, 1) + test(x, y, -1, -1);
    winner |= 3 < test(x, y, -1, 1) + test(x, y, 1, -1);
    winner |= 3 < test(x, y, 1, 0)  + test(x, y, -1, 0);
    winner |= 3 < test(x, y, 0, 1)  + test(x, y, 0, -1);
    if (winner)
        return field[x][y];
    else
        return NoOne;
}

int Board::test(int x, int y, int plusx, int plusy) {
    int ans = 0;
    for (int i = 1; i <= 4; i++)
        if (0 <= x + i * plusx && x + i * plusx < FISIZE &&
            0 <= y + i * plusy && y + i * plusy < FISIZE &&
            field[x + i * plusx][y + i * plusy] == field[x][y])
            ans++;
        else break;
    return ans;
}
