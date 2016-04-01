//
// Created by chemicalchems on 1/04/16.
//

#ifndef JAMAISVU_ANSITEXTOPTIONS_H
#define JAMAISVU_ANSITEXTOPTIONS_H


enum AnsiTextOptions
{
    /* GENERAL SETTINGS */
    reset           = 0,
    bold            = 1,
    dim             = 2,
    underlined      = 4,
    blink           = 5, //Doesn't work on most terminals
    inverted        = 7,
    hidden          = 8,
    rm_bold         = 21,
    rm_dim          = 22,
    rm_underlined   = 24,
    rm_blink        = 25,
    rm_inverted     = 27,
    rm_hidden       = 28,

    /* FOREGROUND COLORS */
    fg_black        = 30,
    fg_red          = 31,
    fg_green        = 32,
    fg_yellow       = 33,
    fg_blue         = 34,
    fg_magenta      = 35,
    fg_cyan         = 36,
    fg_lightgray    = 37,
    fg_default      = 39,
    fg_darkgray     = 90,
    fg_lightred     = 91,
    fg_lightgreen   = 92,
    fg_lightyellow  = 93,
    fg_lightblue    = 94,
    fg_lightmagenta = 95,
    fg_lightcyan    = 96,
    fg_white        = 97,

    /* BACKGROUND COLORS */
    bg_black        = 40,
    bg_red          = 41,
    bg_green        = 42,
    bg_yellow       = 43,
    bg_blue         = 44,
    bg_magenta      = 45,
    bg_cyan         = 46,
    bg_lightgray    = 47,
    bg_default      = 49,
    bg_darkgray     = 100,
    bg_lightred     = 101,
    bg_lightgreen   = 102,
    bg_lightyellow  = 103,
    bg_lightblue    = 104,
    bg_lightmagenta = 105,
    bg_lightcyan    = 106,
    bg_white        = 107,

};


#endif //JAMAISVU_ANSITEXTOPTIONS_H
