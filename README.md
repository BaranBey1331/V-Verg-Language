# 🚀 V-Verg-Language: Özel V Dilimiz & V-Engine Çekirdeği

<div align="center">
  <img src="https://img.shields.io/badge/Sürüm-1.0.0--beta.4-blue?style=for-the-badge" alt="Sürüm">
  <img src="https://img.shields.io/badge/Platform-Mobil_|_Acode_|_Masaüstü-orange?style=for-the-badge" alt="Platform">
  <img src="https://img.shields.io/badge/Motor-V--Engine-red?style=for-the-badge" alt="Motor">
  <img src="https://img.shields.io/badge/Lisans-MIT-green?style=for-the-badge" alt="Lisans">
</div>

> 🌐 **Dil Seçenekleri / Выбор языка:**
> * [🇹🇷 Türkçe Dokümantasyon (Turkish)](#turkish-section)
> * [🇷🇺 Русский (Russian Translation)](#russian-section)

---

<a id="turkish-section"></a>
## 🇹🇷 TÜRKÇE DOKÜMANTASYON

V-Verg-Language resmi GitHub deposuna hoş geldiniz. Bu proje, geleneksel derleyici mimarilerini ve mevcut standart programlama dillerinin hantal yapılarını bir kenara bırakarak, doğrudan donanımla ve mobil geliştirme ortamlarıyla konuşabilen, kendi tasarladığımız özel V dilimizin ana merkezidir.

### 📋 İçindekiler
1. [Proje Vizyonu ve Temel Felsefe](#proje-vizyonu-ve-temel-felsefe)
2. [Neden Standart Vlang Değil?](#neden-standart-vlang-değil)
3. [V-Engine ve Derin Optimizasyonlar](#v-engine-ve-derin-optimizasyonlar)
4. [Acode Mobil Entegrasyonu](#acode-mobil-entegrasyonu)
5. [Derleyici Eklentileri ve VSupport](#derleyici-eklentileri-ve-vsupport)
6. [Eğitim ve Sınıf İçi Kullanım](#eğitim-ve-sınıf-içi-kullanım)
7. [Proje Dizin Mimarisi](#proje-dizin-mimarisi)
8. [Gelecek Yol Haritası](#gelecek-yol-haritası)

---

### 1. Proje Vizyonu ve Temel Felsefe

V-Verg-Language, yalnızca bir programlama dili sözdizimi oluşturma çabası değil; kaynak kodun yazılmasından, derlenmesine ve doğrudan mobil cihazlar üzerinde çalıştırılmasına kadar uzanan uçtan uca bir ekosistem projesidir. Geliştirme felsefemizin merkezinde "her yerde, her şartta kesintisiz kodlama" anlayışı yatmaktadır. Bu nedenle, hantal masaüstü IDE'lerine bağımlılığı ortadan kaldırmayı, güçlü bir derleyiciyi bir cep telefonunun belleğine sığdırmayı ve bunu yaparken de çalışma zamanı (runtime) performansından kesinlikle ödün vermemeyi hedefledik.

### 2. Neden Standart Vlang Değil?

Açık kaynak dünyasında bulunan standart V (Vlang) dili çok yetenekli olsa da, bizim mimari gereksinimlerimiz çok daha spesifikti. Standart dilin sözdizimsel sınırları ve bellek yönetim prensipleri, Acode üzerinden anlık derleme (JIT benzeri anlık tepki) yapmak ve özel V-Engine motorumuzla iletişim kurmak için yeterince esnek değildi. 

Kendi V dilimizi inşa etme kararımız bize şu özgürlükleri sağladı:
* **Tam Kontrol:** Soyut sözdizimi ağacının (AST) her bir dalına derleme aşamasında müdahale edebilme.
* **Bağımsızlık:** Herhangi bir dış kütüphane veya derleyiciye (GCC/Clang) zorunlu bağımlılık duymadan, doğrudan kendi motorumuzla makine seviyesinde işlem yapabilme.
* **Gelişmiş Inline Desteği:** Fonksiyonların çalışma zamanındaki yığın (stack) maliyetlerini sıfıra indiren ve doğrudan derleyici eklentilerimiz tarafından yönetilen agresif inline algoritmaları.

### 3. V-Engine ve Derin Optimizasyonlar

V-Engine, bu dilin kalbidir. Bellek yönetimini tamamen geliştiricinin inisiyatifine bırakan, aynı zamanda eğitim amaçlı kullanımlarda bellek sızıntılarını (memory leak) izole edilmiş ortamlarda güvenle gözlemlemeye olanak tanıyan özel bir yapıya sahiptir. 
Geleneksel dillerin aksine V-Engine, kaynak tüketen çöp toplayıcı (Garbage Collector) duraksamalarını engeller. Geliştirilen özel bellek tahsis algoritmaları sayesinde, nesnelerin yaşam döngüleri derleme anında statik olarak analiz edilir ve hafıza blokları en optimal şekilde serbest bırakılır. Bu sayede, mobil cihazların kısıtlı işlem gücü ve batarya kapasiteleri korunmuş olur.

### 4. Acode Mobil Entegrasyonu

Geliştiricilerin sadece bilgisayar başında değil, hareket halindeyken de profesyonel araçlarla çalışabilmesi için Acode kod editörü ile yerleşik bir entegrasyon sağladık. `acode_v_plugin` yapısı basit bir tema veya renklendirme eklentisi değildir; derleyicinin çekirdek modüllerini doğrudan Acode'un JavaScript tabanlı eklenti sistemine bağlayan güçlü bir köprüdür.
Bu sistem sayesinde Acode üzerinden:
* Gerçek zamanlı sözdizimi hata analizi yapılabilir.
* Anlık AST derlemesi ve betik çalıştırma testleri gerçekleştirilebilir.
* Yerleşik V-Engine sayesinde, mobil cihazın donanım kaynaklarına doğrudan, gecikmesiz erişim sağlanır.

### 5. Derleyici Eklentileri ve VSupport

Derleyicimiz monolitik bir yapıdan ziyade, eklentilerle genişletilebilir modüler bir mimari üzerine kuruludur. En kritik eklentimiz olan ve `compiler/plugins/VSupport/src/` dizini altında bulunan **VSupport** modülü, dilin standart yeteneklerinin çok ötesine geçmesini sağlar.
VSupport eklentisinin temel görevleri:
* **Agresif Inlining:** Performansın kritik olduğu döngülerde, fonksiyon çağrılarını kaynak kod seviyesinde yerleştirerek işlemci döngülerinden tasarruf sağlar.
* **Makro Genişletmeleri:** Geliştiricilerin kendi sentaks uzantılarını oluşturmalarına izin veren meta-programlama yetenekleri sunar.
* **Motor Bağlantısı (Engine Binding):** Yazılan üst düzey V kodunun, alttaki V-Engine C/Assembly katmanlarıyla eksiksiz iletişimini koordine eder.

### 6. Eğitim ve Sınıf İçi Kullanım

Bir eğitimci vizyonuyla ele alınan bu proje, yalnızca ticari bir ürün değil, aynı zamanda öğrencilerin derleyici teorisini, bilgisayar mimarisini ve bellek yönetimini yaşayarak öğrenmeleri için mükemmel bir laboratuvar ortamıdır.
Öğrenciler doğrudan VSupport modülünün kaynak kodlarına (`src/` içerisine) kendi özel optimizasyon algoritmalarını yazabilir, yazdıkları bu algoritmaların saniyeler içinde Acode üzerinde nasıl çalıştığını test edebilirler. Karmaşık C++ veya Java derleyicilerinin aksine, V-Verg'in yalın mimarisi, bir öğrencinin "Yazdığım kod işlemciye nasıl gider?" sorusunun cevabını somut olarak görmesini sağlar. Kod okunabilirliği ve pedagojik yaklaşım, mimarimizin temel taşlarındandır.

### 7. Proje Dizin Mimarisi

Sistemin yapısı, karmaşadan uzak ve tamamen işlevsellik odaklı tasarlanmıştır. Aşağıdaki yapılandırma, projenin kalbini oluşturan ana bileşenleri göstermektedir:


V-Verg-Language/
├── acode_v_plugin/             # Acode editörü için hazırlanan resmi köprü eklentisi.
│   ├── plugin.json             # Acode eklenti konfigürasyon ve izin dosyası.
│   ├── main.js                 # Editör UI entegrasyonu ve derleyici iletişim portu.
│   └── assets/                 # Mobil arayüz için gerekli ikon ve tasarım materyalleri.
├── compiler/                   # Kendi derleyicimizin ana kaynak kodları.
│   ├── core/                   # Sözcüksel analiz (Lexer) ve ayrıştırıcı (Parser).
│   └── plugins/                # Modüler derleyici genişletme klasörü.
│       └── VSupport/           # Inline desteği ve motor bağlayıcı ana eklenti.
│           └── src/            # VSupport eklentisinin kaynak kod dosyaları.
├── engine/                     # V-Engine çekirdek donanım iletişim katmanı.
│   ├── memory_manager/         # Özelleştirilmiş statik bellek tahsis algoritmaları.
│   └── concurrency/            # Çoklu iş parçacığı (Multi-threading) kontrol birimi.
└── docs/                       # Geliştirici ve öğrenci referans kılavuzları.

8. Gelecek Yol Haritası
 * Aşama 1 (Tamamlandı): Kendi V sentaksımızın lexer ve parser yapısının standart Vlang'den tamamen koparılarak özgünleştirilmesi. VSupport modülünün inşası.
 * Aşama 2 (Aktif): acode_v_plugin üzerinden gelen anlık hata ayıklama (debugging) bildirimlerinin optimizasyonu ve mobil UI tepki sürelerinin iyileştirilmesi.
 * Aşama 3 (Planlanan): V-Engine içerisine yapay zeka destekli, kodun yürütme yollarını analiz edip otomatik inline kararları verebilen analitik bir alt sistemin entegre edilmesi.
 * Aşama 4 (Gelecek): Eğitim kurumlarında ortak ağ üzerinden öğrencilerin kodlarını merkezi bir V-Engine üzerinde çalıştırıp anlık performans karşılaştırmaları yapabileceği "Sınıf Modu" (Classroom Mode) entegrasyonu.


<a id="russian-section"></a>
🇷🇺 РУССКИЙ (RUSSIAN TRANSLATION)
Добро пожаловать в официальный репозиторий V-Verg-Language. Этот проект представляет собой наш собственный, специально разработанный язык V, который оставляет позади ограничения традиционных архитектур компиляторов и стандартных языков программирования. Наша система напрямую взаимодействует с аппаратным обеспечением и мобильными средами разработки.
📋 Оглавление
 * Видение и базовая философия проекта
 * Почему не стандартный Vlang?
 * V-Engine и глубокие оптимизации
 * Мобильная интеграция с Acode
 * Плагины компилятора и VSupport
 * Использование в образовании и классах
 * Архитектура каталогов проекта
 * Дорожная карта будущего
1. Видение и базовая философия проекта
V-Verg-Language — это не просто попытка создать новый синтаксис. Это комплексная экосистема, охватывающая весь процесс: от написания исходного кода до его компиляции и прямого выполнения на мобильных устройствах. В основе нашей философии лежит концепция «непрерывного кодирования в любом месте и при любых условиях». Поэтому мы стремились устранить зависимость от громоздких настольных IDE, уместить мощный компилятор в памяти мобильного телефона и при этом не идти на компромиссы в производительности во время выполнения (runtime).
2. Почему не стандартный Vlang?
Несмотря на то, что стандартный язык V (Vlang) в мире открытого исходного кода обладает широкими возможностями, наши архитектурные требования были гораздо более специфичными. Синтаксические ограничения и принципы управления памятью стандартного языка оказались недостаточно гибкими для мгновенной компиляции (подобно JIT) через Acode и связи с нашим собственным движком V-Engine.
Решение создать собственный язык V предоставило нам следующие свободы:
 * Полный контроль: Возможность вмешиваться в каждую ветвь абстрактного синтаксического дерева (AST) на этапе компиляции.
 * Независимость: Способность работать на машинном уровне непосредственно с нашим собственным движком, без жесткой зависимости от внешних библиотек или компиляторов (GCC/Clang).
 * Расширенная поддержка Inline: Агрессивные алгоритмы встраивания (inlining), управляемые нашими плагинами компилятора, которые сводят к нулю затраты стека (stack) при вызове функций во время выполнения.
3. V-Engine и глубокие оптимизации
V-Engine — это сердце этого языка. Он обладает уникальной структурой, которая полностью передает управление памятью в руки разработчика, одновременно позволяя безопасно наблюдать за утечками памяти (memory leaks) в изолированных средах в образовательных целях.
В отличие от традиционных языков, V-Engine предотвращает ресурсоемкие паузы сборщика мусора (Garbage Collector). Благодаря специально разработанным алгоритмам выделения памяти, жизненные циклы объектов статически анализируются на этапе компиляции, и блоки памяти высвобождаются наиболее оптимальным образом. Таким образом, сохраняются ограниченная вычислительная мощность и емкость батареи мобильных устройств.
4. Мобильная интеграция с Acode
Мы обеспечили встроенную интеграцию с редактором кода Acode, чтобы разработчики могли работать с профессиональными инструментами не только за компьютером, но и на ходу. Структура acode_v_plugin — это не просто плагин для тем или подсветки синтаксиса; это мощный мост, который напрямую связывает основные модули компилятора с системой плагинов Acode на базе JavaScript.
Благодаря этой системе через Acode можно:
 * Выполнять анализ синтаксических ошибок в реальном времени.
 * Осуществлять мгновенную компиляцию AST и тестирование выполнения скриптов.
 * Получать прямой доступ к аппаратным ресурсам мобильного устройства без задержек благодаря встроенному V-Engine.
5. Плагины компилятора и VSupport
Наш компилятор построен на модульной архитектуре, расширяемой с помощью плагинов, а не на монолитной структуре. Модуль VSupport, расположенный в каталоге compiler/plugins/VSupport/src/, является нашим самым важным плагином и позволяет языку выйти далеко за пределы стандартных возможностей.
Основные задачи плагина VSupport:
 * Агрессивный Inlining: В критически важных для производительности циклах он экономит такты процессора, встраивая вызовы функций на уровне исходного кода.
 * Расширение макросов: Предоставляет возможности метапрограммирования, позволяя разработчикам создавать собственные синтаксические расширения.
 * Привязка к движку (Engine Binding): Координирует полное взаимодействие написанного на высоком уровне кода V с нижними уровнями C/Assembly движка V-Engine.
6. Использование в образовании и классах
Этот проект, разработанный с точки зрения преподавателя, является не только коммерческим продуктом, но и идеальной лабораторной средой для студентов, где они могут на практике изучать теорию компиляторов, компьютерную архитектуру и управление памятью.
Студенты могут напрямую писать свои собственные алгоритмы оптимизации в исходном коде модуля VSupport (в папке src/) и тестировать, как эти алгоритмы работают в Acode за считанные секунды. В отличие от сложных компиляторов C++ или Java, простая архитектура V-Verg позволяет студенту наглядно увидеть ответ на вопрос: «Как написанный мной код попадает в процессор?». Читаемость кода и педагогический подход являются краеугольными камнями нашей архитектуры.
7. Архитектура каталогов проекта
Структура системы спроектирована так, чтобы избежать путаницы и полностью сосредоточиться на функциональности. Следующая конфигурация демонстрирует основные компоненты, составляющие ядро проекта:
V-Verg-Language/
├── acode_v_plugin/             # Официальный плагин-мост для редактора Acode.
│   ├── plugin.json             # Файл конфигурации и разрешений плагина Acode.
│   ├── main.js                 # Интеграция UI редактора и порт связи компилятора.
│   └── assets/                 # Иконки и материалы дизайна для мобильного интерфейса.
├── compiler/                   # Основной исходный код нашего собственного компилятора.
│   ├── core/                   # Лексический анализатор (Lexer) и парсер (Parser).
│   └── plugins/                # Папка для модульного расширения компилятора.
│       └── VSupport/           # Основной плагин для поддержки inline и привязки движка.
│           └── src/            # Файлы исходного кода плагина VSupport.
├── engine/                     # Уровень связи ядра V-Engine с оборудованием.
│   ├── memory_manager/         # Индивидуализированные алгоритмы статического выделения памяти.
│   └── concurrency/            # Блок контроля многопоточности (Multi-threading).
└── docs/                       # Справочные руководства для разработчиков и студентов.

8. Дорожная карта будущего
 * Этап 1 (Завершен): Полное отделение структуры лексического анализатора и парсера нашего собственного синтаксиса V от стандартного Vlang. Создание модуля VSupport.
 * Этап 2 (Активен): Оптимизация уведомлений об отладке (debugging) в реальном времени через acode_v_plugin и улучшение времени отклика мобильного UI.
 * Этап 3 (Запланирован): Интеграция в V-Engine аналитической подсистемы на базе искусственного интеллекта, способной анализировать пути выполнения кода и принимать автоматические решения об inline-оптимизациях.
 * Этап 4 (В будущем): Интеграция «Режима класса» (Classroom Mode), где студенты в образовательных учреждениях смогут запускать свой код через общую сеть на централизованном V-Engine и проводить мгновенные сравнения производительности.
<div align="center">
<b>&copy; V-Verg-Language Project</b>

<i>Eğitim ve İnovasyon İçin Geliştirilmiştir / Разработано для образования и инноваций</i>
</div>
