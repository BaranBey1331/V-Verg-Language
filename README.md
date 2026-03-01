<div align="center">
🚀 V-Verg-Language
Advanced Tooling, Engine Optimization, and Mobile IDE Integration for the V Programming Language
🌐 Choose Your Language / Dil Seçin / Wählen Sie Ihre Sprache / Выберите язык / 选择您的语言
🇬🇧 English   |   🇹🇷 Türkçe   |   🇩🇪 Deutsch   |   🇷🇺 Русский   |   🇨🇳 中文
</div>
<a id="lang-en"></a> 🇬🇧 English Documentation
🌟 Comprehensive Overview
V-Verg-Language is an ambitious, highly optimized ecosystem designed specifically to extend the capabilities of the V Programming Language. While V is globally recognized for its blazingly fast compilation speed and memory safety, developing and optimizing V applications directly on mobile environments (like Android via Termux) has traditionally been a complex challenge.
This project completely revolutionizes that experience by focusing on three main pillars:
 * Mobile Editor Integration: Seamless coding via the Acode app.
 * Engine Optimization: Custom AST evaluation and memory pool tuning.
 * Advanced Inline Capabilities: Safe wrappers for low-level C macros.
🚀 Deep Dive into Core Features
 * ⚡ V-Engine Optimizer (v_optimizer.v)
   * Implements aggressive dead-code elimination before the C backend translation.
   * Dynamically adjusts the default arena allocator settings to prevent Out-Of-Memory (OOM) errors on resource-constrained Android devices.
   * Rebuilds the Abstract Syntax Tree (AST) for faster runtime execution.
 * 📱 Acode IDE Integration (acode_v_plugin)
   * Brings context-aware syntax highlighting directly to the Android Acode editor.
   * Features a built-in JS bridge that communicates with local background shells (like Termux) to execute v run commands with a single tap.
   * Maps compiler errors directly to the specific line of code within the editor interface.
 * 🧩 VSupport Plugins (VSupport/src)
   * Extends the standard [inline] attributes of the V language.
   * Provides structured, safer environments for embedding raw C code or Assembly instructions directly into your V source files.
📂 Detailed Repository Structure
To maintain a modular and scalable architecture, the repository is structured as follows:
V-Verg-Language/
│
├── acode_v_plugin/                      # Mobile IDE Integration Directory
│   ├── plugin.json                      # Acode plugin metadata and UI registry
│   └── main.js                          # Core JavaScript bridge for Acode & V CLI
│
├── compiler/
│   └── plugins/
│       └── VSupport/
│           └── src/                     # Inline capabilities and compiler hooks
│               ├── inline_handler.v     # Manages the parsing of inline code blocks
│               └── support_core.v       # Core extension API
│
├── src/                                 
│   └── v_optimizer.v                    # The core Engine Optimization module
│
├── examples/                            # Test cases and practical demo scripts
│   └── demo_app.v
│
├── LICENSE                              # MIT License
└── README.md                            # This file

🛠️ Step-by-Step Installation
1. Standard Desktop Setup (Linux / macOS / Windows)
# Clone the repository
git clone https://github.com/BaranBey1331/V-Verg-Language.git

# Enter the directory
cd V-Verg-Language

# Move the optimizer to your local V source directory
cp src/v_optimizer.v /path/to/v/src/

# Test the installation with a demo script
v run examples/demo_app.v

2. Mobile Setup (Android via Termux & Acode)
# First, open Termux and install the necessary packages
pkg install v git

# Navigate to your shared internal storage
cd /storage/emulated/0/Download/

# Clone the project directly into your phone's storage
git clone https://github.com/BaranBey1331/V-Verg-Language.git

 * Activating the Acode Plugin:
   * Open the Acode app on your Android device.
   * Navigate to Settings -> Plugins.
   * Select Install from folder.
   * Browse to /storage/emulated/0/Download/V-Verg-Language/acode_v_plugin and select it.
   * Restart the Acode application to apply the syntax rules and terminal hooks.
