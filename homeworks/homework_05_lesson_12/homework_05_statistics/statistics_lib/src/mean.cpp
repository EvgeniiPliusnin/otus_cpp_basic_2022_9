//
// Created by user on 22.07.23.
//

#include "mean.hpp"

namespace statistics {

    void Mean::update(double next) {
        ++m_count;
        m_mean += next;
    }

    double Mean::eval() const {
        return m_mean / m_count;
    }

    const char * Mean::name() const {
        return "mean";
    }
}