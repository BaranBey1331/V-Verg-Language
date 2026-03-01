#pragma once
#include <string>
#include <vector>

// === V DİLİNİN KELİME DAĞARCIĞI ===
enum class TokenType {
    // Veri Tipleri
        ID, NUMBER, STRING,
            
                // Anahtar Kelimeler (Keywords)
                    IMPORT, AS, FUNC, IF, TRUE, FALSE, VAR, RETURN,
                        
                            // Operatörler
                                EQUALS,         // =
                                    PLUS,           // +
                                        MINUS,          // -
                                            MULTIPLY,       // *
                                                DIVIDE,         // /
                                                    EQUALS_EQUALS,  // ==
                                                        
                                                            // Noktalama ve Semboller
                                                                LPAREN,         // (
                                                                    RPAREN,         // )
                                                                        LBRACE,         // {
                                                                            RBRACE,         // }
                                                                                COMMA,          // ,
                                                                                    DOT,            // .  (Örn: djs.banUser için kritik)
                                                                                        COLON,          // :  (Örn: ZeroCache: true için kritik)
                                                                                            
                                                                                                // Dosya Sonu İşareti
                                                                                                    EOF_TOKEN
                                                                                                    };

                                                                                                    // === YENİ TOKEN YAPISI (HATA AYIKLAMA İÇİN) ===
                                                                                                    // Artık her kelime, kodun neresinde olduğunu biliyor!
                                                                                                    struct Token {
                                                                                                        TokenType type;
                                                                                                            std::string value;
                                                                                                                int line;    // Hatanın olduğu SATIR
                                                                                                                    int column;  // Hatanın olduğu SÜTUN
                                                                                                                    };

                                                                                                                    // === SÖZCÜK ANALİZÖRÜ (LEXER) SINIFI ===
                                                                                                                    class Lexer {
                                                                                                                    private:
                                                                                                                        std::string source;
                                                                                                                            size_t pos;
                                                                                                                                int current_line;    // Derleyici şu an hangi satırda?
                                                                                                                                    int current_column;  // Derleyici şu an hangi sütunda?

                                                                                                                                        // İç yardımcı fonksiyonlar
                                                                                                                                            void advance();
                                                                                                                                                char peek();
                                                                                                                                                    void skipWhitespace();
                                                                                                                                                        
                                                                                                                                                            // Kelime üreticiler
                                                                                                                                                                Token number();
                                                                                                                                                                    Token id_or_keyword();
                                                                                                                                                                        Token string_literal();

                                                                                                                                                                        public:
                                                                                                                                                                            // Yapıcı metod
                                                                                                                                                                                Lexer(const std::string& src);
                                                                                                                                                                                    
                                                                                                                                                                                        // Motoru başlatan ve tüm kelimeleri dizi olarak döndüren ana fonksiyon
                                                                                                                                                                                            std::vector<Token> tokenize();
                                                                                                                                                                                            };
                                                                                                                                                                                            