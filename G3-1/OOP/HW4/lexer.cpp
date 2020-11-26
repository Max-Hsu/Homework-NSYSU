#include <iostream>
#include <string>
#include <unordered_map>
#include "file_handle.h"


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
        int w;      //tag as w
        Token(int t){
            w = t;
        }
        string toString(){
            return string(1,char(w));
        }
};
class Word:public Token{
    public:
        string lexeme;
        Word(string s , int tag):Token(tag){
            lexeme = s;
        }
        string toString(){
            return lexeme;
        }
        static Word And; //'and' will cause error
        static Word Or;  //same as 'or'
        static Word eq;
        static Word ne;
        static Word le;
        static Word ge;
        static Word minus;
        static Word True;
        static Word False;
        static Word temp;     
};

class Type:public Word{
    public:
        int width = 0;
        Type(string s , int tag , int wid):Word(s,tag){
            width = wid;
        }
        static Type Int;
        static Type Float;
        static Type Char;
        static Type Bool;
        bool operator==(Type x){
            return this->width == x.width; //@need to add word comparesion
        }
        bool numeric(Type p){
            if (p == Type::Char || p == Type::Int || p == Type::Float){
                return true;
            }
            else{
                return false;
            }
        }
        Type max(Type p1 , Type p2){
            if(!numeric(p1)||!numeric(p2)){
                //!!! return null - too dirty , instead I want to write Type("",0,-1)
            }
            else if(p1 == Type::Float || p2 == Type::Float){
                return Type::Float;
            }
            else if(p1 == Type::Int || p2 == Type::Int){
                return Type::Int;
            }
            else{
                return Type::Char;
            }
        }
};
class Num:public Token{
    public:
        int value;
        Num(int v):Token(Tag::NUM){
            value = v;
        }
        string toString(){
            return to_string(value);
        }
};
class Real:public Token{
    public:
        float value;
        Real(float v):Token(Tag::REAL){
            value = v;
        }
        string toString(){
            return to_string(value);
        }
};

class Lexer{
    public:
        void reserve(Word w){
            words.insert({w.lexeme , w });
        }
        Lexer(){
            reserve(Word("if"       ,   Tag::IF));
            reserve(Word("else"     ,   Tag::ELSE));
            reserve(Word("while"    ,   Tag::WHILE));
            reserve(Word("do"       ,   Tag::DO));
            reserve(Word("break"    ,   Tag::BREAK));
            reserve(Word::True);
            reserve(Word::False);
            reserve(Type::Int);
            reserve(Type::Char);
            reserve(Type::Bool);
            reserve(Type::Float);
        }
        void readch(){  //stupid eof check i just want to skip

        }
        bool readch(char c){    //peek next character
            int status = 0;
            character = IN_file.char_peek(status);
            if( character != c){
                return false;
            }
            character = ' ';
            return true;
        }
        Token scan(){
            int status = 0;
            
            character = IN_file.char_get(status);
            while(status ==0){
                if(character == ' ' || character == '\t'){
                    continue;
                }
                else if(character == '\n'){
                    line = line+1;
                }
                else{
                    break;
                }
                character = IN_file.char_get(status);
            }
            switch (character){
                case '&':
                    if(readch('&')){
                        return Word::And;
                    }
                    else{
                        //return Token('&');
                    }
                    break;
                case '|':
                    if(readch('|')){
                        return Word::Or;
                    }
                    else{
                        //return Token('|');
                    }
                    break;
                case '=':
                    if(readch('=')){
                        return Word::eq;
                    }
                    else{
                        //return Token('=');
                    }
                    break;
                case '!':
                    if(readch('=')){
                        return Word::ne;
                    }
                    else{
                        //return Token('=');
                    }
                    break;
                case '<':
                    if(readch('=')){
                        return Word::le;
                    }
                    else{
                        //return Token('<');
                    }
                    break;
                case '>':
                    if(readch('=')){
                        return Word::ge;
                    }
                    else{
                        //return Token('>');
                    }
                    break;
            }
            if(isdigit(character)){
                int v = 0;
                do{
                    v = 10 * v + (character - '0');
                    character = IN_file.char_peek(status);
                }while(status == 0 &&isdigit(character));
                if(character != '.'){
                    //return new Num(v);
                }
                float x = v;
                float d = 10;
                character = IN_file.char_get(status);
                while(status ==0 ){
                    if(!isdigit(character)){
                        break;
                    }
                    x = x + (character - '0') / d;
                    d = d * 10;
                }
                return 0;//!!!Real(x);
            }
            if(isalpha(character)){

                string b (1,character);
                character = IN_file.char_get(status);
                while(status == 0){
                    if(isalpha(character)){
                        b.append(1,character);
                    }
                    character = IN_file.char_get(status);
                }
                unordered_map<string,Word>::const_iterator W = words.find(b); //!!not quiet sure if this will work 
                if(W != words.end()){   //not found
                    return W->second;   //!!so does this line
                }
                Word Wx(b,Tag::ID);
                words.insert({b,Wx});
            }
            Token tok(character);
            character = ' ';
            return tok;
        }

    private:
        unordered_map<string , Word> words;
        file_handler IN_file;
        char character;
        int line = 1;
};

Word Word::And("&&",Tag::AND);
Word Word::Or("||",Tag::OR);
Word Word::eq("==",Tag::EQ);
Word Word::ne("!=",Tag::NE);
Word Word::le("<=",Tag::LE);
Word Word::ge(">=",Tag::GE);
Word Word::minus("minus",Tag::MINUS);
Word Word::True("True",Tag::TRUE);
Word Word::False("false",Tag::FALSE);
Word Word::temp("t",Tag::TEMP);
/*
Type Type::Int("int"    , Tag::BASIC    ,4);
Type Type::Float("float", Tag::BASIC    ,8);
Type Type::Char("char"    , Tag::BASIC    ,1);
Type Type::Bool("bool"    , Tag::BASIC    ,1);
*/