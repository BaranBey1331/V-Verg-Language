#pragma once

namespace VDiscordAPI {
    // English-first, highly functional MUTE endpoints
    void timeoutUser(const char* guild_id, const char* user_id, int duration_seconds, const char* reason);
    void removeTimeout(const char* guild_id, const char* user_id, const char* reason);
    
    // Voice Moderation
    void voiceDeafen(const char* guild_id, const char* user_id, bool state, const char* reason); // Sağırlaştırma (Deafen)
    void voiceMute(const char* guild_id, const char* user_id, bool state, const char* reason); // Mikrofon kapatma
}
