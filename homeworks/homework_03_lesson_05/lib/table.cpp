#include "table.hpp"

using namespace std::chrono;

Table::Table() {
    file_ = std::fstream("./test.csv", std::ios_base::in | std::ios_base::app);
    if (!file_.is_open()) {
        std::cerr << "file is not opened" << std::endl;
    } else {
        auto parse = [](std::string str) -> Result {
            std::string delim = ";";
            Result result;

            // user_name
            std::size_t pos = str.find(delim);
            result.user_name = str.substr(0, pos);
            str.erase(0, pos + delim.length());

            // record_time
            pos = str.find(delim);
            result.record_time = seconds{std::stoi(str.substr(0, pos))};
            str.erase(0, pos + delim.length());

            // score
            result.score = std::stoi(str);

            return result;
        };

        for (std::string str; std::getline(file_, str);) {
            table_.push_back(parse(str));
        }
    }
}

void Table::show_results() {
    auto announce_winner = [](Result result) {
        std::cout << "******************************************" << std::endl;
        std::cout << result.user_name << "   |    ";
        std::cout << result.record_time.count() << "           |   ";
        std::cout << result.score << "   |" << std::endl;
    };
    std::for_each(table_.cbegin(), table_.cend(), announce_winner);
}

void Table::sort() {
    auto compare = [](const Result& a, const Result& b){
        if (a.score > b.score) {
            return true;
        } else if (a.score < b.score) {
            return false;
        } else {
            if (a.record_time < b.record_time) {
                return true;
            } else {
                return false;
            }
        }
    };

    std::stable_sort(table_.begin(), table_.end(), compare);
}

int main(int argc, char const *argv[])
{
    Table table;
    table.show_results();

    std::cout << "\n\n\n";

    table.sort();
    table.show_results();

    return 0;
}
