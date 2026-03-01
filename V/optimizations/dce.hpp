#ifndef DCE_HPP
#define DCE_HPP

#include "../compiler/include/core.hpp"
#include <vector>
#include <iostream>

class DeadCodeEliminator {
public:
    std::vector<ASTNode*> optimize(std::vector<ASTNode*> nodes) {
        std::vector<ASTNode*> optimizedNodes;
        int removed = 0;

        for (ASTNode* node : nodes) {
            // 1. KENDİNE ATAMA SİLİCİ (Örn: x = x)
            if (auto* reNode = dynamic_cast<ReassignNode*>(node)) {
                if (reNode->arg.type == ARG_ID && reNode->targetVar == reNode->arg.value) {
                    removed++;
                    continue; // Bu gereksiz kodu sil, işlemciye yollama!
                }
            }
            
            // 2. BOŞ IF BLOKLARI SİLİCİ
            if (auto* ifNode = dynamic_cast<IfNode*>(node)) {
                ifNode->body = optimize(ifNode->body);
                ifNode->elseBody = optimize(ifNode->elseBody);
                
                // İçi tamamen boşsa, if şartını CPU'ya hiç gönderme
                if (ifNode->body.empty() && ifNode->elseBody.empty()) {
                    removed++;
                    continue; 
                }
            }

            // 3. BOŞ WHILE DÖNGÜSÜ SİLİCİ
            if (auto* whileNode = dynamic_cast<WhileNode*>(node)) {
                whileNode->body = optimize(whileNode->body);
                if (whileNode->body.empty()) {
                    removed++;
                    continue;
                }
            }

            // 4. BOŞ FOR DÖNGÜSÜ SİLİCİ
            if (auto* forNode = dynamic_cast<ForNode*>(node)) {
                forNode->body = optimize(forNode->body);
                if (forNode->body.empty()) {
                    removed++;
                    continue;
                }
            }

            optimizedNodes.push_back(node);
        }

        if (removed > 0) {
            std::cout << "\033[1;36m[V-DCE]\033[0m " << removed << " adet olu/gereksiz kod blogu CPU'dan silindi!\n";
        }
        return optimizedNodes;
    }
};

#endif
