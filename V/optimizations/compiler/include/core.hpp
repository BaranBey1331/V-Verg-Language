#ifndef CORE_HPP
#define CORE_HPP

#include <string>
#include <vector>

// === 1. TOKENLER (Yeni Kelimeler Öğreniliyor) ===
enum TokenType {
    TOKEN_ID, TOKEN_NUMBER, TOKEN_STRING,
        TOKEN_VAR, TOKEN_PRINT, TOKEN_WHILE, TOKEN_IF, TOKEN_ELSE, TOKEN_ELIF,
            TOKEN_FOR, TOKEN_TO, TOKEN_BREAK, TOKEN_CONTINUE,
                TOKEN_ASSIGN, TOKEN_PLUS, TOKEN_MINUS, TOKEN_MUL, TOKEN_DIV, TOKEN_MOD,
                    TOKEN_EQ, TOKEN_LT, TOKEN_GT, TOKEN_LBRACE, TOKEN_RBRACE,
                        TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_LBRACKET, TOKEN_RBRACKET, TOKEN_COMMA,
                            TOKEN_FUNC, TOKEN_EOF, TOKEN_UNKNOWN
                            };

                            struct Token {
                                TokenType type;
                                    std::string value;
                                    };

                                    // === 2. ARGÜMANLAR (Diziler Eklendi) ===
                                    enum ArgType { ARG_ID, ARG_NUMBER, ARG_STRING, ARG_ARRAY };

                                    struct Argument {
                                        ArgType type;
                                            std::string value;
                                                std::vector<Argument> arrayElements; // Array [1, 2, 3] verilerini tutar
                                                };

                                                struct Condition {
                                                    Argument left;
                                                        std::string op;
                                                            Argument right;
                                                            };

                                                            // === 3. SÖZDİZİMİ AĞACI (Yeni Mimari Yapılar) ===
                                                            class ASTNode { public: virtual ~ASTNode() = default; };

                                                            class VarDeclNode : public ASTNode {
                                                            public:
                                                                std::string varName;
                                                                    Argument val;
                                                                        VarDeclNode(std::string n, Argument v) : varName(n), val(v) {}
                                                                        };

                                                                        class ReassignNode : public ASTNode {
                                                                        public:
                                                                            std::string targetVar;
                                                                                Argument arg;
                                                                                    ReassignNode(std::string t, Argument a) : targetVar(t), arg(a) {}
                                                                                    };

                                                                                    class MathAssignNode : public ASTNode {
                                                                                    public:
                                                                                        std::string targetVar;
                                                                                            Argument arg1;
                                                                                                std::string op;
                                                                                                    Argument arg2;
                                                                                                        MathAssignNode(std::string t, Argument a1, std::string o, Argument a2) 
                                                                                                                : targetVar(t), arg1(a1), op(o), arg2(a2) {}
                                                                                                                };

                                                                                                                class PrintNode : public ASTNode {
                                                                                                                public:
                                                                                                                    std::string textToPrint;
                                                                                                                        PrintNode(std::string t) : textToPrint(t) {}
                                                                                                                        };

                                                                                                                        class IfNode : public ASTNode {
                                                                                                                        public:
                                                                                                                            Condition cond;
                                                                                                                                std::vector<ASTNode*> body;
                                                                                                                                    std::vector<ASTNode*> elseBody; // Else yapısı eklendi
                                                                                                                                        IfNode(Condition c, std::vector<ASTNode*> b, std::vector<ASTNode*> e = {}) : cond(c), body(b), elseBody(e) {}
                                                                                                                                        };

                                                                                                                                        class WhileNode : public ASTNode {
                                                                                                                                        public:
                                                                                                                                            Condition cond;
                                                                                                                                                std::vector<ASTNode*> body;
                                                                                                                                                    WhileNode(Condition c, std::vector<ASTNode*> b) : cond(c), body(b) {}
                                                                                                                                                    };

                                                                                                                                                    // YENİ: For Döngüsü Node'u
                                                                                                                                                    class ForNode : public ASTNode {
                                                                                                                                                    public:
                                                                                                                                                        std::string iteratorVar;
                                                                                                                                                            Argument startVal;
                                                                                                                                                                Argument endVal;
                                                                                                                                                                    std::vector<ASTNode*> body;
                                                                                                                                                                        ForNode(std::string i, Argument s, Argument e, std::vector<ASTNode*> b) 
                                                                                                                                                                                : iteratorVar(i), startVal(s), endVal(e), body(b) {}
                                                                                                                                                                                };

                                                                                                                                                                                // YENİ: Döngü Kırıcılar
                                                                                                                                                                                class BreakNode : public ASTNode {};
                                                                                                                                                                                class ContinueNode : public ASTNode {};

                                                                                                                                                                                class FunctionCallNode : public ASTNode {
                                                                                                                                                                                public:
                                                                                                                                                                                    std::string functionName;
                                                                                                                                                                                        std::vector<Argument> arguments;
                                                                                                                                                                                            FunctionCallNode(std::string n, std::vector<Argument> args) : functionName(n), arguments(args) {}
                                                                                                                                                                                            };

                                                                                                                                                                                            class AsmNode : public ASTNode {
                                                                                                                                                                                            public:
                                                                                                                                                                                                std::string instruction;
                                                                                                                                                                                                    AsmNode(std::string i) : instruction(i) {}
                                                                                                                                                                                                    };

                                                                                                                                                                                                    #endif
                                                                                                                                                                                                    