#pragma once

namespace VDiscordAPI {
    // English-first, highly functional BAN endpoints
    void banUser(const char* guild_id, const char* user_id, const char* reason, int prune_days);
    void unbanUser(const char* guild_id, const char* user_id, const char* reason);
    
    // V-Engine Exclusive Ban Features
    void softBan(const char* guild_id, const char* user_id, const char* reason); // Ban & instant unban to clear messages
    void networkBan(const char* guild_id, const char* user_id, const char* reason); // Ban user and all known alts
    void shadowBan(const char* guild_id, const char* user_id); // Ghost-ban at the gateway level
}
