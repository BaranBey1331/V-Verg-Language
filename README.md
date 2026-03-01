<div align="center">
🚀 V-Verg-Language
Advanced Tooling, Engine Optimization, and Mobile IDE Integration for the V Programming Language
🌐 Select Language
🇬🇧 English   |   🇹🇷 Türkçe   |   🇩🇪 Deutsch   |   🇷🇺 Русский   |   🇨🇳 中文


<hr>
</div>
<a id="lang-en"></a> 🇬🇧 English Documentation
🌟 Project Overview
V-Verg-Language is a specialized ecosystem built to enhance the V Programming Language. It eliminates the complexities of mobile development and provides deep engine-level optimizations.
Instead of a complex file structure, this project is divided into specific, highly focused modules. Below is a detailed explanation of every core function and module.
🛠️ Core Modules & Functions
1. The Engine Optimizer (v_optimizer.v)
This module is responsible for making your V code run faster and consume less memory, especially on constrained devices like Android phones.
 * optimize_ast(mut tree ASTNode)
   Analyzes the Abstract Syntax Tree (AST) before compilation. It finds inefficiencies and restructures the nodes for faster execution.
 * eliminate_dead_code()
   Scans the entire project for variables, functions, or imports that are declared but never used. It strips these out entirely before the C translation phase.
 * tune_memory_pool(profile: .mobile)
   Adjusts V's default arena allocator. By using the .mobile profile, it prevents aggressive memory grabs, avoiding Out-Of-Memory (OOM) crashes on Android via Termux.
2. Mobile IDE Integration (acode_v_plugin)
We bring a full V development environment to your phone using the Acode app.
 * Syntax & Context Highlighting
   The plugin understands V syntax perfectly. It colors keywords, types, and functions dynamically as you type on your mobile keyboard.
 * One-Tap Compile & Run Bridge
   A hidden JavaScript bridge communicates with your background shell (like Termux). You press one button in Acode, and the plugin executes v run your_file.v silently, showing the output in the editor.
 * Real-time Error Mapping
   If the compiler throws an error, the plugin catches the exact line number from the terminal output and highlights the broken code line directly inside Acode.
3. Advanced Inline Capabilities (VSupport)
This module gives you safer, structured access to low-level system operations.
 * handle_c_macro(macro_string string)
   Allows you to securely embed complex C macros directly into your V code without breaking the V parser.
 * inject_assembly(arch string, code string)
   A structured wrapper for injecting raw Assembly instructions specifically targeted at either ARM (mobile) or x86 architectures.
🚀 Installation Guide
Desktop (Linux/macOS/Windows):
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)

Mobile (Android via Termux):
pkg install v git
cd /storage/emulated/0/Download/
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)

(Install the acode_v_plugin folder via Acode Settings -> Plugins -> Install from folder)




<hr>
<a id="lang-tr"></a> 🇹🇷 Türkçe Dokümantasyon
🌟 Proje Genel Bakışı
V-Verg-Language, V Programlama Dilini geliştirmek için oluşturulmuş özel bir ekosistemdir. Mobil geliştirmenin karmaşıklıklarını ortadan kaldırır ve derin motor (engine) seviyesinde optimizasyonlar sunar.
Karmaşık bir dosya yapısı yerine, bu proje belirli ve son derece odaklanmış modüllere bölünmüştür. Aşağıda her bir temel fonksiyonun ve modülün detaylı açıklaması yer almaktadır.
🛠️ Temel Modüller ve Fonksiyonlar
1. Motor Optimize Edici (v_optimizer.v)
Bu modül, V kodunuzun özellikle Android telefonlar gibi kısıtlı cihazlarda daha hızlı çalışmasını ve daha az bellek tüketmesini sağlamaktan sorumludur.
 * optimize_ast(mut tree ASTNode)
   Derlemeden önce Soyut Sözdizimi Ağacını (AST) analiz eder. Verimsizlikleri bulur ve daha hızlı yürütme için düğümleri (nodes) yeniden yapılandırır.
 * eliminate_dead_code()
   Tüm projeyi tanımlanmış ancak hiç kullanılmamış değişkenler, fonksiyonlar veya içe aktarmalar (imports) için tarar. C çeviri aşamasından önce bunları tamamen temizler.
 * tune_memory_pool(profile: .mobile)
   V'nin varsayılan arena bellek tahsis edicisini ayarlar. .mobile profilini kullanarak agresif bellek alımlarını engeller ve Termux üzerinden Android'de yetersiz bellek (OOM) çökmelerini önler.
