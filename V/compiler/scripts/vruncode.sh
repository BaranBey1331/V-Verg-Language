#!/bin/bash
# V-Engine Inline Code Runner

# Eğer kod girilmediyse uyarı ver
if [ -z "$1" ]; then
    echo -e "\033[1;36m[VRUNCODE]\033[0m Kullanim: vruncode \"<v_kodlari>\""
    echo -e "Ornek: vruncode \"print \\\"Merhaba V!\\\"\""
    exit 1
fi

# Linux'un geçici hafızasında (RAM diski /tmp) benzersiz bir .v dosyası oluştur
TMP_FILE=$(mktemp /tmp/v_inline_XXXXXX.v)

# Kullanıcının yazdığı metni bu geçici dosyaya yaz
echo "$1" > "$TMP_FILE"

# V motorunu bu geçici dosya ile tetikle (Sadece çıktıları göster)
v "$TMP_FILE"

# İş bitince geçici dosyayı anında sil (Hayalet mod)
rm -f "$TMP_FILE"
