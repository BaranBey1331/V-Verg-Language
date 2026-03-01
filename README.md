<div align="center">
🚀 V-Verg-Language
Advanced Tooling, Engine Optimization, and Mobile IDE Integration for V
🌐 Choose Your Language / Dil Seçin / Wählen Sie Ihre Sprache / Выберите язык / 选择您的语言
🇬🇧 English   |   🇹🇷 Türkçe   |   🇩🇪 Deutsch   |   🇷🇺 Русский   |   🇨🇳 中文
</div>
🇬🇧 English
🌟 Overview
V-Verg-Language is a powerful ecosystem designed to extend the V Programming Language. It focuses on three main pillars:
 * Mobile Development (Android/Acode).
 * Engine Optimization.
 * Advanced Inline Capabilities.
🚀 Core Features
 * ⚡ V-Engine Optimizer: Custom AST evaluation and memory tuning (v_optimizer.v).
 * 📱 Acode IDE Integration: Full V language support for the Android Acode editor (acode_v_plugin).
 * 🧩 VSupport Plugins: Enhanced inline code execution and low-level system bindings.
 * 🌍 Cross-Platform: Works seamlessly across Termux (Android), Linux, and Windows.
📂 Repository Structure
V-Verg-Language/
├── acode_v_plugin/                      
│   ├── plugin.json                      # Acode plugin metadata
│   └── main.js                          # Core JS bridge for Acode & V CLI
├── compiler/
│   └── plugins/
│       └── VSupport/
│           └── src/                     # Inline capabilities
│               ├── inline_handler.v     
│               └── support_core.v       
├── src/                                 
│   └── v_optimizer.v                    # Core Engine Optimizer
├── examples/                            # Demo scripts
└── README.md

🛠️ Installation
1. Desktop (Linux / macOS / Windows)
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)
cd V-Verg-Language
cp src/v_optimizer.v /path/to/v/src/
v run examples/demo.v

2. Mobile (Android via Termux & Acode)
# In Termux
pkg install v git
cd /storage/emulated/0/Download/
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)

 * Acode Setup: Open Acode -> Settings -> Plugins -> Install from folder -> Select acode_v_plugin -> Restart.
💻 Code Example
import optimizer

fn main() {
    mut opt := optimizer.new_optimizer(profile: .mobile)
    opt.run_pass()
    println('V-Verg Mobile Optimization complete!')
}

🗺️ Roadmap
 * [x] Initial structure & AST optimizer setup.
 * [x] Acode plugin scaffolding.
 * [ ] Publish to official Acode Plugin Store.
 * [ ] Add advanced C-macro inline wrappers.
🤝 Contributing
 * Fork the repo.
 * Create branch: git checkout -b feature/NewIdea
 * Commit: git commit -m 'Add NewIdea'
 * Push: git push origin feature/NewIdea
 * Open Pull Request.
🇹🇷 Türkçe
🌟 Genel Bakış
V-Verg-Language, V Programlama Dilini genişletmek için tasarlanmış güçlü bir ekosistemdir. Üç ana temele odaklanır:
 * Mobil Geliştirme (Android/Acode).
 * Motor (Engine) Optimizasyonu.
 * Gelişmiş Satıriçi (Inline) Yetenekleri.
🚀 Temel Özellikler
 * ⚡ V-Engine Optimize Edici: Özel AST değerlendirmesi ve bellek ayarı (v_optimizer.v).
 * 📱 Acode IDE Entegrasyonu: Android Acode editörü için tam V dili desteği (acode_v_plugin).
 * 🧩 VSupport Eklentileri: Gelişmiş satıriçi kod yürütme ve düşük seviye sistem bağlantıları.
 * 🌍 Çapraz Platform: Termux (Android), Linux ve Windows üzerinde sorunsuz çalışır.
📂 Depo Yapısı
V-Verg-Language/
├── acode_v_plugin/                      
│   ├── plugin.json                      # Acode eklenti meta verileri
│   └── main.js                          # Acode ve V CLI için temel JS köprüsü
├── compiler/
│   └── plugins/
│       └── VSupport/
│           └── src/                     # Inline yetenekleri dizini
│               ├── inline_handler.v     
│               └── support_core.v       
├── src/                                 
│   └── v_optimizer.v                    # Çekirdek Motor Optimizatörü
├── examples/                            # Demo betikleri
└── README.md

🛠️ Kurulum
1. Masaüstü (Linux / macOS / Windows)
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)
cd V-Verg-Language
cp src/v_optimizer.v /path/to/v/src/
v run examples/demo.v

