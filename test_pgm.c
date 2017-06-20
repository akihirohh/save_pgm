// About PGM: http://netpbm.sourceforge.net/doc/pgm.html

#include <stdio.h>
#include <stdint.h>

#define WIDTH 480
#define HEIGHT 360
#define MAX_VAL 65535

void drawpgm (char * filename, int width, int height, int max_val, uint16_t image[WIDTH][HEIGHT]);

int main (int argc, char * argv[])
{
	char filename[200];
  uint16_t image[WIDTH][HEIGHT];

  // Sample 2D array 
  for (int i = 0; i < WIDTH; i++)
  {
    for (int j = 0; j < HEIGHT; j++)
    {
      image[i][j] = MAX_VAL - 10*i - 10*j;
    }
  }

  sprintf(filename, "image.pgm");
	drawpgm(filename, WIDTH, HEIGHT, MAX_VAL, image);
	
	printf("Done.\n");
	return 0;
}

void drawpgm (char * filename, int width, int height, int max_val, uint16_t image[WIDTH][HEIGHT]) 
{
  FILE * outfile;
  outfile = fopen(filename, "wb");

  // Headers 
  fprintf(outfile, "P5 ");
  fprintf(outfile, "%d ", width);
  fprintf(outfile, "%d ", height);
  fprintf(outfile, "%d\n", max_val);

  // Image
  for (int i = 0; i < WIDTH; i++) 
  {
    for (int j = 0; j < HEIGHT; j++)
    {     
      fprintf(outfile, "%c", image[i][j] >> 8);
      fprintf(outfile, "%c", image[i][j]);
    }
  }
  fclose(outfile);
}
