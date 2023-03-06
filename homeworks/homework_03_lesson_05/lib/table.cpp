#include "table.hpp"

Table::Table() {
    file_ = std::fstream("./test.csv", std::ios_base::in | std::ios_base::app);
    if (!file_.is_open()) {
        std::cerr << "file is not opened" << std::endl;
    } else {
        auto parse = [](std::string str) -> Result {
            std::vector<std::string> str_result;

            Result result = {
                .user_name = "user_name",
                .record_time = std::chrono::seconds{std::stoi("123")},
                .score = std::stoi("55"),
            };

            Result result;

            return result;
        };

        for (std::string str; std::getline(file_, str);) {
            table_.push_back(parse(str));
        }
    }
}

void Table::show_results() {
    auto announce_winner = [](Result result) {
        std::cout << "*********************************" << std::endl;
        std::cout << result.user_name << "   |    ";
        std::cout << result.record_time.count() << "   |   ";
        std::cout << result.score << "   |" << std::endl;
    };
    std::for_each(table_.cbegin(), table_.cend(), announce_winner);
}

void Table::sort() {
    
}

int main(int argc, char const *argv[])
{
    Table table;
    table.show_results();

    return 0;
}
