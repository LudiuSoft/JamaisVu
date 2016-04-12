//
// Created by chemicalchems on 5/04/16.
//

#include "TUI.h"

TUI::TUI() {

}

void TUI::drawFrames() { //TODO: Refactor and change var names to more descriptive names
    std::u32string middleVerticalFrameString;

    if (console.consoleSize.x % 2 == 0) {middleVerticalFrameString = U"┃┃";}
    else                                {middleVerticalFrameString = U" ┃";}

    int upperMiddleHorizontalFrameLimit;
    int lowerMiddleHorizontalFrameLimit;

    if (console.consoleSize.y % 2 == 0)
    {
        upperMiddleHorizontalFrameLimit = console.consoleSize.y/2;
        lowerMiddleHorizontalFrameLimit = upperMiddleHorizontalFrameLimit + 1;
    }

    else
    {
        upperMiddleHorizontalFrameLimit = console.consoleSize.y/2;
        lowerMiddleHorizontalFrameLimit = upperMiddleHorizontalFrameLimit + 2;
    }

    std::vector<std::u32string> frameLines;

    for (int row = 1; row <= console.consoleSize.y; row++)
    {
        std::u32string line;

        line.resize(console.consoleSize.x, char32_t(32)); //fill line with spaces

        line.replace(console.consoleSize.x/2-1, middleVerticalFrameString.length(), middleVerticalFrameString);

        if (row == 1)
        {
            line.replace(0, line.length(), line.length(), char32_t(9473));
            line.replace(0, 1, U"┏");
            line.replace(console.consoleSize.x/2, 1, U"┳");
            line.replace(console.consoleSize.x-1, 1, U"┓");
        }
        else if (row > upperMiddleHorizontalFrameLimit && row < lowerMiddleHorizontalFrameLimit)
        {
            line.replace(0, line.length(), line.length(), char32_t(9473));
            line.replace(console.consoleSize.x/2, 1, U"╋");
            line.replace(0, 1, U"┣");
            line.replace(console.consoleSize.x-1, 1, U"┫");
        }
        else if (row == console.consoleSize.y)
        {
            line.replace(0, line.length(), line.length(), char32_t(9473));
            line.replace(0, 1, U"┗");
            line.replace(console.consoleSize.x/2, 1, U"┻");
            line.replace(console.consoleSize.x-1, 1, U"┛");
        }
        else
        {
            line.replace(0,1,U"┃");
            line.replace(console.consoleSize.x-1, 1, U"┃");
        }
        frameLines.push_back(line);
    }

    console.draw(frameLines);
}