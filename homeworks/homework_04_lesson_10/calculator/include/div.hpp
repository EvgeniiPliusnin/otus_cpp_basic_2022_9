//
// Created by user on 18.07.23.
//

#ifndef CALC_DIV_HPP
#define CALC_DIV_HPP

#include <string>

#include "astnode.hpp"

namespace nodes {

    class Div : public ASTNode {
    public:
        explicit Div(ASTNode *lhs, ASTNode *rhs)
                : ASTNode("/", lhs, rhs) {}
    };

}

#endif //CALC_DIV_HPP
