#pragma once // Bu dosyanın belleğe iki kere yüklenmesini engeller

namespace VDiscordAPI {
    // English-first, zero-delay function declarations
    void sendMessage(const char* channel_id, const char* content);
    void sendEmbed(const char* channel_id, const char* title, const char* description, int hex_color);
}
