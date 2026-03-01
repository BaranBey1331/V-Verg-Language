#include "vtml_dom.hpp"
#include <iostream>
#include <cctype>

VTMLParser::VTMLParser(const std::string& src) : source(src), pos(0) {}

void VTMLParser::skipWhitespace() {
    while (pos < source.length() && std::isspace(source[pos])) pos++;
}

std::string VTMLParser::readTagOrAttr() {
    std::string res = "";
    while (pos < source.length() && (std::isalnum(source[pos]) || source[pos] == '-')) {
        res += source[pos++];
    }
    return res;
}

std::string VTMLParser::readString() {
    std::string res = "";
    if (source[pos] == '"') pos++; // İlk tırnağı atla
    while (pos < source.length() && source[pos] != '"') {
        res += source[pos++];
    }
    if (source[pos] == '"') pos++; // Son tırnağı atla
    return res;
}

VTMLNode* VTMLParser::parse() {
    VTMLNode* root = new VTMLNode("ROOT");
    VTMLNode* current = root;

    while (pos < source.length()) {
        skipWhitespace();
        if (pos >= source.length()) break;

        if (source[pos] == '<') {
            pos++; // '<' işaretini geç
            
            // Eğer kapanış etiketi ise (Örn: </button>)
            if (source[pos] == '/') {
                pos++;
                std::string tag = readTagOrAttr();
                while (source[pos] != '>') pos++; // '>' işaretini bulana kadar git
                pos++;
                
                // Ağaçta bir üst dala (parent) geri dön! (Regex'in asla yapamadığı o büyük yetenek)
                if (current->parent != nullptr) {
                    current = current->parent;
                }
            } 
            // Eğer açılış etiketi ise (Örn: <button id="x">)
            else {
                std::string tag = readTagOrAttr();
                VTMLNode* newNode = new VTMLNode(tag, current);
                
                // Attributeleri (Özellikleri) Oku
                skipWhitespace();
                while (source[pos] != '>' && source[pos] != '/' && pos < source.length()) {
                    std::string attrName = readTagOrAttr();
                    skipWhitespace();
                    if (source[pos] == '=') {
                        pos++;
                        skipWhitespace();
                        std::string attrValue = readString();
                        newNode->attributes[attrName] = attrValue;
                    }
                    skipWhitespace();
                }

                // Etiketi kapat ve ağaca ekle
                if (source[pos] == '/') {
                    // Kendi kendini kapatan etiket (Örn: <img />)
                    current->children.push_back(newNode);
                    pos += 2; // "/>"
                } else if (source[pos] == '>') {
                    // İçine başka şeyler alacak etiket (Örn: <box> ... </box>)
                    current->children.push_back(newNode);
                    current = newNode; // Artık yeni elementin içine giriyoruz!
                    pos++;
                }
            }
        } 
        // Etiket değilse düz yazıdır (Text Content)
        else {
            std::string text = "";
            while (pos < source.length() && source[pos] != '<') {
                text += source[pos++];
            }
            // Sadece boşluktan ibaret değilse kaydet
            if (text.find_first_not_of(" \n\r\t") != std::string::npos) {
                current->text_content = text;
            }
        }
    }
    return root;
}
