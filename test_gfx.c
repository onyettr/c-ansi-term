/*!
 * @brief ANSI Terminal Graphics operations
 * @note  Test harness
 * @author ronyett
 * @file test_gfx.c
 */
#include <stdio.h>
#include "ansigfx.h"
#include "test_gfx.h"

int test_gfx(void) {
  int result = 0;
  
  /*
   * Insert tests
   */
  // result = test_color();

  ScreenErase();
  
  return result;
}
