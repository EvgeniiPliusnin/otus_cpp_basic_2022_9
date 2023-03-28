#include "game.hpp"
#include "table.hpp"

namespace po = boost::program_options;

void print_welcome(void) {
    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "<<<           The game 'Guess the number'           >>>" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
}

std::string get_user_name(void) {
    std::cout << "Please, enter your name: ";
    std::string name;
    std::cin >> name;
    if(name == "") {
        std::cout << "Error. String is empty. ";    // todo - fix (doesn't show error)
        name = get_user_name();
    }

    return name;
}

void exit(void) {
    // TODO print goodbuy and exit from programm
}

int main(int argc, char const *argv[])
{
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("level,l", po::value<int>(), "set level of game 1-3")
        ("max,m", po::value<int>(), "set max value of a number for guess (Don't use with arg level)")
        ("table,t", "show a table with scoring results and exit")
        ("reset,r", "reset the scoring table values and exit")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);  

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    Table score_table;

    if (vm.count("reset")) {
        score_table.reset_results();
        return 1;
    }

    if (vm.count("level") && (vm.count("max"))) {
        std::cout << "Don't use 'level' and 'max' arguments at same time, Please select only one" << std::endl;
        return 1;
    } else {

    }

    score_table.show_results();

    score_table.update(Result{.user_name{"added_instance_tffffffffffffffffffffest"},
                              .record_time=std::chrono::seconds(3),
                              .score{7777777}});
    score_table.show_results();

    score_table.reset_results();
    score_table.show_results();  
    
    print_welcome();
    // std::srand(std::time(nullptr));
    // const int max_value = 100;
    // const int random_value = std::rand() % max_value;

    // const std::string user_name = get_user_name();
    // std::cout << user_name << std::endl;
    return 0;
}
