#ifndef OPTIMIZER_HPP
#define OPTIMIZER_HPP

#include "core.hpp"
#include <vector>
#include <iostream>
#include <string>

class Optimizer {
public:
    std::vector<ASTNode*> optimize(std::vector<ASTNode*> nodes) {
        std::vector<ASTNode*> optimizedNodes;
        int folded = 0;
        int eliminated = 0;

        for (ASTNode* node : nodes) {
            
            // IF VE ELSE BLOKLARI İÇİN OPTİMİZASYON VE ÖLÜ KOD SİLME (DCE)
            if (auto* ifNode = dynamic_cast<IfNode*>(node)) {
                ifNode->body = optimize(ifNode->body);
                if (!ifNode->elseBody.empty()) {
                    ifNode->elseBody = optimize(ifNode->elseBody);
                }
                
                // V-TURBO: Şartlar sabitse (Örn: if 10 > 5), işlemi CPU'ya yollama!
                // Doğrudan True veya False bloğunu koda yapıştır, If'i tamamen sil.
                if (ifNode->cond.left.type == ARG_NUMBER && ifNode->cond.right.type == ARG_NUMBER) {
                    long long l = std::stoll(ifNode->cond.left.value);
                    long long r = std::stoll(ifNode->cond.right.value);
                    bool isTrue = false;
                    
                    if (ifNode->cond.op == "<") isTrue = l < r;
                    else if (ifNode->cond.op == ">") isTrue = l > r;
                    else if (ifNode->cond.op == "==") isTrue = l == r;
                    
                    if (isTrue) {
                        for(auto* n : ifNode->body) optimizedNodes.push_back(n); // Sadece True çalışır
                        eliminated++;
                        continue;
                    } else {
                        for(auto* n : ifNode->elseBody) optimizedNodes.push_back(n); // Sadece False çalışır
                        eliminated++;
                        continue;
                    }
                }
            } 
            else if (auto* whileNode = dynamic_cast<WhileNode*>(node)) {
                whileNode->body = optimize(whileNode->body);
                // V-TURBO: while(0) gibi imkansız bir döngü varsa, kodu tamamen çöpe at!
                if (whileNode->cond.left.type == ARG_NUMBER && whileNode->cond.right.type == ARG_NUMBER) {
                     long long l = std::stoll(whileNode->cond.left.value);
                     long long r = std::stoll(whileNode->cond.right.value);
                     bool isTrue = false;
                     if (whileNode->cond.op == "<") isTrue = l < r;
                     else if (whileNode->cond.op == ">") isTrue = l > r;
                     else if (whileNode->cond.op == "==") isTrue = l == r;
                     
                     if (!isTrue) { eliminated++; continue; }
                }
            }
            else if (auto* forNode = dynamic_cast<ForNode*>(node)) {
                forNode->body = optimize(forNode->body);
            }
            
            // SABİT KATLAMA VE CEBİRSEL SADELEŞTİRME (Algebraic Simplification)
            if (auto* mathNode = dynamic_cast<MathAssignNode*>(node)) {
                
                if (mathNode->arg1.type == ARG_NUMBER && mathNode->arg2.type == ARG_NUMBER) {
                    long long val1 = std::stoll(mathNode->arg1.value);
                    long long val2 = std::stoll(mathNode->arg2.value);
                    long long result = 0;

                    if (mathNode->op == "+") result = val1 + val2;
                    else if (mathNode->op == "-") result = val1 - val2;
                    else if (mathNode->op == "*") result = val1 * val2;
                    else if (mathNode->op == "/") { if (val2 != 0) result = val1 / val2; }
                    else if (mathNode->op == "%") { if (val2 != 0) result = val1 % val2; }

                    Argument newArg = {ARG_NUMBER, std::to_string(result), {}};
                    optimizedNodes.push_back(new ReassignNode(mathNode->targetVar, newArg));
                    folded++;
                    continue;
                }
                
                // V-TURBO: Cebirsel Zeka (x + 0 = x, x * 1 = x) CPU'yu yormasın!
                if (mathNode->arg2.type == ARG_NUMBER) {
                    long long val2 = std::stoll(mathNode->arg2.value);
                    if ((mathNode->op == "+" && val2 == 0) || (mathNode->op == "-" && val2 == 0) || 
                        (mathNode->op == "*" && val2 == 1) || (mathNode->op == "/" && val2 == 1)) {
                        
                        optimizedNodes.push_back(new ReassignNode(mathNode->targetVar, mathNode->arg1));
                        eliminated++;
                        continue;
                    }
                }
            }
            
            optimizedNodes.push_back(node);
        }
        
        return optimizedNodes;
    }
};

#endif
