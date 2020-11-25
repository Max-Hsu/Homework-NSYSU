#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
enum Tag :int {
    AND = 256   ,
    BASIC       ,
    BREAK       ,
    DO          ,
    ELSE        ,
    EQ          ,
    FALSE       ,
    GE 		    ,
    ID 		    ,
    IF 		    ,
    INDEX 	    ,
    LE 		    ,
    MINUS 	    ,
    NE 		    ,
    NUM 	    ,
    OR 		    ,
    REAL 		,
    TEMP 		,
    TRUE 		,
    WHILE
};
class Token{
    public:
        int w;
};
class Word:public Token{
    public:
        string lexeme;
        Word(string s , int tag){
            w = tag;
            lexeme = s;
        }
};
class Lexer{
    public:
        void reserve(Word w){
            words.insert({w.lexeme , w.w });
        }
        Lexer(){
            reserve(Word("if"   ,   Tag::IF));
        }
    private:
        unordered_map<string , int> words;
};