💻 Practical Code Example
Here is how you can implement the V-Verg optimizer in your daily V projects:
import optimizer

fn main() {
    println('[INFO] Initializing V-Verg Engine...')
    
    // Initialize the custom optimizer with the mobile profile
    // This will limit memory allocation spikes
    mut opt := optimizer.new_optimizer(profile: .mobile)
    
    // Run the optimization pass on the current AST
    opt.run_pass()
    
    println('[SUCCESS] Optimization complete. Running main logic.')
}

❓ Troubleshooting & FAQ
Q: The Acode plugin says "Invalid plugin.json". What should I do?
> A: Ensure you are selecting the specific acode_v_plugin directory, NOT the root repository folder. Acode expects the plugin.json to be at the exact root of the chosen folder.
> 
Q: Why do I get "Permission Denied" errors when compiling in Termux?
> A: Termux needs explicit permission to read/write to your Android storage. Run termux-setup-storage in your terminal and accept the Android permission prompt.
> 
🤝 Contributing Guidelines
We welcome all contributions! To help us improve:
 * Fork the project.
 * Create your feature branch (git checkout -b feature/AmazingFeature).
 * Commit your changes (git commit -m 'Add some AmazingFeature').
 * Push to the branch (git push origin feature/AmazingFeature).
 * Open a Pull Request for review.


<hr>


<a id="lang-tr"></a> 🇹🇷 Türkçe Dokümantasyon
🌟 Kapsamlı Genel Bakış
V-Verg-Language, V Programlama Dilinin yeteneklerini genişletmek ve sınırlarını zorlamak için tasarlanmış iddialı ve son derece optimize edilmiş bir ekosistemdir. V dili, inanılmaz derleme hızı ve bellek güvenliği ile küresel çapta tanınsa da, doğrudan mobil ortamlarda (örneğin Termux üzerinden Android) V uygulamaları geliştirmek ve optimize etmek geleneksel olarak karmaşık bir zorluk olmuştur.
Bu proje, üç ana temele odaklanarak bu deneyimde tamamen devrim yaratıyor:
 * Mobil Editör Entegrasyonu: Acode uygulaması üzerinden sorunsuz kodlama.
 * Motor (Engine) Optimizasyonu: Özel AST değerlendirmesi ve bellek havuzu ayarları.
 * Gelişmiş Satıriçi (Inline) Yetenekleri: Düşük seviyeli C makroları için güvenli sarmalayıcılar.
🚀 Temel Özelliklerin Derinlemesine İncelenmesi
 * ⚡ V-Engine Optimize Edici (v_optimizer.v)
   * C arka planına (backend) çeviriden önce agresif ölü kod (dead-code) eliminasyonu uygular.
   * Kaynakları kısıtlı Android cihazlarda Yetersiz Bellek (OOM - Out Of Memory) hatalarını önlemek için varsayılan arena bellek tahsis edici ayarlarını dinamik olarak ayarlar.
   * Daha hızlı çalışma zamanı yürütmesi için Soyut Sözdizimi Ağacını (AST) yeniden inşa eder.
 * 📱 Acode IDE Entegrasyonu (acode_v_plugin)
   * Android Acode editörüne doğrudan bağlama duyarlı sözdizimi vurgulama (syntax highlighting) getirir.
   * Tek bir dokunuşla v run komutlarını yürütmek için yerel arka plan kabuklarıyla (Termux gibi) iletişim kuran yerleşik bir JS köprüsü içerir.
   * Derleyici hatalarını doğrudan editör arayüzündeki belirli kod satırıyla eşleştirerek hata ayıklamayı kolaylaştırır.
 * 🧩 VSupport Eklentileri (VSupport/src)
   * V dilinin standart [inline] niteliklerini büyük ölçüde genişletir.
   * Doğrudan V kaynak dosyalarınıza ham C kodu veya Assembly talimatları yerleştirmek için yapılandırılmış, daha güvenli ortamlar sağlar.
