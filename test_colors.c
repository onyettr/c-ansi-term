/*!
 * @brief ANSI Terminal Graphics operations
 * @note  Test harness
 * @author ronyett
 * @file test_color.c
 */

#include "ansigfx.h"

int test_color(void) {
  
  ScreenReset();

  ScreenSetColour(FG_MAGENTA);
  printf("Magenta");

  ScreenGotoxy(10,10,FG_RED);
  printf("RED");
  ScreenGotoxy(11,12,FG_GREEN);
  printf("GREEN");
  ScreenGotoxy(12,13,FG_YELLOW);
  printf("YELLOW");
  ScreenGotoxy(13,14,FG_BLUE);
  printf("BLUE");
  ScreenGotoxy(14,15,FG_MAGENTA);
  printf("MAGENTA");
  ScreenGotoxy(15,16,FG_CYAN);
  printf("CYAN");

  ScreenSetColour(BG_RED);
  printf("Back RED");
  
  ScreenReset();
  printf("\n");

  return 1;
}
