#pragma once

#include "Test.hpp"
#include "Board.hpp"

class BoardTest : public Test {
private:
    void test_get_state_horizontal();

    void test_get_state_main_diagonal();

    void test_get_state_side_diagonal();

    void test_get_state_vertical();

    void test_get_state_bad_vertical();

    void test_can_move_empty_field();

    void test_move_and_can_move();

public:
    
    void run_all_tests();
};