📂 Detaylı Depo Yapısı
Modüler ve ölçeklenebilir bir mimariyi korumak için proje dizini aşağıdaki gibi yapılandırılmıştır:
V-Verg-Language/
│
├── acode_v_plugin/                      # Mobil IDE Entegrasyon Dizini
│   ├── plugin.json                      # Acode eklenti meta verileri ve arayüz kaydı
│   └── main.js                          # Acode & V CLI için çekirdek JavaScript köprüsü
│
├── compiler/
│   └── plugins/
│       └── VSupport/
│           └── src/                     # Satıriçi yetenekler ve derleyici kancaları
│               ├── inline_handler.v     # Satıriçi kod bloklarının ayrıştırılmasını yönetir
│               └── support_core.v       # Çekirdek uzantı API'si
│
├── src/                                 
│   └── v_optimizer.v                    # Temel Motor Optimizasyon modülü
│
├── examples/                            # Test senaryoları ve pratik demo betikleri
│   └── demo_app.v
│
├── LICENSE                              # MIT Lisansı
└── README.md                            # Bu dosya

🛠️ Adım Adım Kurulum
1. Standart Masaüstü Kurulumu (Linux / macOS / Windows)
# Depoyu bilgisayarınıza klonlayın
git clone https://github.com/BaranBey1331/V-Verg-Language.git

# Proje dizinine girin
cd V-Verg-Language

# Optimize ediciyi yerel V kaynak dizininize taşıyın
cp src/v_optimizer.v /path/to/v/src/

# Kurulumu bir demo betiği ile test edin
v run examples/demo_app.v

2. Mobil Kurulum (Termux ve Acode üzerinden Android)
# Önce Termux'u açın ve gerekli paketleri yükleyin
pkg install v git

# Paylaşılan dahili depolamanıza gidin
cd /storage/emulated/0/Download/

# Projeyi doğrudan telefonunuzun hafızasına klonlayın
git clone https://github.com/BaranBey1331/V-Verg-Language.git

 * Acode Eklentisini Etkinleştirme:
   * Android cihazınızda Acode uygulamasını açın.
   * Ayarlar (Settings) -> Eklentiler (Plugins) menüsüne gidin.
   * Klasörden yükle (Install from folder) seçeneğini seçin.
   * /storage/emulated/0/Download/V-Verg-Language/acode_v_plugin dizinini bulun ve seçin.
   * Sözdizimi kurallarını ve terminal bağlantılarını uygulamak için Acode uygulamasını yeniden başlatın.
💻 Pratik Kod Örneği
V-Verg optimize ediciyi günlük V projelerinizde şu şekilde uygulayabilirsiniz:
import optimizer

fn main() {
    println('[BİLGİ] V-Verg Motoru Başlatılıyor...')
    
    // Özel optimize ediciyi mobil profil ile başlat
    // Bu, ani bellek artışlarını sınırlayacaktır
    mut opt := optimizer.new_optimizer(profile: .mobile)
    
    // Geçerli AST üzerinde optimizasyon geçişini çalıştır
    opt.run_pass()
    
    println('[BAŞARILI] Optimizasyon tamamlandı. Ana mantık çalıştırılıyor.')
}

❓ Sorun Giderme ve SSS
S: Acode eklentisi "Geçersiz plugin.json" diyor. Ne yapmalıyım?
> C: Kök depo klasörünü DEĞİL, yalnızca acode_v_plugin dizinini seçtiğinizden emin olun. Acode, plugin.json dosyasının seçilen klasörün tam kökünde olmasını bekler.
> 
S: Termux'ta derleme yaparken neden "Erişim Reddedildi" (Permission Denied) hatası alıyorum?
> C: Termux'un Android depolama alanınızı okumak/yazmak için açık izne ihtiyacı vardır. Terminalinizde termux-setup-storage komutunu çalıştırın ve ekrana gelen Android izin istemini kabul edin.
> 
🤝 Katkıda Bulunma Yönergeleri
Tüm katkılara açığız! Bizi geliştirmemize yardımcı olmak için:
 * Projeyi Forklayın.
 * Özellik dalınızı oluşturun (git checkout -b feature/HarikaOzellik).
 * Değişikliklerinizi commit edin (git commit -m 'HarikaOzellik eklendi').
 * Dalınıza pushlayın (git push origin feature/HarikaOzellik).
 * İnceleme için bir Pull Request (Çekme İsteği) açın.


