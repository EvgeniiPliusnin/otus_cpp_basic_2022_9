//
// Created by user on 22.07.23.
//


#include <cmath>
#include "sd.hpp"
#include "iostream"

namespace statistics {

    void Sd::update(double next) {
        ++m_count;
        m_sum += next;

        if (auto search = m_distribution.find(next); search != m_distribution.end())
            ++m_distribution[next];
        else
            m_distribution.emplace(next, 1);
    }

    double Sd::eval() const {
        double mean = m_sum / m_count;
        double variance{};
        for (const auto &item : m_distribution) {
            variance += std::pow(item.first - mean, 2) * item.second;
        }
        variance /= m_count;
        return std::sqrt(variance);
    }

    const char * Sd::name() const {
        return "sd";
    }

}