//
// Created by user on 22.07.23.
//

#include <limits>

#include "max.hpp"

namespace statistics {

    Max::Max() : m_max{std::numeric_limits<double>::lowest()} {}

    void Max::update(double next) {
        if (next > m_max) {
            m_max = next;
        }
    }

    double Max::eval() const {
        return m_max;
    }

    const char * Max::name() const {
        return "max";
    }

}