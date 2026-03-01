#include "mute.hpp"
#include <iostream>

namespace VDiscordAPI {

    void timeoutUser(const char* guild_id, const char* user_id, int duration_seconds, const char* reason) {
        std::cout << "\033[1;35m[VDISCORD-TIMEOUT]\033[0m Applied -> User: " << user_id << " | Time: " << duration_seconds << "s\n";
    }

    void removeTimeout(const char* guild_id, const char* user_id, const char* reason) {
        std::cout << "\033[1;32m[VDISCORD-TIMEOUT]\033[0m Removed -> User: " << user_id << "\n";
    }

    void voiceDeafen(const char* guild_id, const char* user_id, bool state, const char* reason) {
        std::string status = state ? "DEAFENED" : "UNDEAFENED";
        std::cout << "\033[1;34m[VDISCORD-VOICE]\033[0m " << status << " -> User: " << user_id << "\n";
    }

    void voiceMute(const char* guild_id, const char* user_id, bool state, const char* reason) {
        std::string status = state ? "MUTED" : "UNMUTED";
        std::cout << "\033[1;34m[VDISCORD-VOICE]\033[0m " << status << " -> User: " << user_id << "\n";
    }
}
