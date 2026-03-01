#include <iostream>

extern "C" {
    void vsupport_init() {
        std::cout << "[VSupport] Modulu basariyla yuklendi.\n";
    }
}
