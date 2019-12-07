#pragma once

#include "Test.hpp"

void Test::check(bool expr, const char *func, const char  *filename, size_t lineNum) {
    total_num++;
    if (!expr) {
        std::cout << "--| Wrong test: " << func << " In file: " << filename << " In line: " << lineNum << "\n";
        failed_num++;
    }
}


void Test::show_final_result() {
    std::cout << "All  : " << total_num << "\n";
    std::cout << "Filed : " << failed_num << "\n";
}
