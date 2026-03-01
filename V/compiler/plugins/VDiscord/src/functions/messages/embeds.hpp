#pragma once

namespace VDiscordAPI {
    void createEmbed(const char* title, const char* desc, int color);
    void addEmbedField(const char* name, const char* value, int inlineField);
    void setEmbedImage(const char* url);
    void setEmbedThumbnail(const char* url);
    void sendEmbed(const char* channel_id);
}
