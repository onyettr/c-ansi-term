/*!
 * @brief ANSI Terminal Graphics operations
 * @note 
 * @author ronyett
 */

#include "ansigfx.h"

void ScreenErase(void) {
   printf("\033[2J");
}

void ScreenGotoxy(int x, int y, int colour) {
  printf("\033[%d;%df\033[%dm",y,x,colour);
}

void ScreenSetColour(int colour) {
  printf("\033[0;%dm", colour);
}

void ScreenSetBackGroundColour(int colour) {
  printf("\033[0;%dm", colour);
}

void ScreenReset() {
  printf("\033[0m");
}

void ScreenBox(int startX, int startY, int endX, int endY, int colour) {
  int rows;
  
  for (rows = startX; rows < endX; rows++) {
    int cols;    
    for (cols = (startY*rows); cols < endY; cols++) {
      ScreenGotoxy(rows,cols,colour);
    }
  }
}

