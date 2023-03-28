#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <boost/program_options.hpp>
#include <chrono>
#include "table.hpp"
#include "structures.hpp"
#include "unordered_set"

void print_welcome(void);
void exit(void);

enum class Levels : unsigned int {
    level_1 = 1,
    level_2 = 2,
    level_3 = 3,
};

class Game {
public:
    Game()=default;
    void parse_args(int argc, char const *argv[]);
    void init(void);

private:
    Table score_table_;
    unsigned int range_;
    unsigned int level_scale_ = 1;
    unsigned int attempt_quantity_ = 0;
    const std::unordered_set<Levels> levels_ = {Levels::level_1, Levels::level_2, Levels::level_3};
};
