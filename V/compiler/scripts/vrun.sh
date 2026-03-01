#!/bin/bash

if [ -z "$1" ]; then
    echo -e "\033[1;36m[VRUN]\033[0m Kullanim: vrun <dosya>"
    exit 1
fi

FILE=$1
EXT="${FILE##*.}"

echo -e "\033[1;34m[VRUN]\033[0m Calistiriliyor: $FILE"
echo "----------------------------------------"

if [ "$EXT" == "v" ]; then
    # Standart V kodunu derle ve çalıştır
    v "$FILE"
    
elif [ "$EXT" == "vtml" ]; then
    echo -e "\033[1;35m[VTML MOTORU]\033[0m Arayuz Insa Ediliyor..."
    
    # 1. VTML'i HTML'e Çevir (Bulunduğun klasöre index.html üretir)
    vtml "$FILE"
    if [ $? -ne 0 ]; then 
        echo -e "\033[1;31m[HATA]\033[0m VTML derlemesi basarisiz oldu!"
        exit 1
    fi
    
    # 2. Gecici sunucu kodunu BULUNDUGUMUZ KLASORDE (Gizli dosya olarak) olustur
    # Bu sayede sunucu index.html ile ayni klasorde (yan yana) calisacak!
    echo "print \"[SISTEM] V-Engine Web Sunucusu Baslatiliyor...\"" > .server_temp.v
    echo "v_start_server(8080)" >> .server_temp.v
    
    # 3. Android'de tarayıcıyı otomatik aç
    termux-open "http://localhost:8080" 2>/dev/null || true
    
    # 4. Sunucuyu çalıştır ve işi bitince iz bırakmadan sil
    v .server_temp.v
    rm -f .server_temp.v
    
else
    echo -e "\033[1;31m[HATA]\033[0m Desteklenmeyen uzanti: .$EXT"
    echo "----------------------------------------"
fi
