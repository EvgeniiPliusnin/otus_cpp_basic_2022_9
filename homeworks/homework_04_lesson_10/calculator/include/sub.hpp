//
// Created by user on 18.07.23.
//

#ifndef CALC_SUB_HPP
#define CALC_SUB_HPP

#include <string>

#include "astnode.hpp"

namespace nodes {

    class Sub : public ASTNode {
    public:
        explicit Sub(ASTNode *lhs, ASTNode *rhs)
                : ASTNode("-", lhs, rhs) {}
    };

}

#endif //CALC_SUB_HPP
