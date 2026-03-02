#pragma once
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

namespace VEngine {
    class Benchmark {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
        size_t total_lines;
        std::string filepath;

        // Dosyadaki toplam satir sayisini isik hizinda sayar
        size_t countLines(const std::string& path) {
            std::ifstream file(path);
            if (!file.is_open()) return 0;
            size_t lines = 0;
            std::string line;
            while (std::getline(file, line)) {
                lines++;
            }
            return lines;
        }

    public:
        // Sinif baslatildiginda dosya yolunu alir ve satirlari sayar
        Benchmark(const std::string& file) : filepath(file) {
            total_lines = countLines(filepath);
        }

        // Kronometreyi baslatir
        void start() {
            start_time = std::chrono::high_resolution_clock::now();
            std::cout << "\033[1;36m[V-Engine]\033[0m Derleme basliyor: " << filepath << "\n";
        }

        // Kronometreyi durdurur ve LOC/s raporunu ekrana basar
        void stopAndReport() {
            auto end_time = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end_time - start_time;
            double seconds = elapsed.count();
            
            // Sifira bolunme hatasini engeller
            double loc_per_sec = (seconds > 0.0) ? (total_lines / seconds) : 0.0;

            std::cout << "\n\033[1;33m=== V-ENGINE DERLEME RAPORU ===\033[0m\n";
            std::cout << "Hedef Dosya  : " << filepath << "\n";
            std::cout << "Toplam Satir : " << total_lines << "\n";
            std::cout << "Gecen Sure   : " << std::fixed << std::setprecision(5) << seconds << " saniye\n";
            std::cout << "Hiz (LOC/s)  : \033[1;32m" << (int)loc_per_sec << " satir/saniye\033[0m\n";
            std::cout << "\033[1;33m===============================\033[0m\n";
        }
    };
}

