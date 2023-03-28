#include "../inc/game.hpp"
#include "../inc/table.hpp"

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
    Table score_table;
    bool reset = false;
    unsigned int level = NULL;
    unsigned int max = NULL;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("level,l", po::value<int>(), "set level of game 1-3")
        ("max,m", po::value<int>(), "set max value of a number for guess (Don't use with arg level)")
        ("table,t", "show a table with scoring results and exit")
        ("reset,r", po::bool_switch(&reset)->default_value(reset),
                "reset the scoring table values and exit")
    ;
    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        if (vm.count("help")) {
            std::cout << desc << std::endl;
            return 0;
        }
        po::notify(vm);
    } catch (const po::error& e) {
        std::cerr << "Error while parsing: " << e.what() << "\n" << desc << std::endl;
        return 1;
    }

    if (vm.count("reset")) {
        score_table.reset_results();
        return 1;
    }

    if (vm.count("max")) {
        max = vm["max"].as<decltype(max)>();
    }

    if (vm.count("level")) {
        level = vm["level"].as<decltype(level)>();
    }

    return 0;
}
