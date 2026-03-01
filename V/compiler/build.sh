#!/bin/bash
set -e

echo "=== V-ENGINE DERLEME ISLEMI ==="

# Eski dosyalari ve kutuphaneleri temizle
rm -f *.so v_compiler

echo "[1/2] Eklentiler Derleniyor..."
for plugin_dir in plugins/*; do
    if [ -d "$plugin_dir/src" ]; then
        plugin_name=$(basename "$plugin_dir")
        so_name="lib$(echo "$plugin_name" | tr '[:upper:]' '[:lower:]').so"
        
        echo " -> $plugin_name derleniyor..."
        
        if [ "$plugin_name" == "VDiscord" ]; then
            # VDiscord icin otonom header uretimi
            AUTO_HEADER="$plugin_dir/src/vdiscord_autogen.hpp"
            echo "// OTONOM URETILDI" > "$AUTO_HEADER"
            find "$plugin_dir/src/functions" -type f -name "*.hpp" | while read -r hpp_file; do
                clean_path="${hpp_file#$plugin_dir/src/}"
                echo "#include \"$clean_path\"" >> "$AUTO_HEADER"
            done
            
            # VDiscord, HTTP istekleri icin cURL kütüphanesi (-lcurl) ile derlenir
            clang++ $(find "$plugin_dir/src" -type f -name "*.cpp") -shared -fPIC -lcurl -o "$so_name"
        else
            # Diger standart eklentiler
            clang++ $(find "$plugin_dir/src" -type f -name "*.cpp") -shared -fPIC -o "$so_name"
        fi
    fi
done

echo "[2/2] V-Engine Ana Motoru Derleniyor..."
# src icindeki ana dosyalar, codegen modulleri ve core modulleri tek seferde derlenir
clang++ src/*.cpp src/codegen/*.cpp src/core/*.cpp -Iinclude -L. -ldl -Wl,-rpath,. -o v_compiler
chmod +x v_compiler

echo "[BASARILI] V-Engine hazir."
