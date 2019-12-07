#include "StdioBoardView.hpp"
#include "BoardTest.hpp"

int main() {
    BoardTest test;
    test.run_all_tests();
    test.show_final_result();
}
