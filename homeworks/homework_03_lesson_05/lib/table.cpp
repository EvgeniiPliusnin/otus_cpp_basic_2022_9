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

    auto no_result_msg = []() {
        std::cout<< "\r\n"
            "***************************\r\n"   
            "       NO RESULT           \r\n"
            "***************************\r\n"
            //  TODO: solve beautiful export, doesn't work (unknown escape sequence)
            // "**************************************************************\r\n"
            // "*           _   __                              ____         *\r\n"
            // "*          / | / /___     ________  _______  __/ / /_        *\r\n"
            // "*         /  |/ / __ \   / ___/ _ \/ ___/ / / / / __/        *\r\n"
            // "*        / /|  / /_/ /  / /  /  __(__  ) /_/ / / /_          *\r\n"
            // "*       /_/ |_/\____/  /_/   \___/____/\__,_/_/\__/          *\r\n"
            // "*                                                            *\r\n"
            // "*                                                            *\r\n"  
            // "**************************************************************\r\n"
        << std::endl;
    };

    if (table_.empty()) {
        no_result_msg();
    } else {

    }
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

void Table::update(const Result& result) {
    table_.push_back(result);
    sort();
}

void Table::reset_results() {
    table_.erase(table_.begin(), table_.end());
    file_.
}

int main(int argc, char const *argv[])
{
    Table table;
    table.update(Result{.user_name{"added_instance_test"}, .record_time{3s}, .score{7777777}});
    table.show_results();

    return 0;
}
