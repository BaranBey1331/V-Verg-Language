#pragma once
#include <string>
#include <vector>
#include <map>

// Gerçek bir Arayüz Düğümü (DOM Node)
struct VTMLNode {
    std::string tag; // Örn: "div", "button"
    std::map<std::string, std::string> attributes; // Örn: id="btn1", color="red"
    std::string text_content; // İki etiket arasındaki yazı
    std::vector<VTMLNode*> children; // İç içe geçmiş elementler (Ağacın Dalları)
    VTMLNode* parent; // Üst element (Geri dönüş yolu)

    VTMLNode(const std::string& t, VTMLNode* p = nullptr) : tag(t), parent(p) {}
};

// Regex'i tarihe gömen gerçek DOM Ayrıştırıcısı
class VTMLParser {
private:
    std::string source;
    size_t pos;

    void skipWhitespace();
    std::string readTagOrAttr();
    std::string readString();

public:
    VTMLParser(const std::string& src);
    VTMLNode* parse(); // Kodları okuyup hiyerarşik bir UI ağacı döndürür
};
