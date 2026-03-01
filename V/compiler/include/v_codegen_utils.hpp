#pragma once
#include <string>

namespace v_std {
    void print(const std::string& text);
    void print(long long num);
    
    // YENI: Renkli terminal ciktisi
    void print_color(const std::string& text, const std::string& color);
    
    std::string readFile(const std::string& path);
    std::string concat(const std::string& a, const std::string& b);
}
