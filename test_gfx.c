/*!
 * @brief ANSI Terminal Graphics operations
 * @note  Test harness
 * @author ronyett
 * @file test_gfx.c
 */

#include "ansigfx.h"
#include "test_gfx.h"

int test_gfx(void) {
  int result;
  
  /*
   * Insert tests
   */

  result = test_color();
  
  return result;
}
