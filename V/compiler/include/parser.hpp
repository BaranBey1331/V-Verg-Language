#pragma once
#include <vector>
#include <string>
#include "lexer.hpp"
#include "ast.hpp"

// === V-ENGINE SÖZDİZİMİ AYRIŞTIRICISI (PARSER) ===
// Lexer'dan gelen kelimeleri (Token) okur ve anlamlı bir Ağaca (AST) dönüştürür.

class Parser {
private:
    std::vector<Token> tokens;
    size_t pos;

    // İç Mekanizmalar
    Token peek();
    Token advance();
    
    // Hata Yakalama Sistemi
    void error(const std::string& message);
    void expect(TokenType type, const std::string& error_msg);

    // Ağaç (AST) Üretici Düğümler
    ASTNode* parseExpression(); // İŞTE UNUTULAN KRİTİK SATIR BURASI!
    ASTNode* parseMethodCall();
    ASTNode* parseStatement();

public:
    // Yapıcı (Constructor)
    Parser(const std::vector<Token>& t);
    
    // Tüm dosyayı okuyup donanıma (Transpiler'a) gönderecek olan ana fonksiyon
    std::vector<ASTNode*> parseAll();
};
