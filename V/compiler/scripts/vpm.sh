#!/bin/bash
# ==============================================================================
# V-ENGINE PACKAGE MANAGER (VPM)
# V diline disaridan donanim hizlandirmali C eklentileri kurar.
# ==============================================================================

# Arguman kontrolu
if [ "$1" != "install" ] || [ -z "$2" ]; then
    echo -e "\033[1;36m========================================\033[0m"
    echo -e "\033[1;35m[VPM]\033[0m V-Engine Paket Yoneticisi"
    echo -e "\033[1;36m========================================\033[0m"
    echo -e "Kullanim: vpm install <paket_adi>"
    echo -e "Mevcut Resmi Paketler:"
    echo -e "  - \033[1;32mweb_ui\033[0m : Localhost Soket Sunucusu (Web Arayuzu)"
    echo -e "  - \033[1;32mvtorch\033[0m : ARM NEON Hizlandirmali Yapay Zeka (Autograd) Motoru"
    exit 1
fi

PACKAGE=$2
BASE_DIR="$HOME/compiler"

echo -e "\033[1;35m[VPM]\033[0m '$PACKAGE' paketi araniyor ve sisteme entegre ediliyor..."

case $PACKAGE in
    web_ui)
        TARGET_DIR="$BASE_DIR/stdlib"
        mkdir -p "$TARGET_DIR"
        
        # Web UI C kodunu dogrudan dosyanin icine yaziyoruz (Heredoc)
        cat << 'EOF' > "$TARGET_DIR/web_ui.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// V Dilinden cagrilabilen Soket Sunucusu
void v_start_server(int port) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    
    // Ciktisi V diline ozel HTML sayfasi
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><head><title>V-Engine</title><style>body{background-color:#1e1e1e;color:#00ff00;font-family:monospace;padding:50px;}</style></head><body><h1>[ V-ENGINE WEB SUNUCUSU AKTIF ]</h1><p>V dili tarafindan C Soketleri uzerinden render edilmistir.</p></body></html>";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("\033[1;31m[HATA]\033[0m Socket basarisiz"); exit(EXIT_FAILURE);
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("\033[1;31m[HATA]\033[0m Setsockopt hatasi"); exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("\033[1;31m[HATA]\033[0m Bind basarisiz"); exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("\033[1;31m[HATA]\033[0m Listen hatasi"); exit(EXIT_FAILURE);
    }
    
    printf("\033[1;32m[V-WEB]\033[0m Sunucu %d portunda dinleniyor...\n", port);
    printf("\033[1;33m[V-WEB]\033[0m Tarayicidan su adrese git: http://localhost:%d\n", port);
    
    // Sadece tek bir HTTP istegi kabul et ve kapan (basitlik icin)
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("\033[1;31m[HATA]\033[0m Accept hatasi"); exit(EXIT_FAILURE);
    }
    
    read(new_socket, buffer, 1024);
    send(new_socket, hello, strlen(hello), 0);
    printf("\033[1;32m[V-WEB]\033[0m Istemciye yanit basariyla gonderildi.\n");
    
    close(new_socket);
    close(server_fd);
}
EOF
        echo -e "\033[1;32m[BASARILI]\033[0m 'web_ui' modulu (C Soket Sunucusu) stdlib icine yazildi."
        ;;

    vtorch)
        TARGET_DIR="$BASE_DIR/plugins/vtorch/src"
        mkdir -p "$TARGET_DIR"
        
        # Vtorch dosyalari V-Engine gelistiricisi tarafindan manuel yonetilir (Cok parcali oldugu icin)
        # Burada sadece VPM tarafindan dogrulamasi yapilir.
        if [ -f "$TARGET_DIR/neural.h" ] && [ -f "$TARGET_DIR/math_ops.c" ]; then
            echo -e "\033[1;32m[BASARILI]\033[0m Vtorch AI Motoru (.c ve .h) eklenti klasorunde dogrulandi."
        else
            echo -e "\033[1;31m[UYARI]\033[0m Vtorch dosyalari eksik! Lutfen 'neural.h', 'memory.c', 'math_ops.c' ve 'api.c' dosyalarini MT Manager uzerinden ekleyin."
        fi
        ;;

    *)
        echo -e "\033[1;31m[HATA]\033[0m V-Engine paket kayit defterinde '$PACKAGE' adinda bir paket bulunamadi."
        exit 1
        ;;
esac

echo -e "\033[1;33m[VPM]\033[0m V-Engine Derleyicisi (v_compiler) yeni modullerle yeniden baglaniyor (Linking)..."

# Ana dizine donup C++ baglayicisini tetikle
cd "$BASE_DIR" && ./build.sh > /dev/null

if [ $? -eq 0 ]; then
    echo -e "\033[1;32m[VPM]\033[0m '$PACKAGE' kurulumu tamamen bitti! V dilinde kullanmaya baslayabilirsiniz."
else
    echo -e "\033[1;31m[CRITICAL ERROR]\033[0m Baglayici (Linker) yeni paketi derlerken coktu."
fi
