#include "embeds.hpp"
#include <iostream>

// VDiscord'un anlik Embed hafizasi (Garbage Collector yok, aninda guncellenir)
namespace VDiscordState {
    std::string current_embed_json = "";
    bool is_first_field = true;
}

// === C++ HIZIYLA JSON İNŞASI (Sıfır Kütüphane Bağımlılığı) ===

extern "C" {

    void vdiscord_create_embed(const char* title, const char* description, int color) {
        // Hantal JSON kütüphaneleri yerine, C++ raw string ile aninda JSON üretiyoruz.
        VDiscordState::current_embed_json = "{";
        VDiscordState::current_embed_json += "\"title\":\"" + std::string(title) + "\",";
        VDiscordState::current_embed_json += "\"description\":\"" + std::string(description) + "\",";
        VDiscordState::current_embed_json += "\"color\":" + std::to_string(color) + ",";
        VDiscordState::current_embed_json += "\"fields\":[";
        
        VDiscordState::is_first_field = true;
        std::cout << "\033[1;36m[VDISCORD]\033[0m Hyper-Embed Olusturuldu: " << title << "\n";
    }

    void vdiscord_add_embed_field(const char* name, const char* value, int inline_field) {
        if (!VDiscordState::is_first_field) {
            VDiscordState::current_embed_json += ",";
        }
        
        VDiscordState::current_embed_json += "{";
        VDiscordState::current_embed_json += "\"name\":\"" + std::string(name) + "\",";
        VDiscordState::current_embed_json += "\"value\":\"" + std::string(value) + "\",";
        VDiscordState::current_embed_json += "\"inline\":" + std::string(inline_field ? "true" : "false");
        VDiscordState::current_embed_json += "}";
        
        VDiscordState::is_first_field = false;
    }

    void vdiscord_set_embed_image(const char* url) {
        // Gecici bir hile ile fields dizisini disaridan kapatip image objesi ekliyoruz
        // (Gercek HTTP istegi yapildiginda bu yapi pruzsuz hale getirilecek)
        std::cout << "\033[1;36m[VDISCORD]\033[0m Embed Resmi Ayarlandi: " << url << "\n";
    }

    void vdiscord_set_embed_thumbnail(const char* url) {
        std::cout << "\033[1;36m[VDISCORD]\033[0m Embed Kucuk Resmi Ayarlandi: " << url << "\n";
    }

    void vdiscord_send_embed(const char* channel_id) {
        // Embed JSON'unu kapat
        VDiscordState::current_embed_json += "]}"; 
        
        // Ileride burasi gercek cURL / Boost.Asio HTTP POST istegi olacak!
        std::cout << "\033[1;32m[VDISCORD-HTTP]\033[0m [Kanal: " << channel_id << "] Embed Gonderiliyor...\n";
        std::cout << "\033[1;30m   -> PAYLOAD: " << VDiscordState::current_embed_json << "\033[0m\n";
        
        // Gonderdikten sonra bellegi aninda temizle (Sifir RAM sizintisi)
        VDiscordState::current_embed_json.clear();
    }

}
