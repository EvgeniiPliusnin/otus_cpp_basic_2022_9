#include "parser.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mul.hpp"
#include "number.hpp"
#include "sub.hpp"
#include "variable.hpp"

using Token = Lexer::Token;

ASTNode *Parser::parse() { return expr(); }

void Parser::next_token() { tok_ = lexer_.next_token(); }

ASTNode *Parser::expr() {
    // parse addition and subsctruction
    ASTNode *root = term();
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '+':
                 root = new nodes::Add(root, term());
                break;
            case '-':
                root = new nodes::Sub(root, term());
                break;
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}

ASTNode *Parser::term() {
    // parse multiplication and division
    ASTNode *root = prim();
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '*':
                 root = new nodes::Mul(root, prim());
                break;
            case '/':
                root = new nodes::Div(root, prim());
                break;
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}

ASTNode *Parser::prim() {
    // parse numbers and names
    ASTNode *node = nullptr;
    next_token();
    switch (tok_) {
    case Token::Number:
        node = new nodes::Number(lexer_.get_number());
        break;
    case Token::Name:
        node = new nodes::Variable(lexer_.get_name());
        break;
    case Token::Lbrace:
        node = expr();
        break;
    case Token::Rbrace:
        return node;
        break;
    default:
        break;
    }
    next_token();
    return node;
}