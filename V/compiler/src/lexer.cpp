#include "lexer.hpp"
#include <cctype>
#include <iostream>

Lexer::Lexer(const std::string& src) : source(src), pos(0), current_line(1), current_column(1) {}

char Lexer::peek() {
    if (pos >= source.length()) return '\0';
    return source[pos];
}

void Lexer::advance() {
    if (pos < source.length()) {
        if (source[pos] == '\n') {
            current_line++;
            current_column = 1;
        } else {
            current_column++;
        }
        pos++;
    }
}

void Lexer::skipWhitespace() {
    while (std::isspace(peek())) advance();
}

Token Lexer::number() {
    std::string result = "";
    int start_col = current_column;
    while (std::isdigit(peek())) {
        result += peek();
        advance();
    }
    return {TokenType::NUMBER, result, current_line, start_col};
}

Token Lexer::id_or_keyword() {
    std::string result = "";
    int start_col = current_column;
    while (std::isalnum(peek()) || peek() == '_') {
        result += peek();
        advance();
    }
    TokenType type = TokenType::ID;
    if (result == "import") type = TokenType::IMPORT;
    else if (result == "as") type = TokenType::AS;
    else if (result == "func") type = TokenType::FUNC;
    else if (result == "if") type = TokenType::IF;
    else if (result == "else") type = TokenType::ID; // Şimdilik ID geçiyoruz
    else if (result == "var") type = TokenType::VAR;
    else if (result == "while") type = TokenType::ID; // Parse'da ID olarak yakalayacağız
    else if (result == "true") type = TokenType::TRUE;
    else if (result == "false") type = TokenType::FALSE;
    return {type, result, current_line, start_col};
}

Token Lexer::string_literal() {
    std::string result = "";
    int start_col = current_column;
    advance();
    while (peek() != '"' && peek() != '\0') {
        result += peek();
        advance();
    }
    if (peek() == '"') advance();
    return {TokenType::STRING, result, current_line, start_col};
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos < source.length()) {
        skipWhitespace();
        if (pos >= source.length()) break;
        char c = peek();
        int start_col = current_column;

        if (std::isdigit(c)) {
            tokens.push_back(number());
        } else if (std::isalpha(c) || c == '_') {
            tokens.push_back(id_or_keyword());
        } else if (c == '"') {
            tokens.push_back(string_literal());
        } else {
            switch (c) {
                case '=':
                    advance();
                    if (peek() == '=') { advance(); tokens.push_back({TokenType::EQUALS_EQUALS, "==", current_line, start_col}); }
                    else { tokens.push_back({TokenType::EQUALS, "=", current_line, start_col}); }
                    break;
                case '+': tokens.push_back({TokenType::PLUS, "+", current_line, start_col}); advance(); break;
                case '-': tokens.push_back({TokenType::MINUS, "-", current_line, start_col}); advance(); break;
                case '*': tokens.push_back({TokenType::MULTIPLY, "*", current_line, start_col}); advance(); break;
                case '/': tokens.push_back({TokenType::DIVIDE, "/", current_line, start_col}); advance(); break;
                case '%': tokens.push_back({TokenType::ID, "%", current_line, start_col}); advance(); break; // Collatz mod için
                case '>': tokens.push_back({TokenType::ID, ">", current_line, start_col}); advance(); break;
                case '<': tokens.push_back({TokenType::ID, "<", current_line, start_col}); advance(); break;
                case '(': tokens.push_back({TokenType::LPAREN, "(", current_line, start_col}); advance(); break;
                case ')': tokens.push_back({TokenType::RPAREN, ")", current_line, start_col}); advance(); break;
                case '{': tokens.push_back({TokenType::LBRACE, "{", current_line, start_col}); advance(); break;
                case '}': tokens.push_back({TokenType::RBRACE, "}", current_line, start_col}); advance(); break;
                case '.': tokens.push_back({TokenType::DOT, ".", current_line, start_col}); advance(); break;
                case ',': tokens.push_back({TokenType::COMMA, ",", current_line, start_col}); advance(); break;
                default:
                    advance();
                    break;
            }
        }
    }
    tokens.push_back({TokenType::EOF_TOKEN, "", current_line, current_column});
    return tokens;
}
