#pragma once
#include <vector>
#include <string>

// AST Düğümü (Parser'dan gelecek olan veri yapısı)
class ASTNode; 

class CodeGenerator {
private:
    std::string cpp_code;
        int indent_level;

            // Kod yazma yardımcıları
                void write(const std::string& text);
                    void writeLine(const std::string& text);
                        void indent();

                            // Düğümleri (Komutları) işleyen fonksiyon
                                void visit(ASTNode* node);

                                public:
                                    CodeGenerator();
                                        
                                            // 1. Adım: V kodunu alıp C++ koduna çevirir (Transpile)
                                                void generateCPP(const std::vector<ASTNode*>& ast, const std::string& out_filename);
                                                    
                                                        // 2. Adım: Üretilen C++ kodunu saf makine koduna çevirir
                                                            void compileToBinary(const std::string& cpp_filename, const std::string& bin_filename);
                                                            };
                                                            