#include "table.hpp"

Table::Table() : file_("test.csv", std::ios_base::app) {
    if (!file_.is_open()) {
        std::clog << "file is not opened" << std::endl;
    } else {
        std::clog << "file is opened" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "hello from main" << std::endl;
    Table table;
    return 0;
}
