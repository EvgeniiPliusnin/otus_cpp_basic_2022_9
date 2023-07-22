//
// Created by user on 22.07.23.
//

#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>

#include "pct.hpp"

namespace statistics {

    Pct::Pct(int pct)
        : m_pct{pct} {
        m_name = "pct" + std::to_string(m_pct);
    }

    void Pct::update(double next) {
        m_value_list.emplace_back(next);
        std::sort(m_value_list.begin(), m_value_list.end());
    }

    double Pct::eval() const {
        double pct_index = (static_cast<double>(m_pct) / 100) * static_cast<double>(m_value_list.size());
        double i_ptr = 0;
        double pct_result{};
        int arr_index{};
        if (std::modf(pct_index, &i_ptr) == 0.0) {
            arr_index = static_cast<int>(pct_index);
            pct_result = (m_value_list[arr_index] + m_value_list[arr_index - 1]) / 2;
        } else {
            pct_index = ::ceil(pct_index);
            arr_index = static_cast<int>(pct_index);
            pct_result = m_value_list[arr_index - 1];
        }

        return pct_result;
    }

    const char* Pct::name() const {
        return m_name.c_str();
    }
}