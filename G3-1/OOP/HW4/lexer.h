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
const char  * Tag_name[] = {
    "AND"   ,
    "BASIC"       ,
    "BREAK"       ,
    "DO"          ,
    "ELSE"        ,
    "EQ"          ,
    "FALSE"       ,
    "GE" 		    ,
    "ID" 		    ,
    "IF" 		    ,
    "INDEX" 	    ,
    "LE" 		    ,
    "MINUS" 	    ,
    "NE" 		    ,
    "NUM" 	    ,
    "OR" 		    ,
    "REAL" 		,
    "TEMP" 		,
    "TRUE" 		,
    "WHILE"
};

class Token{
    public:
        int w;      //tag as w
        Token(int t){
            w = t;
        }
        virtual string toString(){
            string symbol(1,char(w));
            string output = symbol+"\t\t("+symbol+")";
            return output;
        }
};
class Word:public Token{
    public:
        string lexeme;
        Word(string s , int tag):Token(tag){
            lexeme = s;
        }
        string toString(){
            string output = lexeme+"\t\t("+string(Tag_name[w-256])+")";
            return output;
        }
        static Word And; //'and' will cause error ? guessing keyword
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
            return this->width == x.width && this->lexeme == x.lexeme; //!!!dirty check using public lexeme 
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
                return Type("",0,-1);
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
            string output = to_string(value)+"\t\t("+string(Tag_name[w-256])+")";
            return output;
        }
};
class Real:public Token{
    public:
        float value;
        Real(float v):Token(Tag::REAL){
            value = v;
        }
        string toString(){
            string output = to_string(value)+"\t\t("+string(Tag_name[w-256])+")";
            return output;
        }
};

class Lexer{
    public:
        void reserve(Word * w){
            words.insert({w->lexeme , w });
        }
        Lexer(string file_name){
            IN_file = file_handler(file_name);
            reserve(new Word("if"       ,   Tag::IF));
            reserve(new Word("else"     ,   Tag::ELSE));
            reserve(new Word("while"    ,   Tag::WHILE));
            reserve(new Word("do"       ,   Tag::DO));
            reserve(new Word("break"    ,   Tag::BREAK));
            reserve(&Word::True);
            reserve(&Word::False);
            reserve(&Type::Int);
            reserve(&Type::Char);
            reserve(&Type::Bool);
            reserve(&Type::Float);
        }
        int file_status(){
            int status;
            char dummy;
            dummy = IN_file.char_peek(status);
            return status;
        }
        void readch(){  //stupid eof check i just want to skip

        }
        bool readch(char c){    //peek next character
            int status = 0;
            character = IN_file.char_get(status);
            if( character != c){
                return false;
            }
            character = ' ';
            return true;
        }
        char return_true_char(int & status){
            char read = IN_file.char_get(status);
            while(read == ' ' || read == '\n' || read == '\t'){
                if(read == '\n'){
                    line = line+1;
                }
                read = IN_file.char_get(status);
            }
            return read;
        }
        Token * scan(){
            int status = 0;
            character = return_true_char(status);
            if(status == -1){
                return new Token(-1);
            }
            switch (character){
                case '&':
                    if(readch('&')){
                        return &Word::And;
                    }
                    else{
                        return new Token('&');
                    }
                    break;
                case '|':
                    if(readch('|')){
                        return &Word::Or;
                    }
                    else{
                        return new Token('|');
                    }
                    break;
                case '=':
                    if(readch('=')){
                        return &Word::eq;
                    }
                    else{
                        return new Token('=');
                    }
                    break;
                case '!':
                    if(readch('=')){
                        return &Word::ne;
                    }
                    else{
                        return new Token('=');
                    }
                    break;
                case '<':
                    if(readch('=')){
                        return &Word::le;
                    }
                    else{
                        return new Token('<');
                    }
                    break;
                case '>':
                    if(readch('=')){
                        return &Word::ge;
                    }
                    else{
                        return new Token('>');
                    }
                    break;
            }
            if(isdigit(character)){
                int v = 0;
                do{
                    v = 10 * v + (character - '0');
                    character = IN_file.char_peek(status);
                    if(!isdigit(character)){
                        break;
                    }
                    character = IN_file.char_get(status);
                }while(status == 0 && isdigit(character));
                if(character != '.'){
                    return new Num(v);
                }
                character = IN_file.char_get(status);
                float x = v;
                float d = 10;
                character = IN_file.char_peek(status);
                while(status ==0 ){
                    if(!isdigit(character)){
                        break;
                    }
                    character = IN_file.char_get(status);
                    x = x + (character - '0') / d;
                    d = d * 10;
                    character = IN_file.char_peek(status);
                }
                return new Real(x);
            }
            if(isalpha(character)){
                string b (1,character);
                character = IN_file.char_peek(status);
                while(status == 0){
                    if(isalpha(character)){
                        character = IN_file.char_get(status);
                        b.append(1,character);
                    }
                    else{
                        break;
                    }
                    character = IN_file.char_peek(status);
                }
                unordered_map<string,Word *>::const_iterator W = words.find(b); //!!not quiet sure if this will work 
                if(W != words.end()){   //found
                    return W->second;   //!!so does this line
                }
                Word * Wx = new Word(b,Tag::ID);
                words.insert({b,Wx});
                return Wx;
            }
            char backup = character;
            character = ' ';
            return new Token(backup);
        }

    private:
        unordered_map<string , Word *> words;
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
Word Word::True("true",Tag::TRUE);
Word Word::False("false",Tag::FALSE);
Word Word::temp("t",Tag::TEMP);

Type Type::Int("int"    , Tag::BASIC    ,4);
Type Type::Float("float", Tag::BASIC    ,8);
Type Type::Char("char"    , Tag::BASIC    ,1);
Type Type::Bool("bool"    , Tag::BASIC    ,1);