<hr>


<a id="lang-de"></a> 🇩🇪 Deutsch Dokumentation
🌟 Umfassende Übersicht
V-Verg-Language ist ein ehrgeiziges, hochoptimiertes Ökosystem, das speziell entwickelt wurde, um die Fähigkeiten der V-Programmiersprache zu erweitern. Während V weltweit für seine blitzschnelle Kompilierungsgeschwindigkeit und Speichersicherheit bekannt ist, war die Entwicklung und Optimierung von V-Anwendungen direkt in mobilen Umgebungen (wie Android über Termux) traditionell eine komplexe Herausforderung.
Dieses Projekt revolutioniert diese Erfahrung völlig, indem es sich auf drei Hauptsäulen konzentriert:
 * Mobile Editor Integration: Nahtloses Programmieren über die Acode-App.
 * Engine-Optimierung: Benutzerdefinierte AST-Auswertung und Speicherpool-Tuning.
 * Erweiterte Inline-Funktionen: Sichere Wrapper für Low-Level-C-Makros.
🚀 Tiefer Einblick in die Kernfunktionen
 * ⚡ V-Engine Optimizer (v_optimizer.v)
   * Implementiert eine aggressive Dead-Code-Eliminierung vor der Übersetzung in das C-Backend.
   * Passt die Standardeinstellungen des Arena-Allocators dynamisch an, um Out-Of-Memory (OOM)-Fehler auf ressourcenbeschränkten Android-Geräten zu vermeiden.
   * Baut den abstrakten Syntaxbaum (AST) für eine schnellere Laufzeitausführung neu auf.
 * 📱 Acode IDE Integration (acode_v_plugin)
   * Bringt kontextbezogene Syntaxhervorhebung direkt in den Android Acode-Editor.
   * Verfügt über eine integrierte JS-Brücke, die mit lokalen Hintergrund-Shells (wie Termux) kommuniziert, um v run-Befehle mit einem einzigen Tippen auszuführen.
   * Ordnet Compilerfehler direkt der spezifischen Codezeile innerhalb der Editor-Oberfläche zu.
 * 🧩 VSupport Plugins (VSupport/src)
   * Erweitert die standardmäßigen [inline]-Attribute der V-Sprache erheblich.
   * Bietet strukturierte, sicherere Umgebungen zum direkten Einbetten von rohem C-Code oder Assembly-Anweisungen in Ihre V-Quelldateien.
📂 Detaillierte Repository-Struktur
Um eine modulare und skalierbare Architektur zu erhalten, ist das Repository wie folgt strukturiert:
V-Verg-Language/
│
├── acode_v_plugin/                      # Mobile IDE Integrationsverzeichnis
│   ├── plugin.json                      # Acode-Plugin-Metadaten
│   └── main.js                          # JavaScript-Brücke für Acode & V CLI
│
├── compiler/
│   └── plugins/
│       └── VSupport/
│           └── src/                     # Inline-Funktionen und Compiler-Hooks
│               ├── inline_handler.v     # Verwaltet das Parsen von Inline-Code
│               └── support_core.v       # Kern-Erweiterungs-API
│
├── src/                                 
│   └── v_optimizer.v                    # Das Kernmodul zur Engine-Optimierung
│
├── examples/                            # Testfälle und Demoskripte
│   └── demo_app.v
│
├── LICENSE                              # MIT-Lizenz
└── README.md                            # Diese Datei

