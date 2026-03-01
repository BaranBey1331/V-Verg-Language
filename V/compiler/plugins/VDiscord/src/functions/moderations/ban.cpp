#include "ban.hpp"
#include <iostream>

namespace VDiscordAPI {

    void banUser(const char* guild_id, const char* user_id, const char* reason, int prune_days) {
        std::cout << "\033[1;31m[VDISCORD-BAN]\033[0m Executed -> User: " << user_id << " | Prune: " << prune_days << "d\n";
    }

    void unbanUser(const char* guild_id, const char* user_id, const char* reason) {
        std::cout << "\033[1;32m[VDISCORD-UNBAN]\033[0m Revoked -> User: " << user_id << "\n";
    }

    void softBan(const char* guild_id, const char* user_id, const char* reason) {
        std::cout << "\033[1;33m[VDISCORD-SOFTBAN]\033[0m Messages Cleared -> User: " << user_id << "\n";
    }

    void networkBan(const char* guild_id, const char* user_id, const char* reason) {
        std::cout << "\033[1;41m\033[1;37m[VDISCORD-NETBAN]\033[0m Alts Eliminated -> Target: " << user_id << "\n";
    }

    void shadowBan(const char* guild_id, const char* user_id) {
        std::cout << "\033[1;30m[VDISCORD-SHADOW]\033[0m Gateway Isolation -> Target: " << user_id << "\n";
    }
}