2. Mobil (Termux ve Acode ile Android)
# Termux İçinde
pkg install v git
cd /storage/emulated/0/Download/
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)

 * Acode Ayarı: Acode'u açın -> Ayarlar -> Eklentiler -> Klasörden Yükle -> acode_v_plugin seçin -> Yeniden başlatın.
💻 Kod Örneği
import optimizer

fn main() {
    mut opt := optimizer.new_optimizer(profile: .mobile)
    opt.run_pass()
    println('V-Verg Mobil Optimizasyonu tamamlandı!')
}

🗺️ Yol Haritası
 * [x] Başlangıç yapısı ve AST optimizatör kurulumu.
 * [x] Acode eklenti iskeleti.
 * [ ] Resmi Acode Eklenti Mağazasında yayınla.
 * [ ] Gelişmiş C-makro satıriçi sarmalayıcıları ekle.
🤝 Katkıda Bulunma
 * Depoyu Forklayın.
 * Dal oluşturun: git checkout -b feature/YeniFikir
 * Commit atın: git commit -m 'YeniFikir Eklendi'
 * Pushlayın: git push origin feature/YeniFikir
 * Pull Request (Çekme İsteği) açın.
🇩🇪 Deutsch
🌟 Übersicht
V-Verg-Language ist ein leistungsstarkes Ökosystem zur Erweiterung der V-Programmiersprache. Es konzentriert sich auf drei Hauptsäulen:
 * Mobile Entwicklung (Android/Acode).
 * Engine-Optimierung.
 * Erweiterte Inline-Funktionen.
🚀 Kernfunktionen
 * ⚡ V-Engine Optimizer: Benutzerdefinierte AST-Auswertung und Speicheroptimierung (v_optimizer.v).
 * 📱 Acode IDE Integration: Volle V-Sprachunterstützung für den Android-Acode-Editor (acode_v_plugin).
 * 🧩 VSupport Plugins: Verbesserte Inline-Code-Ausführung und Low-Level-Systembindungen.
 * 🌍 Plattformübergreifend: Funktioniert nahtlos auf Termux (Android), Linux und Windows.
📂 Repository-Struktur
V-Verg-Language/
├── acode_v_plugin/                      
│   ├── plugin.json                      # Acode-Plugin-Metadaten
│   └── main.js                          # JS-Brücke für Acode & V CLI
├── compiler/
│   └── plugins/
│       └── VSupport/
│           └── src/                     # Inline-Funktionen
│               ├── inline_handler.v     
│               └── support_core.v       
├── src/                                 
│   └── v_optimizer.v                    # Kern-Engine-Optimierer
├── examples/                            # Demo-Skripte
└── README.md

🛠️ Installation
1. Desktop (Linux / macOS / Windows)
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)
cd V-Verg-Language
cp src/v_optimizer.v /path/to/v/src/
v run examples/demo.v

2. Mobil (Android über Termux & Acode)
# In Termux
pkg install v git
cd /storage/emulated/0/Download/
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)

 * Acode-Einrichtung: Acode öffnen -> Einstellungen -> Plugins -> Aus Ordner installieren -> acode_v_plugin auswählen -> Neustart.
💻 Code-Beispiel
import optimizer

fn main() {
    mut opt := optimizer.new_optimizer(profile: .mobile)
    opt.run_pass()
    println('V-Verg Mobile Optimierung abgeschlossen!')
}

🗺️ Fahrplan
 * [x] Initiale Struktur & AST-Optimierer-Setup.
 * [x] Acode-Plugin-Gerüst.
 * [ ] Im offiziellen Acode Plugin Store veröffentlichen.
 * [ ] Erweiterte C-Makro-Inline-Wrapper hinzufügen.
🤝 Mitwirken
 * Repo forken.
 * Branch erstellen: git checkout -b feature/NeueIdee
 * Commit: git commit -m 'NeueIdee hinzugefügt'
 * Push: git push origin feature/NeueIdee
 * Pull Request öffnen.
🇷🇺 Русский
🌟 Обзор
V-Verg-Language — это мощная экосистема, предназначенная для расширения языка программирования V. Она сосредоточена на трех основных направлениях:
 * Мобильная разработка (Android/Acode).
 * Оптимизация движка (Engine).
 * Расширенные встроенные (Inline) возможности.
🚀 Основные функции
 * ⚡ Оптимизатор V-Engine: Пользовательская оценка AST и настройка памяти (v_optimizer.v).
 * 📱 Интеграция Acode IDE: Полная поддержка языка V для редактора Android Acode (acode_v_plugin).
 * 🧩 Плагины VSupport: Улучшенное выполнение встроенного кода и низкоуровневые системные привязки.
 * 🌍 Кроссплатформенность: Безупречно работает в Termux (Android), Linux и Windows.