🛠️ Schritt-für-Schritt-Installation
1. Standard-Desktop-Setup (Linux / macOS / Windows)
# Klonen Sie das Repository
git clone https://github.com/BaranBey1331/V-Verg-Language.git

# Betreten Sie das Verzeichnis
cd V-Verg-Language

# Verschieben Sie den Optimierer in Ihr V-Quellverzeichnis
cp src/v_optimizer.v /path/to/v/src/

# Testen Sie die Installation mit einem Demoskript
v run examples/demo_app.v

2. Mobiles Setup (Android über Termux & Acode)
# Öffnen Sie Termux und installieren Sie die Pakete
pkg install v git

# Navigieren Sie zu Ihrem internen Speicher
cd /storage/emulated/0/Download/

# Klonen Sie das Projekt
git clone https://github.com/BaranBey1331/V-Verg-Language.git

 * Aktivierung des Acode-Plugins:
   * Öffnen Sie die Acode-App.
   * Navigieren Sie zu Einstellungen -> Plugins.
   * Wählen Sie Aus Ordner installieren.
   * Wählen Sie den Ordner /storage/emulated/0/Download/V-Verg-Language/acode_v_plugin.
   * Starten Sie Acode neu.


<hr>


<a id="lang-ru"></a> 🇷🇺 Русский Документация
🌟 Подробный обзор
V-Verg-Language — это амбициозная, высокооптимизированная экосистема, специально разработанная для расширения возможностей языка программирования V. Хотя V всемирно известен своей молниеносной скоростью компиляции и безопасностью памяти, разработка и оптимизация приложений V непосредственно в мобильных средах (таких как Android через Termux) традиционно была сложной задачей.
Этот проект полностью революционизирует этот опыт, сосредотачиваясь на трех основных направлениях:
 * Интеграция мобильного редактора: Бесшовное программирование через приложение Acode.
 * Оптимизация движка (Engine): Пользовательская оценка AST и настройка пула памяти.
 * Расширенные встроенные функции: Безопасные оболочки для низкоуровневых макросов C.
🚀 Глубокое погружение в основные функции
 * ⚡ Оптимизатор V-Engine (v_optimizer.v)
   * Реализует агрессивное устранение мертвого кода перед трансляцией в бэкенд C.
   * Динамически настраивает параметры распределителя памяти по умолчанию, чтобы предотвратить ошибки нехватки памяти (OOM) на устройствах Android.
   * Перестраивает абстрактное синтаксическое дерево (AST) для более быстрого выполнения.
 * 📱 Интеграция Acode IDE (acode_v_plugin)
   * Приносит контекстно-зависимую подсветку синтаксиса прямо в редактор Android Acode.
   * Имеет встроенный мост JS, который связывается с локальными фоновыми оболочками для выполнения команд v run одним касанием.
 * 🧩 Плагины VSupport (VSupport/src)
   * Значительно расширяет стандартные атрибуты [inline] языка V.
   * Обеспечивает структурированные и безопасные среды для встраивания необработанного кода C или инструкций Assembly.
📂 Подробная структура репозитория
V-Verg-Language/
│
├── acode_v_plugin/                      # Каталог интеграции мобильной IDE
│   ├── plugin.json                      # Метаданные плагина
│   └── main.js                          # Мост JavaScript для Acode
│
├── compiler/
│   └── plugins/
│       └── VSupport/
│           └── src/                     # Встроенные функции
│               ├── inline_handler.v     # Управление встроенным кодом
│               └── support_core.v       # Основной API
│
├── src/                                 
│   └── v_optimizer.v                    # Модуль оптимизации движка
│
├── examples/                            # Тестовые скрипты
│   └── demo_app.v
│
├── LICENSE                              # Лицензия MIT
└── README.md                            # Этот файл

