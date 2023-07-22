//
// Created by user on 22.07.23.
//

#include <iostream>
#include <limits>

#include "statistics.hpp"
#include "min.hpp"
#include "max.hpp"
#include "mean.hpp"
#include "sd.hpp"
#include "pct.hpp"

using namespace statistics;

int main() {

    const size_t statistic_methods = 6;
    IStatistics *statistics[statistic_methods];

    statistics[0] = new Min{};
    statistics[1] = new Max{};
    statistics[2] = new Mean{};
    statistics[3] = new Sd{};
    statistics[4] = new Pct{90};
    statistics[5] = new Pct{95};

    double val = 0;
    while (std::cin >> val) {
        for (auto & statistic : statistics) {
            statistic->update(val);
        }
    }

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    // Print results if any
    for (auto & statistic : statistics) {
        std::cout << statistic->name() << " = " << statistic->eval() << std::endl;
    }

    // Clear memory - delete all objects created by new
    for (auto & statistic : statistics) {
        delete statistic;
    }

    return 0;
}