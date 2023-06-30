#include "game.hpp"
#include "table.hpp"

#include <stdlib.h>
#include <cstdlib>
#include <ctime>

namespace po = boost::program_options;
using namespace guess_number;

void Game::print_welcome() {
    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "<<<           The game 'Guess the number'           >>>" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
}

std::string Game::get_user_name() {
    std::cout << "Please, enter your name: ";
    std::string name;
    std::cin >> name;
    if(name == "") {
        std::cerr << "Error. String is empty. ";    // todo - fix (doesn't show error)
        name = get_user_name();
    }
    std::cout << std::endl;

    return name;
}

Game::Game(int argc, char const *argv[]) {
    bool reset = false;
    bool show_table = false;
    unsigned int max = 0;

    po::options_description desc("Allowed options");
    desc.add_options()
            ("help,h", "produce help message")
            ("level,l", po::value<decltype(level_)>(), "set level of game 1-3")
            ("max,m", po::value<decltype(max)>(), "set max value of a number for guess (Don't use with arg level)")
            ("show-table,t", po::bool_switch(&show_table)->default_value(show_table), "how_table with scoring results and exit")
            ("reset,r", po::bool_switch(&reset)->default_value(reset), "reset show_table"
             "reset the scoring show_table values and exit")
            ;
    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        if (vm.count("help")) {
            std::cout << desc << std::endl;
            std::exit(EXIT_SUCCESS);
        }
        if (vm.count("max") && vm.count("level")) {
            std::cerr << "Don't use two arguments [max] and [level] at the same time" << std::endl;
            exit(EXIT_FAILURE);
        } else {
            if (vm.count("max")) {
                max = vm["max"].as<decltype(max)>();
                if (max > 0) {
                    max_ = max;
                    if (max_ <= 0) {
                        level_ = 1;
                    } else if (max >= 10 && max <= 49) {
                        level_ = 2;
                    } else if (max >= 50 && max_ <= 99) {
                        level_ = 3;
                    } else {
                        level_ = 3 + max_ / 100 % 10;
                    }
                } else {
                    std::cerr << "The [max] argument must be greater than zero" << std::endl;
                    std::exit(EXIT_FAILURE);
                }
            }
            if (vm.count("level")) {
                level_ = vm["level"].as<decltype(level_)>();
                if (auto item = levels.find(static_cast<Levels>(level_)); item == levels.end()) {
                    std::cerr << "Invalid argument [--level], please use values 1-3" << std::endl;
                    std::exit(EXIT_FAILURE);
                }
//                Doesn't work
//                switch (level_) {
//                    case Levels::level_1:
//                        max_ = 9;
//                        break;
//                    case Levels::level_2:
//                        max_ = 49;
//                        break;
//                    case Levels::level_3:
//                        max_ = 99;
//                        break;
//                    default:
//                        break;
//                }
                if (level_ == 1) {
                    max_ = 9;
                } else if (level_ == 2) {
                    max_ = 49;
                } else if (level_ == 3) {
                    max_ = 99;
                }
            }
        }
        po::notify(vm);
    } catch (const po::error& e) {
        std::cerr << "Error while parsing: " << e.what() << "\n" << desc << std::endl;
        std::exit(EXIT_FAILURE);
    }

    if (reset) {
        score_table_.reset_results();
        std::exit(EXIT_SUCCESS);
    }
    if (show_table) {
        score_table_.show_results();
        std::exit(EXIT_SUCCESS);
    }

    print_welcome();
    player_.user_name = get_user_name();
}

unsigned int Game::generate_random() {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    const int random_value = std::rand() % max_;
    return  random_value;
}

void Game::start() {
/*
TODO:
  1. generate a random number
  2. start the timer
  3. call function guess_number | -> return attempt_quantity OR exit from program if player doesn't want continue
  4. stop the timer
  5. calculate score(scale, attempt)
  6. update result table
*/

    unsigned int random_number = generate_random();
#ifdef DEBUG
    std::cout << "Random number is " << random_number << std::endl;
#endif
    unsigned int attempt_quantity = guess_number(random_number);
    std::cout << "The number of attempts is " << attempt_quantity << std::endl;
}

unsigned int Game::guess_number(const int target_value) {
    int current_value{};
    unsigned int attempt_quantity = 1;
    std::cout << "Enter your guess:" << std::endl;
    do {
        std::cin >> current_value;

        if (current_value < target_value) {
            std::cout << "Less than target " << std::endl;
        } else if (current_value > target_value) {
            std::cout << "Greater than target" << std::endl;
        } else {
            std::cout << "You win!" << std::endl;
            break;
        }
        attempt_quantity++;
    } while(true);

    return attempt_quantity;
}

int main(int argc, char const *argv[])
{
    Game game{argc, argv};
    do {
        std::cout << "Press Enter to start the game. Or enter Ctrl+C to exit" << std::endl << std::endl;
    } while (std::cin.get() != '\n');
    game.start();

    return 0;
}
