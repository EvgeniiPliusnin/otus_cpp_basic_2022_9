//
// Created by user on 18.07.23.
//

#ifndef CALC_ADD_HPP
#define CALC_ADD_HPP

#include <string>

#include "astnode.hpp"

namespace nodes {

    class Add : public ASTNode {
    public:
        explicit Add(ASTNode *lhs, ASTNode *rhs)
                : ASTNode("+", lhs, rhs) {}
    };

}

#endif //CALC_ADD_HPP
