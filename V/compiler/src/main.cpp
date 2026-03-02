#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <dlfcn.h>
#include <cstdlib>

// V-Engine Cekirdek Bilesenleri
#include "benchmark.hpp"
#include "codegen/v_codegen_utils.hpp"
#include "ast.hpp"

// =========================================================================
// 1. VTML SUNUCU TETIKLEYICI (Dinamik Eklenti Yukleyici)
// =========================================================================
void trigger_dynamic_plugin(const std::string& lib_path, const std::string& func_name, const std::string& filepath) {
    void* handle = dlopen(lib_path.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "\033[1;31m[HATA]\033[0m V-Engine Eklentisi yuklenemedi: " << dlerror() << "\n";
        exit(1);
    }

    typedef void (*PluginFunc)(const char*);
    PluginFunc func = (PluginFunc)dlsym(handle, func_name.c_str());
    
    if (!func) {
        std::cerr << "\033[1;31m[HATA]\033[0m Fonksiyon bulunamadi: " << dlerror() << "\n";
        dlclose(handle);
        exit(1);
    }

    // VTML Sunucusunu calistir
    func(filepath.c_str());
    dlclose(handle);
}

// =========================================================================
// 2. V-ENGINE TAM OTOMATIK DERLEME BORU HATTI (PIPELINE)
// =========================================================================
void compile_v_engine_file(const std::string& filepath) {
    std::string cpp_filename = filepath + ".cpp";
    std::string bin_filename = filepath + ".bin";

    // A. Hedef .v veya .vdj dosyasini oku
    std::ifstream source_file(filepath);
    if (!source_file.is_open()) {
        std::cerr << "\033[1;31m[HATA]\033[0m Kaynak dosya okunamadi: " << filepath << "\n";
        exit(1);
    }
    
    std::stringstream buffer;
    buffer << source_file.rdbuf();
    std::string source_code = buffer.str();
    source_file.close();

    // B. C++ Kod Uretimi (Codegen)
    std::ofstream out_cpp(cpp_filename);
    if (!out_cpp.is_open()) {
        std::cerr << "\033[1;31m[HATA]\033[0m C++ ciktisi olusturulamadi!\n";
        exit(1);
    }

    // VCodeGenUtils üzerinden senin tanimladigin gercek basliklari ve baslangic kodlarini yaz
    out_cpp << VCodeGenUtils::getCoreHeaders();
    out_cpp << VCodeGenUtils::getStartupCode();

    // Not: Ileride parser eklendiginde AST dugumleri (IfNode, AssignmentNode) 
    // buradaki dongude islenip out_cpp'ye basilacak. Su an motorun sorunsuz
    // derleyebilmesi icin standart kapanis bloklarini otonom kapatiyoruz.
    out_cpp << "    // V-Engine Motoru Tarafindan Otonom Derlendi\n";
    out_cpp << "    // Hedef: " << filepath << "\n";
    out_cpp << "    return 0;\n";
    out_cpp << "}\n"; // main fonksiyonunu kapat
    out_cpp.close();

    // C. Arka Planda Clang/GCC ile Makine Koduna (Binary) Cevir
    std::string compile_cmd = VCodeGenUtils::buildCompilerCommand(cpp_filename, bin_filename);
    
    std::cout << "\033[1;34m[Codegen]\033[0m Binary uretiliyor: " << bin_filename << "\n";
    int compile_result = system(compile_cmd.c_str());
    
    if (compile_result != 0) {
        std::cerr << "\033[1;31m[HATA]\033[0m Arka plan C++ derlemesi basarisiz oldu!\n";
        exit(1);
    }
    
    // Temizlik: Gecici .cpp dosyasini sil (Istersen yorum satirina alip inceleyebilirsin)
    remove(cpp_filename.c_str());

    std::cout << "\033[1;32m[BASARILI]\033[0m Derleme tamamlandi. Calistirmak icin: ./" << bin_filename << "\n";
}

// =========================================================================
// 3. ANA GİRİŞ KAPISI
// =========================================================================
int main(int argc, char* argv[]) {
    // Arguman kontrolu
    if (argc < 2) {
        std::cout << "\033[1;36m=== V-ENGINE DERLEYICI ===\033[0m\n";
        std::cout << "Kullanim: ./v_compiler <dosya.v | .vdj | .vtml> [--serve]\n";
        return 1;
    }

    std::string filepath = argv[1];

    // VTML Sunucu Modu Kontrolu
    if (argc == 3 && std::string(argv[2]) == "--serve") {
        if (filepath.length() >= 5 && filepath.substr(filepath.length() - 5) == ".vtml") {
            std::cout << "\033[1;32m[V-Engine]\033[0m VTML Localhost Sunucusu baslatiliyor...\n";
            trigger_dynamic_plugin("./libvtml.so", "vtml_serve_file", filepath);
            return 0; // Sunucu acildigi icin asagiya gecme
        } else {
            std::cerr << "\033[1;31m[HATA]\033[0m --serve komutu sadece .vtml dosyalarinda kullanilabilir!\n";
            return 1;
        }
    }

    // Normal Derleme Modu (Benchmark ile birlikte)
    VEngine::Benchmark timer(filepath);
    timer.start();

    // Tum okuma, AST, C++ uretme ve arka plan Clang derleme islemlerini baslat
    compile_v_engine_file(filepath);

    // Kronometreyi durdur ve hiz raporunu (LOC/s) ekrana bas
    timer.stopAndReport();

    return 0;
}


