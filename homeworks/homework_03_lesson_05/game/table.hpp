#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include "structures.hpp"
#include <chrono>
#include <algorithm>
#include <iomanip>

class Table{
public:
    Table();
    void update(const Result& result);
    void show_results();
    void reset_results();

private:
    void sort();

private:
    unsigned int MIN_WIDTH = 10;
    unsigned int POS_WIDTH = 2;
    unsigned int USER_NAME_WIDTH = MIN_WIDTH;
    unsigned int TIME_WIDTH = MIN_WIDTH;
    unsigned int SCORE_WIDTH = MIN_WIDTH;
    unsigned int PADDING = 2;
    unsigned int ITEM_CNT = 4;
    unsigned int ROW_WIDTH = 0;

    std::string score_table_ = "./score_table";

    std::fstream file_;
    std::vector<Result> table_;
    std::string header_bound_ = "";
    std::string line_bound_ = "";
    std::string row_ = "";    
};
