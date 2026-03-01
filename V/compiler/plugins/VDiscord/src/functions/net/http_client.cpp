#include <iostream>
#include <string>
#include <curl/curl.h>

// Discord API Baglantilari Icin Otonom C++ cURL Saricisi
extern "C" {

    // Gercek HTTP POST Istegi!
    void vdiscord_http_post(const char* url, const char* json_payload, const char* auth_token) {
        CURL* curl;
        CURLcode res;
        
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        
        if(curl) {
            struct curl_slist* headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            
            std::string auth_header = "Authorization: Bot " + std::string(auth_token);
            headers = curl_slist_append(headers, auth_header.c_str());
            
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_payload);
            
            // İstek fırlatılıyor (Şimdilik çıktıyı konsola basıyoruz)
            res = curl_easy_perform(curl);
            
            if(res != CURLE_OK) {
                std::cerr << "\033[1;31m[VDISCORD-HTTP HATA]\033[0m " << curl_easy_strerror(res) << "\n";
            } else {
                std::cout << "\n\033[1;32m[VDISCORD]\033[0m HTTP POST Basarili! (" << url << ")\n";
            }
            
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }
}
