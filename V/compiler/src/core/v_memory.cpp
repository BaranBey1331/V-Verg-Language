#include "v_memory.hpp"
#include <cstdlib>
#include <iostream>

namespace v_core {
    
    // Motor baslarken isletim sisteminden tek bir buyuk parca kopaririz.
    ArenaAllocator::ArenaAllocator(size_t size) : capacity(size), offset(0) {
        buffer = static_cast<uint8_t*>(std::malloc(size));
        if (!buffer) {
            std::cerr << "\033[1;31m[KRIZ]\033[0m V-Engine Isletim Sisteminden RAM koparamadi!\n";
            std::exit(1);
        }
    }

    ArenaAllocator::~ArenaAllocator() {
        std::free(buffer);
    }

    // Isletim sistemine sormadan, kendi ayirdigimiz alandan milisaniyesinde RAM veriyoruz
    void* ArenaAllocator::alloc(size_t size) {
        // CPU Cache (Önbellek) hizalamasi (8 byte align) - Saf donanim hizi icin!
        size_t aligned_size = (size + 7) & ~7; 
        
        if (offset + aligned_size > capacity) {
            std::cerr << "\033[1;31m[MEMORY PANIC]\033[0m V-Arena Doldu! Kapasite: " << capacity << " bayt\n";
            std::exit(1);
        }
        
        void* ptr = buffer + offset;
        offset += aligned_size; // Sadece sayiyi artir (O(1) Karmaşıklık)
        return ptr;
    }

    // Binlerce degiskeni tek seferde, 0 maliyetle yok et.
    void ArenaAllocator::reset() {
        offset = 0; 
    }

    // V-Engine icin otonom olarak 64 MB Ultra-Hizli RAM rezerve ediliyor!
    ArenaAllocator EngineArena(64 * 1024 * 1024);
}
