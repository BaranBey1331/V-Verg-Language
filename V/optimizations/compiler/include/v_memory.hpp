#pragma once
#include <cstddef>
#include <cstdint>

namespace v_core {
    // === V-ARENA (BUMP ALLOCATOR) ===
        // Isletim sistemi (Kernel) gecikmelerini yok eder.
            // Degiskenler RAM'de sirayla, CPU L1 Cache'ini %100 dolduracak sekilde dizilir.
                class ArenaAllocator {
                    private:
                            uint8_t* buffer;
                                    size_t capacity;
                                            size_t offset;
                                                public:
                                                        ArenaAllocator(size_t size);
                                                                ~ArenaAllocator();
                                                                        
                                                                                // 1 CPU Cycle suren inanilmaz hizli bellek tahsisi
                                                                                        void* alloc(size_t size);
                                                                                                
                                                                                                        // C++'in delete/free hamalligini silip atar. Aninda (O(1)) bellek temizligi!
                                                                                                                void reset(); 
                                                                                                                    };

                                                                                                                        // V-Engine'in 64MB'lik Ana Cekirdek Bellek Alani (Global Instance)
                                                                                                                            extern ArenaAllocator EngineArena;
                                                                                                                            }
                                                                                                                            