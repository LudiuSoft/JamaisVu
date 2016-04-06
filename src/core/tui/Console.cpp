//
// Created by chemicalchems on 1/04/16.
//

#include "Console.h"
#include "../util/toStr.h"
#include <iostream>
#include <sstream>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <zconf.h>
#endif

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
    //this->clearConsole();
}

Vector2<int> Console::getNativeConsoleSize() {
#if defined(_WIN32) || defined(_WIN64)
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo( hConsoleOut, &csbiInfo );
    return Vector2<int> {csbiInfo.dwSize.X, csbiInfo.dwSize.Y};
#else
    winsize size;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
    return Vector2<int> {size.ws_col, size.ws_row};
#endif
}
