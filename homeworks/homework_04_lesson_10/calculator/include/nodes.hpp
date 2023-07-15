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

    class Add : public ASTNode {
    public:
        explicit Add(ASTNode *lhs, ASTNode *rhs)
                : ASTNode("+", lhs, rhs) {}
    };

    class Sub : public ASTNode {

    };

    class Mul : public ASTNode {
    public:
        explicit Mul(ASTNode *lhs, ASTNode *rhs)
                : ASTNode("*", lhs, rhs) {}
    };

    class Div : public ASTNode {
    public:
        explicit Div(ASTNode *lhs, ASTNode *rhs)
                : ASTNode("/", lhs, rhs) {}
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