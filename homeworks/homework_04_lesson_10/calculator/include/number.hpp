//
// Created by user on 18.07.23.
//

#ifndef CALC_NUMBER_HPP
#define CALC_NUMBER_HPP

#include <string>

#include "astnode.hpp"

namespace nodes {

    class Number : public ASTNode {
    public:
        explicit Number(const int val)
                : ASTNode(std::to_string(val)), val_(val) {}

        int value() const { return val_; }

    private:
        int val_;
    };

}

#endif //CALC_NUMBER_HPP
