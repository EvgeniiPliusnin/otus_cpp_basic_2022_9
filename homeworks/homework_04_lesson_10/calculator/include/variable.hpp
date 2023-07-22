//
// Created by user on 18.07.23.
//

#ifndef CALC_VARIABLE_HPP
#define CALC_VARIABLE_HPP

#include <string>

#include "astnode.hpp"

namespace nodes {

    class Variable : public ASTNode {
    public:
        explicit Variable(const std::string& val)
                : ASTNode(val)
                , val_(val){}

        std::string value() const { return val_; }

    private:
        std::string val_;
    };
}

#endif //CALC_VARIABLE_HPP
