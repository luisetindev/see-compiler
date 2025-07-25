#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>



enum class TokenType {
    RPARENT,
    LPARENT,
};

struct Token {
    TokenType type;
    std::string value;
};


class Lexer{

    private:
        char _currentChar;
        int _currentIdx;
        std::string _tokenBuffer;
        std::vector<Token> tokens;
        
    
    public:
        std::string content;

        Lexer(std::string fileContent){
            this->content = fileContent;
            this->_currentIdx = -1;
        }
        
        char getCurrentChar() const { return this->_currentChar; };
        int getCurrentIdx() const {return this-> _currentIdx; };
        char advance();
        void consumeToken();
        void consumeAll();
        
        


};


#endif 