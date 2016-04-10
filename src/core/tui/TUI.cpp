//
// Created by chemicalchems on 5/04/16.
//

#include "TUI.h"

TUI::TUI() {

}

void TUI::drawFrames() {
    std::u32string middleVerticalFrameString;

    if (console.consoleSize.x % 2 == 0) {middleVerticalFrameString = U"┃┃";}
    else                                {middleVerticalFrameString = U"┃╋┃";}

    std::vector<std::u32string> middleVerticalFrameStrings;
    std::vector<std::u32string> middleHorizontalFrameStrings;

    std::vector<Vector2<int>> middleVerticalFrameStringPositions;
    std::vector<Vector2<int>> middleHorizontalFrameStringPositions;


    for (int row = 1; row <= console.consoleSize.y; row++)
    {
        middleVerticalFrameStrings.push_back(middleVerticalFrameString);
        if (console.consoleSize.x % 2 == 0)
        {
            middleVerticalFrameStringPositions.push_back(Vector2<int>{console.consoleSize.x/2, row});
        }
        else
        {
            middleVerticalFrameStringPositions.push_back(Vector2<int>{console.consoleSize.x/2+1, row});
        }
    }

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

    for (int row = upperMiddleHorizontalFrameLimit; row <= lowerMiddleHorizontalFrameLimit; row++)
    {
        std::u32string chars;
        if (console.consoleSize.x % 2 == 0)
        {
            chars.insert(0, console.consoleSize.x/2-1, char32_t(9473));
            chars += U"  ";
            chars.insert(console.consoleSize.x/2, console.consoleSize.x/2+1, char32_t(9473));
        }
        else
        {
            chars.insert(0, console.consoleSize.x/2, char32_t(9473));
            chars += U"  ";
            chars.insert(console.x, console.consoleSize.x/2-1, char32_t(9473));
        }
        middleHorizontalFrameStrings.push_back(chars);
        middleHorizontalFrameStringPositions.push_back(Vector2<int> {1, row});
    }

    console.draw(middleVerticalFrameStrings, middleVerticalFrameStringPositions);
    console.draw(middleHorizontalFrameStrings, middleHorizontalFrameStringPositions);
}