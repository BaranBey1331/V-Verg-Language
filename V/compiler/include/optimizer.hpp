#pragma once
#include "ast.hpp"
#include <vector>

// === V-ENGINE OTONOM OPTİMİZATÖR ===
// Kod makineye veya C++'a çevrilmeden önce matematiksel işlemleri
// donanımın en hızlı anlayacağı formata (Bitwise) dönüştürür.

class Optimizer {
public:
    // Ana optimizasyon başlatıcı
    static void optimize(std::vector<ASTNode*>& ast);

private:
    // Ağacın dallarında gezinen rekürsif fonksiyon
    static void optimizeNode(ASTNode*& node);
    
    // Güç İndirgeme (Strength Reduction) Hileleri
    static void applyStrengthReduction(BinaryOpNode* bNode);
};