🛠️ Пошаговая установка
1. Установка на десктоп (Linux / macOS / Windows)
# Клонировать репозиторий
git clone https://github.com/BaranBey1331/V-Verg-Language.git

# Войти в каталог
cd V-Verg-Language

# Переместить оптимизатор в исходный каталог V
cp src/v_optimizer.v /path/to/v/src/

# Тест
v run examples/demo_app.v

2. Мобильная установка (Android через Termux и Acode)
# В Termux
pkg install v git
cd /storage/emulated/0/Download/
git clone https://github.com/BaranBey1331/V-Verg-Language.git

 * Активация плагина Acode: Откройте Acode -> Настройки -> Плагины -> Установить из папки -> Выберите acode_v_plugin -> Перезапустите Acode.


<hr>


<a id="lang-zh"></a> 🇨🇳 中文 文档
🌟 综合概述
V-Verg-Language 是一个雄心勃勃、高度优化的生态系统，专为扩展 V 编程语言 的功能而设计。 虽然 V 语言因其惊人的编译速度和内存安全性而闻名全球，但直接在移动环境（例如通过 Termux 的 Android）中开发和优化 V 应用程序传统上是一项复杂的挑战。
该项目通过关注三个主要支柱彻底改变了这种体验：
 * 移动编辑器集成： 通过 Acode 应用程序进行无缝编码。
 * 引擎优化： 自定义 AST 评估和内存池调整。
 * 高级内联功能： 底层 C 宏的安全包装器。
🚀 核心功能深入探讨
 * ⚡ V-Engine 优化器 (v_optimizer.v)
   * 在 C 后端翻译之前实施激进的死代码消除。
   * 动态调整默认的 arena 分配器设置，以防止在资源受限的 Android 设备上出现内存不足 (OOM) 错误。
   * 重建抽象语法树 (AST) 以加快运行时执行速度。
 * 📱 Acode IDE 集成 (acode_v_plugin)
   * 将上下文感知的语法高亮直接带到 Android Acode 编辑器。
   * 具有内置的 JS 桥，可与本地后台 shell（如 Termux）通信，只需轻按一下即可执行 v run 命令。
 * 🧩 VSupport 插件 (VSupport/src)
   * 扩展了 V 语言的标准 [inline] 属性。
   * 提供结构化、更安全的环境，用于将原始 C 代码或汇编指令直接嵌入到 V 源文件中。
📂 详细仓库结构
V-Verg-Language/
│
├── acode_v_plugin/                      # 移动 IDE 集成目录
│   ├── plugin.json                      # 插件元数据
│   └── main.js                          # Acode 的 JavaScript 桥接
│
├── compiler/
│   └── plugins/
│       └── VSupport/
│           └── src/                     # 内联功能
│               ├── inline_handler.v     # 管理内联代码的解析
│               └── support_core.v       # 核心扩展 API
│
├── src/                                 
│   └── v_optimizer.v                    # 核心引擎优化模块
│
├── examples/                            # 演示脚本
│   └── demo_app.v
│
├── LICENSE                              # MIT 许可证
└── README.md                            # 本文件

🛠️ 分步安装
1. 标准桌面设置 (Linux / macOS / Windows)
# 克隆仓库
git clone https://github.com/BaranBey1331/V-Verg-Language.git

# 进入目录
cd V-Verg-Language

# 将优化器移动到 V 源目录
cp src/v_optimizer.v /path/to/v/src/

# 测试
v run examples/demo_app.v

2. 移动设置 (通过 Termux 和 Acode 在 Android 上)
# 在 Termux 中
pkg install v git
cd /storage/emulated/0/Download/
git clone https://github.com/BaranBey1331/V-Verg-Language.git

 * 激活 Acode 插件： 打开 Acode -> 设置 -> 插件 -> 从文件夹安装 -> 选择 acode_v_plugin -> 重启 Acode。
<div align="center">
<p><b>Built with ❤️ by the V-Verg-Language Open Source Community.</b></p>
</div>
