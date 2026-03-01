#pragma once
#include <string>
#include <vector>

class ASTNode {
public:
    virtual ~ASTNode() = default;
        virtual std::string nodeType() const = 0;
        };

        class NumberNode : public ASTNode {
        public:
            std::string value;
                NumberNode(const std::string& val) : value(val) {}
                    std::string nodeType() const override { return "Number"; }
                    };

                    class StringNode : public ASTNode {
                    public:
                        std::string value;
                            StringNode(const std::string& val) : value(val) {}
                                std::string nodeType() const override { return "String"; }
                                };

                                class IdentifierNode : public ASTNode {
                                public:
                                    std::string name;
                                        IdentifierNode(const std::string& n) : name(n) {}
                                            std::string nodeType() const override { return "Identifier"; }
                                            };

                                            class VarDeclNode : public ASTNode {
                                            public:
                                                std::string var_name;
                                                    ASTNode* value;
                                                        VarDeclNode(const std::string& name, ASTNode* val) : var_name(name), value(val) {}
                                                            std::string nodeType() const override { return "VarDecl"; }
                                                            };

                                                            class AssignmentNode : public ASTNode {
                                                            public:
                                                                std::string var_name;
                                                                    ASTNode* value;
                                                                        AssignmentNode(const std::string& name, ASTNode* val) : var_name(name), value(val) {}
                                                                            std::string nodeType() const override { return "Assignment"; }
                                                                            };

                                                                            class BinaryOpNode : public ASTNode {
                                                                            public:
                                                                                ASTNode* left;
                                                                                    std::string op;
                                                                                        ASTNode* right;
                                                                                            BinaryOpNode(ASTNode* l, const std::string& o, ASTNode* r) : left(l), op(o), right(r) {}
                                                                                                std::string nodeType() const override { return "BinaryOp"; }
                                                                                                };

                                                                                                class MethodCallNode : public ASTNode {
                                                                                                public:
                                                                                                    std::string object_name;
                                                                                                        std::string method_name;
                                                                                                            std::vector<ASTNode*> arguments;
                                                                                                                MethodCallNode(const std::string& obj, const std::string& method) : object_name(obj), method_name(method) {}
                                                                                                                    std::string nodeType() const override { return "MethodCall"; }
                                                                                                                    };

                                                                                                                    class IfNode : public ASTNode {
                                                                                                                    public:
                                                                                                                        ASTNode* condition;
                                                                                                                            std::vector<ASTNode*> if_body;
                                                                                                                                std::vector<ASTNode*> else_body;
                                                                                                                                    IfNode(ASTNode* cond) : condition(cond) {}
                                                                                                                                        std::string nodeType() const override { return "If"; }
                                                                                                                                        };

                                                                                                                                        class WhileNode : public ASTNode {
                                                                                                                                        public:
                                                                                                                                            ASTNode* condition;
                                                                                                                                                std::vector<ASTNode*> body;
                                                                                                                                                    WhileNode(ASTNode* cond) : condition(cond) {}
                                                                                                                                                        std::string nodeType() const override { return "While"; }
                                                                                                                                                        };
                                                                                                                                                        