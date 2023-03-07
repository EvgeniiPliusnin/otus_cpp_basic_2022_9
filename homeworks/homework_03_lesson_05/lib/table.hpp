#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include "structures.hpp"
#include <chrono>
#include <algorithm>

class Table{
public:
    Table();
    void update(const Result& result);
    void show_results();
    void reset_results();

private:
    void sort();

private:
    std::fstream file_;
    std::vector<Result> table_;
};  