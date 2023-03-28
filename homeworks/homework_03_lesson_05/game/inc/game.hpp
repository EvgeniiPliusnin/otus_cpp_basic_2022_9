#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <boost/program_options.hpp>
#include <chrono>
#include "table.hpp"
#include "structures.hpp"

void print_welcome(void);
void exit(void);

class Game {
public:
    Game()=default;
    void parse_args(int argc, char const *argv[]);
    void init(void);

private:
    Table score_table_;
    unsigned int range_;
    unsigned int level_ = 1;
    unsigned int attempt_quantity_ = 0;
};
