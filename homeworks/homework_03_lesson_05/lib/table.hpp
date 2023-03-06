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
    bool update(const Result& result);
    void show_results();
    void reset_results();
     void sort();

private:
   

private:
    std::fstream file_;
    std::vector<Result> table_;
};  