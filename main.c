/*!
 * @brief ANSI Terminal Graphics operations
 * @note 
 * @author ronyett
 * @file  main.c
 */

#include "ansigfx.h"
#include "test_gfx.h"

int main (void) {

  test_gfx();
  test_color();
  test_mandel();
  exit(1);
}
