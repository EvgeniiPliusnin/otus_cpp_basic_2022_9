//
// Created by user on 22.07.23.
//

#ifndef STATISTICS_MIN_HPP
#define STATISTICS_MIN_HPP

#include "i_statistics.hpp"
#include "min.hpp"
#include "max.hpp"

namespace statistics {
    class Min : public IStatistics {
    public:
        Min();

        void update(double next) override;

        double eval() const override;

        const char *name() const override;

    private:
        double m_min;
    };
}

#endif //STATISTICS_MIN_HPP
