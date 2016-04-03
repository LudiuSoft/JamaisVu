//
// Created by chemicalchems on 1/04/16.
//

#include "Console.h"
#include "../util/toStr.h"

void Console::setTextFormat(std::initializer_list<AnsiTextCode> textCodes) {
    std::string ansiTextFormat = "\033[0";
    for (AnsiTextCode textCode : textCodes)
    {
        ansiTextFormat += ";";
        ansiTextFormat += toStr(textCode);
    }
    ansiTextFormat += "m";

    std::cout << ansiTextFormat;
}

void Console::resetTextFormat() {
    std::cout << "\033[0;39;49m";
}

void Console::setCursorPosition(const Vector2<int>& position) {
    std::cout << "\033[" << position.y << ";" << position.x << "H";
}

void Console::setCursorPosition(const int& x, const int& y) {
    this->setCursorPosition(Vector2<int>(x,y));
}

void Console::clearConsole() {
    std::cout << "\033[2J";
    this->setCursorPosition(1,1);
}

void Console::print(const std::string& text) {
    std::cout << text;
}

void Console::draw(const std::vector<std::string>& chars) {
    for (std::string line : chars) { std::cout << line << std::endl;}
}

Console::Console() {
    this->clearConsole();
}

Console::~Console() {
    this->clearConsole();
}