2. Mobil IDE Entegrasyonu (acode_v_plugin)
Acode uygulamasını kullanarak telefonunuza tam bir V geliştirme ortamı getiriyoruz.
 * Sözdizimi ve Bağlam Vurgulama
   Eklenti, V sözdizimini mükemmel bir şekilde anlar. Mobil klavyenizde yazarken anahtar kelimeleri, türleri ve fonksiyonları dinamik olarak renklendirir.
 * Tek Dokunuşla Derle ve Çalıştır Köprüsü
   Gizli bir JavaScript köprüsü, arka plan kabuğunuzla (Termux gibi) iletişim kurar. Acode'da bir düğmeye basarsınız ve eklenti sessizce v run dosyaniz.v komutunu çalıştırarak çıktıyı editörde gösterir.
 * Gerçek Zamanlı Hata Eşleme
   Derleyici bir hata verirse, eklenti terminal çıktısından tam satır numarasını yakalar ve doğrudan Acode içinde hatalı kod satırını vurgular.
3. Gelişmiş Satıriçi (Inline) Yetenekleri (VSupport)
Bu modül size düşük seviyeli sistem operasyonlarına daha güvenli, yapılandırılmış erişim sağlar.
 * handle_c_macro(macro_string string)
   Karmaşık C makrolarını, V ayrıştırıcısını (parser) bozmadan doğrudan V kodunuza güvenli bir şekilde gömmenizi sağlar.
 * inject_assembly(arch string, code string)
   Özellikle ARM (mobil) veya x86 mimarilerini hedefleyen ham Assembly talimatlarını enjekte etmek için yapılandırılmış bir sarmalayıcı (wrapper).
🚀 Kurulum Rehberi
Masaüstü (Linux/macOS/Windows):
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)

