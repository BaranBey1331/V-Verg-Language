#include <iostream>
#include <string>
#include "vtml_dom.hpp"

// === V-ENGINE KÖPRÜSÜ (C-ABI) ===
// Transpiler'ın (V Dilinin) doğrudan çağıracağı saf makine kodu kapıları
extern "C" {

    // 1. Motor Kurulumu
    void vtml_setup() {
        std::cout << "\033[1;36m[VTML-CORE]\033[0m High-Performance UI Engine Online. DOM Parser Active.\n";
    }

    // 2. Arayüz Çizici (Layout Renderer)
    void vtml_render(const char* layout_string) {
        std::cout << "\033[1;32m[VTML-RENDER]\033[0m Parsing & Rendering Layout...\n";
        // İleride DOM Parse işlemi burada tetiklenecek:
        // VTMLParser parser(layout_string);
        // VTMLNode* dom_tree = parser.parse();
    }

    // 3. Etkileşimli Buton Yaratıcı
    void vtml_create_button(const char* id, const char* label) {
        std::cout << "\033[1;33m[VTML-UI]\033[0m Button Created -> ID: [" << id << "] Label: " << label << "\n";
    }

    // 4. (Oyun/Sandbox) ESP Çizici - Ekrana doğrudan müdahale
    void vtml_draw_esp(float x, float y, const char* label) {
        std::cout << "\033[1;35m[VTML-OVERLAY]\033[0m ESP Drawn at X: " << x << ", Y: " << y << " [" << label << "]\n";
    }

} // extern "C" sonu
