// About PGM: http://netpbm.sourceforge.net/doc/pgm.html

#include <stdint.h>
#include <iostream>
#include <fstream>
#include <string>

#define WIDTH 480
#define HEIGHT 360
#define MAX_VAL 65535

void drawpgm (std::string filename, int width, int height, int max_val, uint16_t image[WIDTH][HEIGHT]);

int main (int argc, char * argv[])
{
  std::string filename = "sample_image.pgm";
  uint16_t image[WIDTH][HEIGHT];

  // Sample 2D array 
  for (int i = 0; i < WIDTH; i++)
  {
    for (int j = 0; j < HEIGHT; j++)
    {
      image[i][j] = MAX_VAL - 10*i - 10*j;
    }
  }

  drawpgm(filename, WIDTH, HEIGHT, MAX_VAL, image);
  std::cout << "Done. PGM image is " << filename << std::endl;
  return 0;
}

void drawpgm (std::string filename, int width, int height, int max_val, uint16_t image[WIDTH][HEIGHT]) 
{
  // File
  std::fstream outfile(filename.c_str(), std::ios::out | std::ios::binary);

  // Headers 
  outfile << "P5 " << width << " " << height << " " << max_val << std::endl;

  // Image
  for (int i = 0; i < WIDTH; i++) 
  {
    for (int j = 0; j < HEIGHT; j++)
    {     
      outfile.write((char*)&image[i][j], sizeof(uint16_t)); 
    }
  }

  outfile.close();
}
