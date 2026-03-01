#include "../include/v_runtime.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace v_std {
    // V dilindeki readFile() komutunun donanım karşılığı
    std::string readFile(const std::string& path) {
        std::ifstream file(path);
        if (!file.is_open()) {
            throw std::runtime_error("Dosya bulunamadi veya erisim reddedildi: " + path);
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
}
