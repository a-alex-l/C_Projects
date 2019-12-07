
#include "BoardTest.hpp"

void BoardTest::test_get_state_horizontal() {
    Board b;
    b.move(0, 0, X); // XXXXX.....
    b.move(0, 1, X); // ..........
    b.move(0, 2, X); // ..........
    b.move(0, 3, X); // ..........
    b.move(0, 4, X); // ..........
    DO_CHECK(b.get_state(0, 4) == X);
    DO_CHECK(b.get_state(0, 3) == X);
    DO_CHECK(b.get_state(0, 2) == X);
    DO_CHECK(b.get_state(0, 1) == X);
    DO_CHECK(b.get_state(0, 0) == X);
}

void BoardTest::test_get_state_main_diagonal() {
    Board b = *(new Board());
    b.move(0, 0, X); // X.........
    b.move(1, 1, X); // .X........
    b.move(2, 2, X); // ..X.......
    b.move(3, 3, X); // ...X......
    b.move(4, 4, X); // ....X.....
                     // ..........
    DO_CHECK(b.get_state(4, 4) == X);
    DO_CHECK(b.get_state(3, 3) == X);
    DO_CHECK(b.get_state(2, 2) == X);
    DO_CHECK(b.get_state(1, 1) == X);
    DO_CHECK(b.get_state(0, 0) == X);
}

void BoardTest::test_get_state_side_diagonal() {
    Board b = *(new Board());
    b.move(0, 4, X); // ....X.....
    b.move(1, 3, X); // ...X......
    b.move(2, 2, X); // ..X.......
    b.move(3, 1, X); // .X........
    b.move(4, 0, X); // X.........
                     // ..........
    DO_CHECK(b.get_state(0, 4) == X);
    DO_CHECK(b.get_state(1, 3) == X);
    DO_CHECK(b.get_state(2, 2) == X);
    DO_CHECK(b.get_state(3, 1) == X);
    DO_CHECK(b.get_state(4, 0) == X);
}

void BoardTest::test_get_state_vertical() {
    Board b;
    b.move(0, 0, X); // X.........
    b.move(1, 0, X); // X.........
    b.move(2, 0, X); // X.........
    b.move(3, 0, X); // X.........
    b.move(4, 0, X); // X.........
                     // ..........
    DO_CHECK(b.get_state(4, 0) == X);
    DO_CHECK(b.get_state(3, 0) == X);
    DO_CHECK(b.get_state(2, 0) == X);
    DO_CHECK(b.get_state(1, 0) == X);
    DO_CHECK(b.get_state(0, 0) == X);
}

void BoardTest::test_get_state_bad_vertical() {
    Board b;
    b.move(0, 0, X); // X.........
    b.move(1, 0, X); // X.........
    b.move(2, 0, X); // X.........
    b.move(3, 0, X); // X.........
                     // ..........
    DO_CHECK(b.get_state(3, 0) == NoOne);
    DO_CHECK(b.get_state(2, 0) == NoOne);
    DO_CHECK(b.get_state(1, 0) == NoOne);
    DO_CHECK(b.get_state(0, 0) == NoOne);
}

void BoardTest::test_can_move_empty_field() {
    Board b;
    DO_CHECK(b.can_move(0, 0));
    DO_CHECK(b.can_move(9, 9));
    DO_CHECK(b.can_move(0, 9));
    DO_CHECK(b.can_move(9, 0));

    DO_CHECK(b.can_move(5, 9));
    DO_CHECK(b.can_move(9, 5));
    DO_CHECK(b.can_move(0, 5));
    DO_CHECK(b.can_move(5, 0));

    DO_CHECK(b.can_move(5, 5));
}

void BoardTest::test_move_and_can_move() {
    Board b;
    DO_CHECK(b.can_move(0, 0));
    DO_CHECK(b.can_move(1, 0));
    b.move(0, 0, X);
    DO_CHECK(!b.can_move(0, 0));
    b.move(1, 0, O);
    DO_CHECK(!b.can_move(1, 0));
    b.move(9, 9, X);
    DO_CHECK(!b.can_move(9, 9));
}


void BoardTest::run_all_tests() {
    std::cout << "Start tests :\n";
    total_num = failed_num = 0;

    test_get_state_horizontal();
    test_get_state_main_diagonal();
    test_get_state_side_diagonal();
    test_get_state_vertical();
    test_get_state_bad_vertical();
    test_can_move_empty_field();
    test_move_and_can_move();
}
