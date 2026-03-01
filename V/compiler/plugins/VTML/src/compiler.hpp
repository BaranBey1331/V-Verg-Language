#ifndef VTML_COMPILER_HPP
#define VTML_COMPILER_HPP

#include <string>
#include <regex>
#include "components.hpp"

class VtmlCompiler {
public:
    static std::string compileLine(std::string line) {
        
        // 1. TEMEL DÜZEN VE İSKELET (Layouts)
        line = std::regex_replace(line, std::regex(R"REGEX(page\s*\{)REGEX"), "<div class='page'>");
        line = std::regex_replace(line, std::regex(R"REGEX(box\s*center\s*\{)REGEX"), "<div class='box center'>");
        line = std::regex_replace(line, std::regex(R"REGEX(box\s*\{)REGEX"), "<div class='box'>");
        line = std::regex_replace(line, std::regex(R"REGEX(row\s*\{)REGEX"), "<div class='row'>");
        line = std::regex_replace(line, std::regex(R"REGEX(column\s*\{)REGEX"), "<div class='column'>");
        line = std::regex_replace(line, std::regex(R"REGEX(grid\s*\{)REGEX"), "<div class='grid'>");
        
        // 2. TİPOGRAFİ
        line = std::regex_replace(line, std::regex(R"REGEX(title\s+"([^"]+)")REGEX"), "<h1>$1</h1>");
        line = std::regex_replace(line, std::regex(R"REGEX(subtitle\s+"([^"]+)")REGEX"), "<h2>$1</h2>");
        line = std::regex_replace(line, std::regex(R"REGEX(text\s+"([^"]+)")REGEX"), "<p>$1</p>");
        line = std::regex_replace(line, std::regex(R"REGEX(badge\s+"([^"]+)")REGEX"), "<span class='v-badge'>$1</span>");
        
        // 3. STANDART GİRİDİLER VE BUTONLAR
        line = std::regex_replace(line, std::regex(R"REGEX(button\s+"([^"]+)"\s*->\s*onclick\(([^)]+)\))REGEX"), "<button class='v-btn' onclick='$2()'>$1</button>");
        line = std::regex_replace(line, std::regex(R"REGEX(button_outline\s+"([^"]+)"\s*->\s*onclick\(([^)]+)\))REGEX"), "<button class='v-btn v-btn-outline' onclick='$2()'>$1</button>");
        line = std::regex_replace(line, std::regex(R"REGEX(input\s+"([^"]+)"\s*->\s*([a-zA-Z0-9_]+))REGEX"), "<input type='text' id='$2' class='v-input' placeholder='$1'>");
        line = std::regex_replace(line, std::regex(R"REGEX(input_password\s+"([^"]+)"\s*->\s*([a-zA-Z0-9_]+))REGEX"), "<input type='password' id='$2' class='v-input' placeholder='$1'>");
        
        // 4. HTML'DE OLMAYAN GELİŞMİŞ BİLEŞENLER (V-UI Devrimi)
        
        // iOS Switch: v_toggle "Aktif" -> id
        line = std::regex_replace(line, std::regex(R"REGEX(v_toggle\s+"([^"]+)"\s*->\s*([a-zA-Z0-9_]+))REGEX"), "<div style='display:flex; align-items:center; gap:10px;'><label class='v-toggle'><input type='checkbox' id='$2'><span class='v-slider-round'></span></label> <span>$1</span></div>");
        
        // Fake Terminal (IDE için): v_terminal -> id
        line = std::regex_replace(line, std::regex(R"REGEX(v_terminal\s*->\s*([a-zA-Z0-9_]+))REGEX"), "<div id='$1' class='v-terminal'><div>V-Engine Shell Ready.</div></div>");
        
        // Sözdizimi Renklendirici Kod Bloğu: v_codeblock "KOD"
        line = std::regex_replace(line, std::regex(R"REGEX(v_codeblock\s+"([^"]+)")REGEX"), "<pre class='v-codeblock'><code>$1</code></pre>");
        
        // Yükleniyor Animasyonu: v_loader
        line = std::regex_replace(line, std::regex(R"REGEX(v_loader)REGEX"), "<div class='v-loader'></div>");
        
        // İlerleme Çubuğu: v_progress -> id
        line = std::regex_replace(line, std::regex(R"REGEX(v_progress\s*->\s*([a-zA-Z0-9_]+))REGEX"), "<div class='v-progress-bg'><div id='$1' class='v-progress-bar'></div></div>");
        
        // Sürükle Bırak Yükleme Alanı: v_upload "Metin" -> id
        line = std::regex_replace(line, std::regex(R"REGEX(v_upload\s+"([^"]+)"\s*->\s*([a-zA-Z0-9_]+))REGEX"), "<div id='$2' class='v-upload-zone' onclick='document.getElementById(\"$2_file\").click()'>📁 $1<input type='file' id='$2_file' style='display:none'></div>");
        
        // Yapay Zeka Sohbet Arayüzü: v_ai_chat -> id
        line = std::regex_replace(line, std::regex(R"REGEX(v_ai_chat\s*->\s*([a-zA-Z0-9_]+))REGEX"), "<div id='$1' class='v-ai-chat'></div>");

        // 5. FONKSİYONLAR, JS KÖPRÜLERİ VE BİTİŞLER
        line = std::regex_replace(line, std::regex(R"REGEX(\})REGEX"), "</div>");
        line = std::regex_replace(line, std::regex(R"REGEX(func\s+([a-zA-Z0-9_]+)\(\)\s*\{)REGEX"), "<script>\nfunction $1() {");
        line = std::regex_replace(line, std::regex(R"REGEX(end_func)REGEX"), "}\n</script>");
        
        return line;
    }
};

#endif
