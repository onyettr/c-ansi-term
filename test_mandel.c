/*!
 * @brief ANSI Terminal Graphics operations
 * @note  Test harness
 * @author ronyett
 * @file test_madell.c
 */
#include <stdio.h>
#include "ansigfx.h"
#include "test_gfx.h"

#define MAXCOUNT 30

int mandel(void)
{
  float r,i,R,I,b;
  int n = 2;

  for(i=-1;i<1;i+=.06,puts(""))
    for(r=-2;I=i,(R=r)<1;
        r+=.03,ScreenSetColour((n % 8) + 40),putchar(n+31))
      for(n=0;b=I*I,26>n++&&R*R+b<4;I=2*R*I+i,R=R*R-b+r);

  return n;
}

void fractal(float left, float top, float xside, float yside)
{
    float xscale, yscale, zx, zy, cx, tempx, cy;
    int x, y;
    int maxx, maxy, count;
  
    // getting maximum value of x-axis of screen
    //    maxx = getmaxx();
    maxx = 50;  
    // getting maximum value of y-axis of screen
    maxy = 40;
  
    // setting up the xscale and yscale
    xscale = xside / maxx;
    yscale = yside / maxy;
  
    // calling rectangle function
    // where required image will be seen
    //    rectangle(0, 0, maxx, maxy);
  
    // scanning every point in that rectangular area.
    // Each point represents a Complex number (x + yi).
    // Iterate that complex number
    for (y = 1; y <= maxy - 1; y++) {
        for (x = 1; x <= maxx - 1; x++)
        {
            // c_real
            cx = x * xscale + left;
  
            // c_imaginary
            cy = y * yscale + top;
  
            // z_real
            zx = 0;
  
            // z_imaginary
            zy = 0;
            count = 0;
  
            // Calculate whether c(c_real + c_imaginary) belongs
            // to the Mandelbrot set or not and draw a pixel
            // at coordinates (x, y) accordingly
            // If you reach the Maximum number of iterations
            // and If the distance from the origin is
            // greater than 2 exit the loop
            while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
            {
                // Calculate Mandelbrot function
                // z = z*z + c where z is a complex number
  
                // tempx = z_real*_real - z_imaginary*z_imaginary + c_real
                tempx = zx * zx - zy * zy + cx;
  
                // 2*z_real*z_imaginary + c_imaginary
                zy = 2 * zx * zy + cy;
  
                // Updating z_real = tempx
                zx = tempx;
  
                // Increment count
                count = count + 1;
            }
  
            // To display the created fractal
            putchar((char)(count + 31));
            ScreenGotoxy(x, y, (count % 8) + 40); 
        }
    }
}

int test_mandel3(void)
{
  int height = 70; // 30;
  int width  = 100; // 80;
  int max = 1000;
  
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
        double c_re = (col - width/2.0)*4.0/width;
        double c_im = (row - height/2.0)*4.0/width;
        double x = 0, y = 0;
        int iteration = 0;
        while (x*x+y*y <= 4 && iteration < max) {
            double x_new = x*x - y*y + c_re;
            y = 2*x*y + c_im;
            x = x_new;
            iteration++;
        }
        if (iteration < max) {
          printf("*"); ScreenGotoxy(col, row, (iteration % 8)+40);
        } else ScreenGotoxy(col, row, FG_BLUE);
    }
}
  return 0;
}


// Driver code
int test_mandel4(void)
{
    float left, top, xside, yside;
  
    // setting the left, top, xside and yside
    // for the screen and image to be displayed
    left = -1.75;
    top = -0.25;
    xside = 0.25;
    yside = 0.45;

    // Function calling
     fractal(left, top, xside, yside);
  
    return 0;
}

int test_mandel(void) {
  int result = 0;
  
  /*
   * Insert tests
   */

  //  result = test_color();
  ScreenErase();

  //  test_mandel2();
  test_mandel3();  
  
  //  test_mandel();
  
  return result;
}
