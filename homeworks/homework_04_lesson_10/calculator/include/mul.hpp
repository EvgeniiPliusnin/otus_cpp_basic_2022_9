//
// Created by user on 18.07.23.
//

#ifndef CALC_MUL_HPP
#define CALC_MUL_HPP

#include <string>

#include "astnode.hpp"

namespace nodes {

    class Mul : public ASTNode {
    public:
        explicit Mul(ASTNode *lhs, ASTNode *rhs)
                : ASTNode("*", lhs, rhs) {}
    };

}

#endif //CALC_MUL_HPP
