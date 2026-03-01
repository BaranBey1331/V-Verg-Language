#include <iostream>
#include <string>

extern "C" {

    // Discord.js'in yapamadigi, donanimdan dogrudan ANSI kodlu mesaj firlatma
    void vdiscord_send_colored(const char* channel_id, const char* text, const char* color) {
        std::string ansi_code = "0"; // Varsayilan

        // Discord ANSI Renk Kodlari
        std::string col_str = color;
        if (col_str == "kirmizi" || col_str == "red") ansi_code = "31";
        else if (col_str == "yesil" || col_str == "green") ansi_code = "32";
        else if (col_str == "sari" || col_str == "yellow") ansi_code = "33";
        else if (col_str == "mavi" || col_str == "blue") ansi_code = "34";
        else if (col_str == "mor" || col_str == "purple") ansi_code = "35";
        else if (col_str == "turkuaz" || col_str == "cyan") ansi_code = "36";

        // Discord'un algilayacagi Ozel ANSI Kod Blogu formatini insa ediyoruz
        std::string payload = "```ansi\n\\u001b[1;" + ansi_code + "m" + std::string(text) + "\\u001b[0m\n```";

        // HTTP istegi icin hazirlik
        std::cout << "\033[1;32m[VDISCORD-HTTP]\033[0m [Kanal: " << channel_id << "] Renkli Mesaj Gonderiliyor...\n";
        std::cout << "\033[1;30m   -> PAYLOAD: " << payload << "\033[0m\n";
    }

}
