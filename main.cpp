#include <iostream>
#include <fstream>
#include <filesystem>

#include "lexer.h"


std::string readFile(std::string filename){

    std::ifstream file(filename);

    if(!file.is_open()){
        std::cerr << "File could not be opened." << std::endl;
        return "";
    }

    auto size = std::filesystem::file_size(filename);

    std::string content(size, '\0');
    file.read(&content[0], size);

    return content;

}


int main(){

    std::string content = readFile("examples/1-hello.c");

    if(!content.length()){
        return -1;
    }

    Lexer lexer(content);
    lexer.consumeAll();
    lexer.visualizeTokens();

    return 0;
}