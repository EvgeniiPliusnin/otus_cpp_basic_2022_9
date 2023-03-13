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

void get_table(void) {

}

void safe_table(void) {

}

void show_table(void) {

}

void clear_terminal() {
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
} 

int main(int argc, char const *argv[])
{
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("level", po::value<int>(), "set level of game 1-3")
        ("max", po::value<int>(), "set max value of a number for guess (Don't use with arg level)")
        ("table", "show a table with scoring results")
        ("reset", "reset the scoring table values")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);  

    if (vm.count("help")) {
        std::cout << desc << "\n";
        // return 1;
    }

    Table game_table;
    game_table.show_results();

    game_table.update(Result{.user_name{"added_instance_tffffffffffffffffffffest"}, .record_time{3s}, .score{7777777}});
    game_table.show_results();

    game_table.reset_results();
    game_table.show_results();  
    
    print_welcome();
    // std::srand(std::time(nullptr));
    // const int max_value = 100;
    // const int random_value = std::rand() % max_value;

    // const std::string user_name = get_user_name();
    // std::cout << user_name << std::endl;


    return 0;
}
