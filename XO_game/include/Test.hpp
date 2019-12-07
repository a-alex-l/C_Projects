#pragma once

#include <iostream>

#define DO_CHECK(EXPR) check(EXPR, __FUNCTION__, __FILE__, __LINE__);

class Test {
protected:
    int failed_num;
    int total_num;

    void check(bool expr, const char *func, const char  *filename, size_t lineNum);

public:
    void show_final_result();

    virtual void run_all_tests() = 0;
};
