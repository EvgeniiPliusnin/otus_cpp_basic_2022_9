#include "../inc/table.hpp"

using namespace std::chrono;

Table::Table() {
    file_ = std::fstream(score_table_, std::ios_base::in | std::ios_base::app);
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
        file_.close();
    }
}

void Table::show_results() {
    auto get_max_width = [](const std::string& item, unsigned int &width) {
        auto length = item.length();
        if(length > width)
            width = length;
    };

    auto print_no_result_msg = [this]() {
        std::cout<< "\r\n"
            "******************************************************************\r\n"
            "                            NO RESULTS\r\n"
            "******************************************************************\r\n"
        << std::endl;
    };


    auto get_header_bound = [this]() {
        header_bound_ = "+";
        for (int i = 0; i < (ROW_WIDTH - 2); i++) {
            header_bound_ += "-";
        }
        header_bound_ += "+\n\r";
    };

    auto get_line_bound = [this] () {
        line_bound_ = "+";
        auto item_padding = [this] (unsigned int size) {
            for(size_t i = 0; i < (PADDING * 2 + size); i++) {
                line_bound_ += "-";
            }
        };
        item_padding(POS_WIDTH);
        line_bound_ += "+";
        item_padding(USER_NAME_WIDTH);
        line_bound_ += "+";
        item_padding(TIME_WIDTH);
        line_bound_ += "+";
        item_padding(SCORE_WIDTH);
        line_bound_ += "+\n";
    };

    auto print_item = [this](const std::string &str, unsigned int &len) {
        std::cout << "|";
        std::string space_padding(PADDING, ' ');
        std::cout << space_padding;
        std::cout << std::left << std::setw(len + 2) << str + space_padding;

    };

    auto init_msg = [&, this]() {
        for_each (table_.begin(), table_.end(), [&, this](auto item){
            get_max_width(item.user_name, USER_NAME_WIDTH);
            get_max_width(std::to_string(item.record_time.count()), TIME_WIDTH);
            get_max_width(std::to_string(item.score), SCORE_WIDTH);
        });
        ROW_WIDTH = 2 + (2 * PADDING * ITEM_CNT) + POS_WIDTH + USER_NAME_WIDTH + TIME_WIDTH + SCORE_WIDTH + ITEM_CNT - 1;
                get_header_bound();
        get_line_bound();
    };

    auto print_winners = [&, this]() {
        for (size_t i = 0; i < table_.size(); ++i) {
            if (i == 5)
                break;
            print_item(std::to_string(i + 1), POS_WIDTH);
            print_item(table_[i].user_name, USER_NAME_WIDTH);
            print_item(std::to_string(table_[i].record_time.count()), TIME_WIDTH);
            print_item(std::to_string(table_[i].score), SCORE_WIDTH);
            std::cout << "|" << std::endl <<  line_bound_;
        }
    };

    auto print_header = [&]() {
        std::cout << header_bound_;
        std::string msg = "Aviable only 5 positions";
        std::string msg_row = "|";
        for(int i = 0; i < ((ROW_WIDTH - msg.length()) / 2); i++){
            msg_row += " ";
        };
        msg_row += msg;
        for(int i = 0; ROW_WIDTH != (msg_row.length() + 1); i++){
            msg_row += " ";
        };        
        msg_row += "|";
        std::cout << std::right << msg_row << std::endl;
        std::cout << line_bound_;
        print_item("No", POS_WIDTH);
        print_item("USER NAME", USER_NAME_WIDTH);
        print_item("TIME", TIME_WIDTH);
        print_item("SCORE", SCORE_WIDTH);
        std::cout << "|" << std::endl << line_bound_;
    };

    if (table_.empty()) {
        print_no_result_msg();
    } else {
        init_msg();
        print_header();
        print_winners();
    }
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
    file_.open(score_table_, std::ios::out | std::ios::trunc);
    for(auto item : table_) {
        file_ << item.user_name << ";";
        file_ << std::to_string(item.record_time.count()) << ";";
        file_ << std::to_string(item.score) << std::endl;
    }
    file_.close();
}

void Table::reset_results() {
    table_.erase(table_.begin(), table_.end());
    file_.open(score_table_, std::ios::out | std::ios::trunc);
    file_.close();
    std::cout<< "\r\n"
        "******************************************************************\r\n"
        "                  THE RESULTS TABLE HAS BEEN RESET\r\n"
        "******************************************************************\r\n"
        << std::endl;
}
