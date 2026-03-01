#include "../include/v_runtime.hpp"
#include <cstdio>
#include <string>

namespace v_std {
    void print(const std::string& text) {
        std::printf("%s\n", text.c_str());
    }
    
    void print(long long num) {
        std::printf("%lld\n", num);
    }
    
    // YENI: V-Engine Renkli Konsol Motoru
    void print_color(const std::string& text, const std::string& color) {
        std::string ansi_code = "\033[0m"; // Varsayilan (Reset)
        
        if (color == "kirmizi" || color == "red") ansi_code = "\033[31m";
        else if (color == "yesil" || color == "green") ansi_code = "\033[32m";
        else if (color == "sari" || color == "yellow") ansi_code = "\033[33m";
        else if (color == "mavi" || color == "blue") ansi_code = "\033[34m";
        else if (color == "mor" || color == "purple") ansi_code = "\033[35m";
        else if (color == "turkuaz" || color == "cyan") ansi_code = "\033[36m";

        // Gecikmesiz saf C yazdirma (Printf)
        std::printf("%s%s\033[0m\n", ansi_code.c_str(), text.c_str());
    }

    std::string concat(const std::string& a, const std::string& b) {
        return a + b;
    }
}
