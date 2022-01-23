/*!
 * @brief ANSI Terminal Graphics operations
 * @note  Test harness
 * @author ronyett
 * @file test_colors.c
 */

#include "ansigfx.h"
typedef struct {
  int colour;
  char str_colour[8];
} test_params_t;

static test_params_t test_pattern[] = 
{
 { FG_RED,     "RED    " },
 { FG_GREEN,   "GREEN  " },
 { FG_YELLOW,  "YELLOW " },
 { FG_BLUE,    "BLUE   " },
 { FG_MAGENTA, "MAGENTA" },
 { FG_CYAN,    "CYAN   " },
 { FG_WHITE,   "WHITE  " }
};

#define DIM(X) sizeof(X)/sizeof(test_params_t)

static int test_set_colour(void) {
  int i;
  
  ScreenReset();

  ScreenSetColour(FG_MAGENTA);

  for (i=0; i< DIM(test_pattern); i++)
  {
    ScreenSetColour(test_pattern[i].colour);
    printf("%s\n", test_pattern[i].str_colour);
  }

  ScreenReset();
  printf("\n");
  
  return 0;
}

static int test_colour_xy(void)
{
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

int test_color(void)
{
  int result;

  result = test_set_colour();

  result = test_colour_xy();

  return result;
}
