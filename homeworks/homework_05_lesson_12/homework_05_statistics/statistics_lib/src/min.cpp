#include <iostream>
#include <limits>

#include "statistics.hpp"
#include "min.hpp"
#include "max.hpp"


namespace statistics {

Min::Min() : m_min{std::numeric_limits<double>::max()} {}

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

}