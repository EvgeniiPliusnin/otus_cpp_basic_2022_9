//
// Created by user on 22.07.23.
//

#ifndef STATISTICS_MAX_HPP
#define STATISTICS_MAX_HPP

#include "statistics.hpp"

namespace statistics {

    class Max : public IStatistics {
    public:
        Max();

        void update(double next) override;

        double eval() const override;

        const char *name() const override;

    private:
        double m_max;
    };
}

#endif //STATISTICS_MAX_HPP
