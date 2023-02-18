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
        // auto parse = [](std::string str) {
        //     std::cout << str << std::endl;
        // };
        // std::for_each(v.begin(), v.end(), parse);
    }
}

void Table::show_results() {

}

void Table::sort() {

}

void test_print_result(Result result) {
    std::cout << result.user_name << " " << result.record_time.count() << " " << result.score << std::endl;
}

int main(int argc, char const *argv[])
{
    // Table table;

    struct Result result = {
        .user_name="test_user",
        .record_time = std::chrono::seconds{3},
        .score=55,
    };
    test_print_result(result);
    return 0;
}
