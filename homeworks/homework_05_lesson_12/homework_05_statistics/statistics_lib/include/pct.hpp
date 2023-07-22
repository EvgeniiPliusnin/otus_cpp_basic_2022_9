//
// Created by user on 22.07.23.
//

#ifndef STATISTICS_PCT_HPP
#define STATISTICS_PCT_HPP

#include <vector>

#include "statistics.hpp"

namespace statistics {
    class Pct : public IStatistics{
    public:
        explicit Pct(int pct);

        void update(double next) override;

        double eval() const override;

        const char *name() const override;

    private:
        int m_pct{};
        std::string m_name;
        std::vector<double> m_value_list;
    };
}

#endif //STATISTICS_PCT_HPP
