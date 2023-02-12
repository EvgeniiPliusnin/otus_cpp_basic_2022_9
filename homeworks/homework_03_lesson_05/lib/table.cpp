#include "table.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

Table::Table() {
    file_ = std::fstream("./test.csv", std::ios_base::in | std::ios_base::app);
    if (!file_.is_open()) {
        std::cerr << "file is not opened" << std::endl;
    } else {
        std::vector<std::string> v;
        for (std::string str; std::getline(file_, str);) {
            v.push_back(str);
        }
        auto parse = [](std::string str) {
            std::cout << str << std::endl;
        };
        std::for_each(v.begin(), v.end(), parse);
    }
}

void Table::show_results() {
    
}

int main(int argc, char const *argv[])
{
    Table table;
    return 0;
}
