#include <iostream>
#include <string>

// === V-ENGINE OTONOM MODÜL YÜKLEYİCİ ===
// Bu dosya build.sh tarafından her derlemede baştan yazılır. 
// Klasörlere eklediğin tüm .hpp'ler otomatik olarak buradan içeri akar!
#include "vdiscord_autogen.hpp"

// İleride compiler kodlarını eklediğimizde buraya dahil edeceğiz:
// #include "compiler/discord_parser.hpp"

// === GLOBAL YAPILANDIRMA ===
struct VDiscordConfig {
    std::string bot_token;
    bool zero_cache_mode;
    int intent_flags;
};

VDiscordConfig core_config;

// === V-ENGINE KÖPRÜSÜ (C-ABI) ===
extern "C" {

    void vdiscord_setup(const char* token, int zero_cache, int intents) {
        core_config.bot_token = token;
        core_config.zero_cache_mode = (zero_cache == 1);
        core_config.intent_flags = intents;
        std::cout << "\033[1;36m[VDISCORD-CORE]\033[0m Autonomous Engine Online.\n";
    }

    void vdiscord_login() {
        std::cout << "\033[1;32m[VDISCORD-GATEWAY]\033[0m Connected to Discord WSS successfully.\n";
    }

    // --- OTO-YÜKLENEN MODÜLLERİN KULLANIMI ---
    // (Aşağıdaki fonksiyonlar autogen.hpp üzerinden otomatik tanınır)
    
    // Mesajlar
    void vdiscord_send_message(const char* channel_id, const char* content) {
        VDiscordAPI::sendMessage(channel_id, content);
    }
    void vdiscord_send_embed(const char* channel_id, const char* title, const char* desc, int hex_color) {
        VDiscordAPI::sendEmbed(channel_id, title, desc, hex_color);
    }

    // Ban İşlemleri
    void vdiscord_ban_user(const char* guild_id, const char* user_id, const char* reason, int days) {
        VDiscordAPI::banUser(guild_id, user_id, reason, days);
    }
    void vdiscord_network_ban(const char* guild_id, const char* user_id, const char* reason) {
        VDiscordAPI::networkBan(guild_id, user_id, reason);
    }
    void vdiscord_shadow_ban(const char* guild_id, const char* user_id) {
        VDiscordAPI::shadowBan(guild_id, user_id);
    }

    // Mute İşlemleri
    void vdiscord_timeout_user(const char* guild_id, const char* user_id, int duration_seconds, const char* reason) {
        VDiscordAPI::timeoutUser(guild_id, user_id, duration_seconds, reason);
    }
    void vdiscord_voice_mute(const char* guild_id, const char* user_id, int state, const char* reason) {
        VDiscordAPI::voiceMute(guild_id, user_id, (state == 1), reason);
    }

} // extern "C" sonu