📂 Структура репозитория
V-Verg-Language/
├── acode_v_plugin/                      
│   ├── plugin.json                      # Метаданные плагина Acode
│   └── main.js                          # Основной мост JS для Acode и V CLI
├── compiler/
│   └── plugins/
│       └── VSupport/
│           └── src/                     # Встроенные возможности
│               ├── inline_handler.v     
│               └── support_core.v       
├── src/                                 
│   └── v_optimizer.v                    # Основной оптимизатор движка
├── examples/                            # Демо-скрипты
└── README.md

🛠️ Установка
1. Десктоп (Linux / macOS / Windows)
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)
cd V-Verg-Language
cp src/v_optimizer.v /path/to/v/src/
v run examples/demo.v

2. Мобильный (Android через Termux и Acode)
# В Termux
pkg install v git
cd /storage/emulated/0/Download/
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)

 * Настройка Acode: Откройте Acode -> Настройки -> Плагины -> Установить из папки -> Выберите acode_v_plugin -> Перезапустить.
💻 Пример кода
import optimizer

fn main() {
    mut opt := optimizer.new_optimizer(profile: .mobile)
    opt.run_pass()
    println('Мобильная оптимизация V-Verg завершена!')
}

🗺️ Дорожная карта
 * [x] Начальная структура и настройка оптимизатора AST.
 * [x] Каркас плагина Acode.
 * [ ] Публикация в официальном магазине плагинов Acode.
 * [ ] Добавление расширенных встроенных оболочек C-макросов.
🤝 Вклад
 * Сделайте форк репозитория.
 * Создайте ветку: git checkout -b feature/NewIdea
 * Закоммитьте: git commit -m 'Add NewIdea'
 * Отправьте: git push origin feature/NewIdea
 * Откройте Pull Request.
🇨🇳 中文
🌟 概述
V-Verg-Language 是一个为扩展 V 编程语言 而设计的强大生态系统。它侧重于三个主要支柱：
 * 移动开发 (Android/Acode)。
 * 引擎优化 (Engine Optimization)。
 * 高级内联功能 (Inline Capabilities)。
🚀 核心功能
 * ⚡ V-Engine 优化器： 自定义 AST 评估和内存调整 (v_optimizer.v)。
 * 📱 Acode IDE 集成： 为 Android Acode 编辑器提供完整的 V 语言支持 (acode_v_plugin)。
 * 🧩 VSupport 插件： 增强的内联代码执行和底层系统绑定。
 * 🌍 跨平台： 在 Termux (Android)、Linux 和 Windows 上无缝运行。
📂 仓库结构
V-Verg-Language/
├── acode_v_plugin/                      
│   ├── plugin.json                      # Acode 插件元数据
│   └── main.js                          # Acode & V CLI 的核心 JS 桥接
├── compiler/
│   └── plugins/
│       └── VSupport/
│           └── src/                     # 内联功能目录
│               ├── inline_handler.v     
│               └── support_core.v       
├── src/                                 
│   └── v_optimizer.v                    # 核心引擎优化器
├── examples/                            # 演示脚本
└── README.md

🛠️ 安装
1. 桌面端 (Linux / macOS / Windows)
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)
cd V-Verg-Language
cp src/v_optimizer.v /path/to/v/src/
v run examples/demo.v

2. 移动端 (通过 Termux & Acode 在 Android 上运行)
# 在 Termux 中
pkg install v git
cd /storage/emulated/0/Download/
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)

 * Acode 设置： 打开 Acode -> 设置 -> 插件 -> 从文件夹安装 -> 选择 acode_v_plugin -> 重启。
💻 代码示例
import optimizer

fn main() {
    mut opt := optimizer.new_optimizer(profile: .mobile)
    opt.run_pass()
    println('V-Verg 移动端优化完成！')
}

🗺️ 路线图
 * [x] 初始结构和 AST 优化器设置。
 * [x] Acode 插件脚手架。
 * [ ] 发布到官方 Acode 插件商店。
 * [ ] 添加高级 C 宏内联包装器。
🤝 参与贡献
 * Fork 本仓库。
 * 创建分支：git checkout -b feature/NewIdea
 * 提交更改：git commit -m 'Add NewIdea'
 * 推送分支：git push origin feature/NewIdea
 * 提交 Pull Request。
<div align="center">
<p>Built with ❤️ by the V-Verg-Language Contributors.</p>
</div>
