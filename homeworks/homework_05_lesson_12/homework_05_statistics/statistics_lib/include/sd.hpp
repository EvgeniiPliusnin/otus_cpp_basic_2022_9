//
// Created by user on 22.07.23.
//

#ifndef STATISTICS_SD_HPP
#define STATISTICS_SD_HPP

#include <unordered_map>

#include "statistics.hpp"

namespace statistics {

    class Sd : public IStatistics {
    public:
        Sd() = default;

        void update(double next) override;

        double eval() const override;

        const char *name() const override;

    private:
        double m_sum{};
        double m_count{};
        std::unordered_map<double, int> m_distribution;
    };

}

#endif //STATISTICS_SD_HPP