Mobil (Termux üzerinden Android):
pkg install v git
cd /storage/emulated/0/Download/
git clone [https://github.com/BaranBey1331/V-Verg-Language.git](https://github.com/BaranBey1331/V-Verg-Language.git)

(Acode Ayarları -> Eklentiler -> Klasörden yükle üzerinden acode_v_plugin klasörünü yükleyin)




<hr>
<a id="lang-de"></a> 🇩🇪 Deutsch Dokumentation
🌟 Projektübersicht
V-Verg-Language ist ein spezialisiertes Ökosystem, das zur Verbesserung der V-Programmiersprache entwickelt wurde. Es beseitigt die Komplexität der mobilen Entwicklung und bietet tiefe Optimierungen auf Engine-Ebene.
Anstelle einer komplexen Dateistruktur ist dieses Projekt in spezifische, hochfokussierte Module unterteilt. Nachfolgend finden Sie eine detaillierte Erklärung aller Kernfunktionen und Module.
🛠️ Kernmodule & Funktionen
1. Der Engine Optimizer (v_optimizer.v)
Dieses Modul ist dafür verantwortlich, dass Ihr V-Code schneller ausgeführt wird und weniger Speicher verbraucht, insbesondere auf eingeschränkten Geräten wie Android-Telefonen.
 * optimize_ast(mut tree ASTNode)
   Analysiert den abstrakten Syntaxbaum (AST) vor der Kompilierung. Es findet Ineffizienzen und strukturiert die Knoten für eine schnellere Ausführung um.
 * eliminate_dead_code()
   Durchsucht das gesamte Projekt nach Variablen, Funktionen oder Importen, die deklariert, aber nie verwendet wurden. Diese werden vor der C-Übersetzungsphase vollständig entfernt.
 * tune_memory_pool(profile: .mobile)
   Passt den standardmäßigen Arena-Allocator von V an. Durch Verwendung des Profils .mobile werden aggressive Speicherzugriffe verhindert und Out-Of-Memory (OOM)-Abstürze vermieden.
2. Mobile IDE Integration (acode_v_plugin)
Wir bringen eine vollständige V-Entwicklungsumgebung mit der Acode-App auf Ihr Telefon.
 * Syntax- & Kontexthervorhebung
   Das Plugin versteht die V-Syntax perfekt. Es färbt Schlüsselwörter, Typen und Funktionen dynamisch ein.
 * One-Tap Kompilieren & Ausführen
   Eine versteckte JavaScript-Brücke kommuniziert mit Ihrer Hintergrund-Shell (wie Termux). Sie drücken eine Taste und das Plugin führt v run im Hintergrund aus.
 * Echtzeit-Fehlerzuordnung
   Wenn der Compiler einen Fehler ausgibt, fängt das Plugin die genaue Zeilennummer ab und markiert die fehlerhafte Codezeile direkt in Acode.
3. Erweiterte Inline-Funktionen (VSupport)
Dieses Modul bietet Ihnen einen sichereren, strukturierten Zugriff auf systemnahe Operationen.
 * handle_c_macro(macro_string string)
   Ermöglicht die sichere Einbettung komplexer C-Makros direkt in Ihren V-Code.
 * inject_assembly(arch string, code string)
   Ein strukturierter Wrapper zum Injizieren von rohen Assembly-Anweisungen, gezielt für ARM (mobil) oder x86-Architekturen.




<hr>
<a id="lang-ru"></a> 🇷🇺 Русский Документация
🌟 Обзор проекта
V-Verg-Language — это специализированная экосистема, созданная для улучшения языка программирования V. Она устраняет сложности мобильной разработки и обеспечивает глубокую оптимизацию на уровне движка.
Вместо сложной файловой структуры этот проект разделен на конкретные модули. Ниже приведено подробное объяснение всех основных функций и модулей.
🛠️ Основные модули и функции
1. Оптимизатор движка (v_optimizer.v)
Этот модуль отвечает за то, чтобы ваш код V работал быстрее и потреблял меньше памяти, особенно на таких устройствах, как телефоны Android.
 * optimize_ast(mut tree ASTNode)
   Анализирует абстрактное синтаксическое дерево (AST) перед компиляцией. Находит неэффективности и реструктурирует узлы для более быстрого выполнения.
 * eliminate_dead_code()
   Сканирует весь проект на наличие переменных, функций или импортов, которые объявлены, но никогда не используются. Полностью удаляет их перед фазой перевода на C.
 * tune_memory_pool(profile: .mobile)
   Настраивает распределитель памяти V по умолчанию. Использование профиля .mobile предотвращает сбои из-за нехватки памяти (OOM).
2. Интеграция мобильной IDE (acode_v_plugin)
Мы переносим полноценную среду разработки V на ваш телефон с помощью приложения Acode.
 * Подсветка синтаксиса
   Плагин идеально понимает синтаксис V. Он динамически раскрашивает ключевые слова и типы.
 * Компиляция и запуск в одно касание
   Скрытый мост JavaScript связывается с вашей фоновой оболочкой (например, Termux). Вы нажимаете кнопку, и плагин незаметно выполняет v run.
 * Отображение ошибок в реальном времени
   Если компилятор выдает ошибку, плагин перехватывает точный номер строки и выделяет поврежденную строку кода прямо в Acode.
3. Расширенные встроенные функции (VSupport)
Этот модуль дает вам безопасный, структурированный доступ к низкоуровневым системным операциям.
 * handle_c_macro(macro_string string)
   Позволяет безопасно встраивать сложные макросы C прямо в ваш код V.
 * inject_assembly(arch string, code string)
   Структурированная оболочка для внедрения необработанных инструкций Assembly.




<hr>
<a id="lang-zh"></a> 🇨🇳 中文 文档
🌟 项目概述
V-Verg-Language 是一个专门构建的生态系统，用于增强 V 编程语言。它消除了移动开发的复杂性，并提供了深入引擎级别的优化。
本项目没有复杂的文件结构，而是划分为特定且高度专注的模块。下面是所有核心功能和模块的详细说明。
🛠️ 核心模块与功能
1. 引擎优化器 (v_optimizer.v)
此模块负责使您的 V 代码运行得更快，消耗的内存更少，尤其是在 Android 手机等受限设备上。
 * optimize_ast(mut tree ASTNode)
   在编译之前分析抽象语法树 (AST)。它会发现效率低下的地方并重组节点以加快执行速度。
 * eliminate_dead_code()
   扫描整个项目，查找已声明但从未使用过的变量、函数或导入。在 C 翻译阶段之前将它们完全剥离。
 * tune_memory_pool(profile: .mobile)
   调整 V 的默认 arena 分配器。通过使用 .mobile 配置文件，可以防止严重的内存占用，避免内存不足 (OOM) 崩溃。
2. 移动 IDE 集成 (acode_v_plugin)
我们使用 Acode 应用程序将完整的 V 开发环境带到您的手机上。
 * 语法和上下文高亮
   该插件完美理解 V 语法。它会在您键入时动态地对关键字、类型和函数进行着色。
 * 一键编译和运行桥接
   一个隐藏的 JavaScript 桥接器与您的后台 shell（如 Termux）通信。您在 Acode 中按下一个按钮，插件就会静默执行 v run。
 * 实时错误映射
   如果编译器抛出错误，该插件会捕获确切的行号，并直接在 Acode 内高亮显示损坏的代码行。
3. 高级内联功能 (VSupport)
该模块为您提供了对底层系统操作的更安全、结构化的访问。
 * handle_c_macro(macro_string string)
   允许您安全地将复杂的 C 宏直接嵌入到您的 V 代码中，而不会破坏 V 解析器。
 * inject_assembly(arch string, code string)
   用于注入原始汇编指令的结构化包装器，专门针对 ARM（移动）或 x86 架构。
<div align="center">
<p><b>Built with ❤️ by the V-Verg-Language Open Source Community.</b></p>
</div>
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
