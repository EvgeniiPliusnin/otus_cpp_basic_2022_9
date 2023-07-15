//
// Created by user on 06.07.23.
//

#pragma once

#include <string>

#include "astnode.hpp"

namespace nodes {

    class Number : public ASTNode {
    public:
        explicit Number(const int val)
                : ASTNode(std::to_string(val))
                , val_(val){}

        int value() const { return val_; }

    private:
        int val_;
    };


// TODO
// Implement the next classes:
// Add
// Sub
// Mul
// Div
// Variable

// Without implementation that classes this application works only with numbers

    class Add : public ASTNode {

    };

    class Sub : public ASTNode {

    };

    class Mul : public ASTNode {

    };

    class Div : public ASTNode {

    };

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