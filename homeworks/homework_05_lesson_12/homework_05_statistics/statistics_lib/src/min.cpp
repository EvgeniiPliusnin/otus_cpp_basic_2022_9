#include <iostream>
#include <limits>

#include "i_statistics.hpp"
#include "min.hpp"

namespace statistics {

Min::Min() : m_min{std::numeric_limits<double>::min()} {}

void Min::update(double next) {
    if (next < m_min) {
        m_min = next;
    }
}

double Min::eval() const {
    return m_min;
}

const char * Min::name() const {
    return "min";
}

Max::Max() : m_max{std::numeric_limits<double>::max()} {}

}