#include "lexer.h"


char Lexer::advance(){

    int step = 1;
    this->_currentIdx += 1;
    this->_currentChar = this->content.at(this->_currentIdx);
    return this->_currentChar;
}

void Lexer::consumeAll(){
    while(this->_currentIdx < (int) this->content.length()-1){
        this->consumeToken();
    }
    for(Token t : this->tokens){
        std::cout << t.value << std::endl;
    }
}

void Lexer::consumeToken(){

    char current = this->advance();

    Token t;

    if(current == '('){
        t.type = TokenType::LPARENT;
        t.value = current;
        this->tokens.push_back(t);
    }
    else if(current == ')'){
        t.type = TokenType::RPARENT;
        t.value = current;
        this->tokens.push_back(t);
    }

    // std::cout << this->advance() << std::endl;
}

