#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

extern "C" {

    // .vdj uzantili dosyalar bu fonksiyona duser!
    void vdiscord_compile_vdj(const char* filepath) {
        std::cout << "\033[1;35m[VDJ-COMPILER]\033[0m VDiscord Ozel Derleyicisi Devrede: " << filepath << "\n";
        
        std::ifstream infile(filepath);
        if (!infile.is_open()) {
            std::cerr << "\033[1;31m[HATA]\033[0m .vdj dosyasi okunamadi!\n";
            return;
        }

        // VDiscord Otonom Kod Enjeksiyonu
        std::string processed_code = "// VDiscord Otonom Enjeksiyonu\n";
        processed_code += "std.print_color(\"[VDJ Core] Discord Aglarina Baglaniliyor...\", \"mor\")\n\n";
        
        std::string line;
        while (std::getline(infile, line)) {
            processed_code += line + "\n";
        }
        infile.close();

        // Islemi tamamlanmis gecici bir .v dosyasi uret ve Ana Motora gonder
        std::string temp_file = "temp_vdj_compiled.v";
        std::ofstream outfile(temp_file);
        outfile << processed_code;
        outfile.close();

        std::cout << "\033[1;36m[VDJ-COMPILER]\033[0m Kod islendi, Ana V-Engine'e devrediliyor...\n";
        
        // Ana V-Engine'i cagirip islenmis dosyayi derletiyoruz
        std::string cmd = "./v_compiler " + temp_file;
        std::system(cmd.c_str());
        
        // Temizlik
        std::remove(temp_file.c_str());
    }

}
