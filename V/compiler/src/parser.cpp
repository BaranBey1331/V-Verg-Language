#include "parser.hpp"
#include <iostream>
#include <cstdlib>

Parser::Parser(const std::vector<Token>& t) : tokens(t), pos(0) {}

Token Parser::peek() {
    if (pos >= tokens.size()) return tokens.back();
    return tokens[pos];
}

Token Parser::advance() {
    Token current = peek();
    pos++;
    return current;
}

void Parser::error(const std::string& message) {
    Token t = peek();
    std::cerr << "[SINTAKS HATASI] " << message << " -> Satir: " << t.line << " Kelime: " << t.value << "\n";
    std::exit(1);
}

void Parser::expect(TokenType type, const std::string& error_msg) {
    if (peek().type == type) advance();
    else error(error_msg);
}

ASTNode* Parser::parseExpression() {
    ASTNode* left = nullptr;
    if (peek().type == TokenType::NUMBER) left = new NumberNode(advance().value);
    else if (peek().type == TokenType::STRING) left = new StringNode(advance().value);
    else if (peek().type == TokenType::ID) left = new IdentifierNode(advance().value);
    else if (peek().type == TokenType::LPAREN) {
        advance();
        left = parseExpression();
        expect(TokenType::RPAREN, "Parantez kapatilmadi");
    }
    else error("Gecersiz ifade");

    if (peek().type == TokenType::PLUS || peek().type == TokenType::MINUS || 
        peek().type == TokenType::MULTIPLY || peek().type == TokenType::DIVIDE || 
        peek().type == TokenType::EQUALS_EQUALS || peek().value == ">" || 
        peek().value == "<" || peek().value == "%") {
        std::string op = advance().value;
        ASTNode* right = parseExpression();
        return new BinaryOpNode(left, op, right);
    }
    return left;
}

ASTNode* Parser::parseStatement() {
    Token t = peek();

    // 1. Değişken Tanımlama
    if (t.type == TokenType::VAR) {
        advance();
        std::string varName = advance().value;
        expect(TokenType::EQUALS, "'=' bekleniyor");
        ASTNode* val = parseExpression();
        return new VarDeclNode(varName, val);
    }
    
    // 2. IF SİSTEMİ (PARANTEZ SIZINTISI ÇÖZÜLDÜ)
    if (t.type == TokenType::IF) {
        advance(); // 'if' kelimesini tüket
        expect(TokenType::LPAREN, "'(' bekleniyor");
        ASTNode* cond = parseExpression();
        expect(TokenType::RPAREN, "')' bekleniyor");
        expect(TokenType::LBRACE, "'{' bekleniyor");
        
        IfNode* iNode = new IfNode(cond);
        
        // If gövdesi
        while (peek().type != TokenType::RBRACE && peek().type != TokenType::EOF_TOKEN) {
            ASTNode* stmt = parseStatement();
            if (stmt) iNode->if_body.push_back(stmt);
        }
        expect(TokenType::RBRACE, "'}' bekleniyor");
        
        // Else kısmı
        if (peek().type == TokenType::ID && peek().value == "else") {
            advance(); // 'else' kelimesini tüket
            expect(TokenType::LBRACE, "'{' bekleniyor");
            while (peek().type != TokenType::RBRACE && peek().type != TokenType::EOF_TOKEN) {
                ASTNode* stmt = parseStatement();
                if (stmt) iNode->else_body.push_back(stmt);
            }
            expect(TokenType::RBRACE, "'}' bekleniyor");
        }
        return iNode;
    }

    // 3. Döngüler ve Atamalar
    if (t.type == TokenType::ID) {
        if (t.value == "while") {
            advance();
            expect(TokenType::LPAREN, "'(' bekleniyor");
            ASTNode* cond = parseExpression();
            expect(TokenType::RPAREN, "')' bekleniyor");
            expect(TokenType::LBRACE, "'{' bekleniyor");
            WhileNode* wNode = new WhileNode(cond);
            while (peek().type != TokenType::RBRACE && peek().type != TokenType::EOF_TOKEN) {
                ASTNode* stmt = parseStatement();
                if (stmt) wNode->body.push_back(stmt);
            }
            expect(TokenType::RBRACE, "'}' bekleniyor");
            return wNode;
        }
        
        std::string name = advance().value;
        if (peek().type == TokenType::EQUALS) {
            advance();
            ASTNode* val = parseExpression();
            return new AssignmentNode(name, val);
        } else if (peek().type == TokenType::DOT) {
            advance();
            std::string methodName = advance().value;
            expect(TokenType::LPAREN, "Metod icin '(' lazim");
            MethodCallNode* mNode = new MethodCallNode(name, methodName);
            while (peek().type != TokenType::RPAREN && peek().type != TokenType::EOF_TOKEN) {
                mNode->arguments.push_back(parseExpression());
                if (peek().type == TokenType::COMMA) advance();
            }
            expect(TokenType::RPAREN, "')' lazim");
            return mNode;
        }
    }
    
    advance(); // Bilinmeyenleri yut
    return nullptr;
}

std::vector<ASTNode*> Parser::parseAll() {
    std::vector<ASTNode*> ast;
    while (peek().type != TokenType::EOF_TOKEN) {
        ASTNode* stmt = parseStatement();
        if (stmt) ast.push_back(stmt);
    }
    return ast;
}
