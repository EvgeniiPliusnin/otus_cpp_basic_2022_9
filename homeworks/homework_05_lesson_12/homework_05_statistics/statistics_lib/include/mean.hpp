//
// Created by user on 22.07.23.
//

#ifndef STATISTICS_MEAN_HPP
#define STATISTICS_MEAN_HPP

#include "statistics.hpp"

namespace statistics {

    class Mean : public  IStatistics {
    public:
        Mean() = default;

        void  update(double next) override;

        double eval() const override;

        const char *name() const override;

    private:
        double m_mean{};
        double m_count{};
    };


}

#endif //STATISTICS_MEAN_HPP
