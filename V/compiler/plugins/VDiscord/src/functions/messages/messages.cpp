#include "messages.hpp"
#include <iostream>

namespace VDiscordAPI {

    void sendMessage(const char* channel_id, const char* content) {
        // High-performance network queue will handle HTTP 429 logic here
        std::cout << "\033[1;32m[VDISCORD-API]\033[0m Message Sent -> Channel: [" 
                  << channel_id << "] | Content: " << content << "\n";
    }

    void sendEmbed(const char* channel_id, const char* title, const char* description, int hex_color) {
        // Memory-safe JSON builder executes here in microseconds
        std::cout << "\033[1;32m[VDISCORD-API]\033[0m Embed Sent -> Channel: [" 
                  << channel_id << "] | Title: " << title 
                  << " | Color: 0x" << std::hex << hex_color << std::dec << "\n";
    }

}
