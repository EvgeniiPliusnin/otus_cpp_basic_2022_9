#include "table.hpp"

Table::Table() {
    file_ = std::fstream("./test.csv", std::ios_base::in | std::ios_base::app);
    if (!file_.is_open()) {
        std::cerr << "file is not opened" << std::endl;
    } else {
        auto parse = [](std::string str) -> Result {

        };
        for (std::string str; std::getline(file_, str);) {
            table_.push_back(parse(str));
        }
    }
}

void Table::show_results() {

}

void Table::sort() {

}

int main(int argc, char const *argv[])
{
    return 0;
}
