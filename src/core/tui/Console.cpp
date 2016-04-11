//
// Created by chemicalchems on 1/04/16.
//

#include "Console.h"
#include "../util/toStr.h"
#include <sstream>
#include <codecvt>
#include <locale>
#include <assert.h>
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
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

void Console::draw(const std::vector<std::u32string>& chars,
                   const std::vector<std::vector<std::initializer_list<AnsiTextCode>>>& formats) {


    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter; //Used to pass from u32string to bytes

    assert(("Format size and text size don't match", chars.size() == formats.size()));

    for (int stringIndex = 0; stringIndex <= chars.size() - 1; stringIndex++)
    {
        assert(("Format size and text size don't match", chars.at(stringIndex).size() == formats.at(stringIndex).size()));

        for (int charIndex = 0; charIndex <= chars.at(stringIndex).size() - 1; charIndex++)
        {
            this->setTextFormat(formats.at(stringIndex).at(charIndex));
            std::cout << converter.to_bytes(chars.at(stringIndex).at(charIndex));
            this->resetTextFormat();
        }
        std::cout << std::endl;
    }
}

Vector2<int> Console::getNativeConsoleSize() {
#if (defined(_WIN32) || defined(_WIN64))
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo( hConsoleOut, &csbiInfo );
    return Vector2<int> (csbiInfo.srWindow.Right - csbiInfo.srWindow.Left +1, csbiInfo.srWindow.Bottom - csbiInfo.srWindow.Top +1);
#else
    winsize size;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
    return Vector2<int> {size.ws_col, size.ws_row};
#endif
}


Console::Console() {
    this->consoleSize = this->getNativeConsoleSize();
    this->clearConsole();
}

Console::~Console() {
    //this->clearConsole();
}
