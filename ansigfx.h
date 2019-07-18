/*!
 * @brief ANSI Terminal Graphics operations
 * @note 
 * @author ronyett
 * @file ansigfx.h
 */
#ifndef __ANSIGFX_H__
#define __ANSIGFX_H__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ansigfx.h"

/*
 * ANSI Escape Graphics - Colours, all 8 of them!
 */
#define FG_BLACK    30
#define FG_RED      31
#define FG_GREEN    32
#define FG_YELLOW   33
#define FG_BLUE     34
#define FG_MAGENTA  35
#define FG_CYAN     36
#define FG_WHITE    37


#define BG_BLACK    40
#define BG_RED      41
#define BG_GREEN    42
#define BG_YELLOW   43
#define BG_BLUE     44
#define BG_MAGENTA  45
#define BG_CYAN     46
#define BG_WHITE    47

void ScreenErase(void);
void ScreenGotoxy(int x, int y, int colour);
void ScreenSetBackGroundColour(int colour);
void ScreenSetColour(int colour);
void ScreenReset(void);
void ScreenBox(int startX, int startY, int endX, int endY, int colour);

#endif
