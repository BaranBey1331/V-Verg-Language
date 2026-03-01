#include "optimizer.hpp"
#include <iostream>

void Optimizer::optimize(std::vector<ASTNode*>& ast) {
    for (auto& node : ast) {
        optimizeNode(node);
    }
    std::cout << "\033[1;35m[V-OPTIMIZER]\033[0m AST Agaci Mutlak Donanim Hizina (Bitwise) Optimize Edildi.\n";
}

void Optimizer::optimizeNode(ASTNode*& node) {
    if (!node) return;
    std::string type = node->nodeType();

    if (type == "While") {
        auto w = static_cast<WhileNode*>(node);
        optimizeNode(w->condition);
        for (auto& stmt : w->body) optimizeNode(stmt);
    } 
    else if (type == "If") {
        auto i = static_cast<IfNode*>(node);
        optimizeNode(i->condition);
        for (auto& stmt : i->if_body) optimizeNode(stmt);
        for (auto& stmt : i->else_body) optimizeNode(stmt);
    } 
    else if (type == "VarDecl") {
        auto v = static_cast<VarDeclNode*>(node);
        optimizeNode(v->value);
    } 
    else if (type == "Assignment") {
        auto a = static_cast<AssignmentNode*>(node);
        optimizeNode(a->value);
    } 
    else if (type == "BinaryOp") {
        auto b = static_cast<BinaryOpNode*>(node);
        optimizeNode(b->left);
        optimizeNode(b->right);
        
        // Matematiksel Güç İndirgeme (Strength Reduction) Uygula
        applyStrengthReduction(b);
    }
}

void Optimizer::applyStrengthReduction(BinaryOpNode* bNode) {
    // Sadece sağ tarafı sabit bir sayı ise optimizasyon yapabiliriz
    if (bNode->right->nodeType() == "Number") {
        auto rightNum = static_cast<NumberNode*>(bNode->right);
        
        // 1. KURAL: x % 2 işlemi -> (x & 1) olur (Muazzam hız artışı)
        if (bNode->op == "%" && rightNum->value == "2") {
            bNode->op = "&";
            rightNum->value = "1";
        }
        // 2. KURAL: x / 2 işlemi -> (x >> 1) olur
        else if (bNode->op == "/" && rightNum->value == "2") {
            bNode->op = ">>";
            rightNum->value = "1";
        }
        // 3. KURAL: x * 2 işlemi -> (x << 1) olur
        else if (bNode->op == "*" && rightNum->value == "2") {
            bNode->op = "<<";
            rightNum->value = "1";
        }
    }
}
