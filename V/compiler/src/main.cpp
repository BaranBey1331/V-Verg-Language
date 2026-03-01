#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <dlfcn.h> 

#include "lexer.hpp"
#include "parser.hpp"
#include "optimizer.hpp" // YENI BEYIN EKLENDI
#include "codegen.hpp"

void trigger_dynamic_plugin(const std::string& so_file, const std::string& function_name, const std::string& argument) {
    void* handle = dlopen(so_file.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "\033[1;31m[PLUGIN HATASI]\033[0m " << dlerror() << "\n";
        return;
    }
    typedef void (*PluginFunc)(const char*);
    PluginFunc func = (PluginFunc)dlsym(handle, function_name.c_str());
    if (dlerror()) { dlclose(handle); return; }
    func(argument.c_str());
    dlclose(handle);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "\033[1;31m[HATA]\033[0m Lutfen islenecek bir .v dosyasi belirtin.\n";
        return 1;
    }

    std::string filepath = argv[1];
    
    // === YENİ: .vdj (V Discord JS) Uzantısı Algılayıcı ===
    if (filepath.length() >= 4 && filepath.substr(filepath.length() - 4) == ".vdj") {
        trigger_dynamic_plugin("./libvdiscord.so", "vdiscord_compile_vdj", filepath);
        return 0; // İşi VDiscord derleyicisi devraldı, ana motor durur.
    }

    if (filepath.length() >= 5 && filepath.substr(filepath.length() - 5) == ".vlua") {
        trigger_dynamic_plugin("./libvlua.so", "v_run_vlua", filepath);
        return 0; 
    }

    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "\033[1;31m[HATA]\033[0m Dosya acilamadi: " << filepath << "\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string sourceCode = buffer.str();

    // 1. Oku ve Ağaç Çıkar
    Lexer lexer(sourceCode);
    std::vector<Token> tokens = lexer.tokenize();
    Parser parser(tokens);
    std::vector<ASTNode*> ast = parser.parseAll();

    // 2. V-OPTİMİZATÖR (C++'IN AKLINA GELMEYEN BİTSEL HİLELER)
    Optimizer::optimize(ast);

    // 3. Transpiler ve Native Derleyiciyi Ateşle!
    CodeGenerator transpiler;
    std::string cpp_out = "v_output_temp.cpp";
    std::string binary_out = "v_program";

    transpiler.generateCPP(ast, cpp_out);
    transpiler.compileToBinary(cpp_out, binary_out);

    return 0;
}
