#pragma once
#include <string>
#include <vector>

// VDiscord C-ABI (V dilinden dogrudan cagrilacak fonksiyonlar)
extern "C" {
    // Yeni bir Embed baslatir (RAM'de aninda yer ayirir)
    void vdiscord_create_embed(const char* title, const char* description, int color);
    
    // Embed'e otonom tarama hizinda Field (Alan) ekler
    void vdiscord_add_embed_field(const char* name, const char* value, int inline_field);
    
    // Embed'e resim veya thumbnail ekler
    void vdiscord_set_embed_image(const char* url);
    void vdiscord_set_embed_thumbnail(const char* url);
    
    // Olusturulan Embed'i kanala firlatir (Aga gonderir)
    void vdiscord_send_embed(const char* channel_id);
}
