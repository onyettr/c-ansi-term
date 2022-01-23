/*!
 * @brief  ANSI Terminal Graphics operations
 * @note   
 * @author ronyett
 * @file ansigfx.c
 */

#include "ansigfx.h"

/**
 * @brief Screen Erase sequence
 * @fn    void ScreenErase(void)
 * @note
 */
void ScreenErase(void) {
   printf("\033[2J");
}

/**
 * @brief Goto <x,y> coordinates and set colour
 * @fn    void ScreenGotoxy(int x, int y, int colour)
 * @param[in] x coordinate
 * @param[in] y coordinate
 * @param[in] colour 
 * @return none
 * @note
 */
void ScreenGotoxy(int x, int y, int colour) {
  printf("\033[%d;%df\033[%dm",y,x,colour);
  //  printf("%d %d %d\n", x, y, colour);
}


/**
 * @brief Set the current foreground colour
 * @fn    void ScreenSetColour(int colour) 
 * @param[in] colour 
 * @return none
 * @note
 */
void ScreenSetColour(int colour) {
  printf("\033[0;%dm", colour);
}

/**
 * @brief Set the current back ground colour
 * @fn    void ScreenSetBackGroundColour(int colour) 
 * @param[in] colour 
 * @return none
 * @note
 */
void ScreenSetBackGroundColour(int colour) {
  printf("\033[0;%dm", colour);
}

/**
 * @brief Resets the screen defaults
 * @fn    void ScreenReset(void)
 * @return none
 * @note
 */
void ScreenReset(void) {
  printf("\033[0m");
}

/**
 * @brief   Plot an area (box) at <startX,startY> to <endX,endY> and fill with colour
 * @fn      void ScreenBox(int startX, int startY, int endX, int endY, int colour)
 * @param[in] startX
 * @param[in] startY  
 * @param[in] endX
 * @param[in] endY
 * @param[in] colour
 * @return none
 * @note
 */
void ScreenBox(int startX, int startY, int endX, int endY, int colour) {
  int rows;
  
  for (rows = startX; rows < endX; rows++) {
    int cols;    
    for (cols = (startY*rows); cols < endY; cols++) {
      ScreenGotoxy(rows,cols,colour);
    }
  }
}

