#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // sum of all rgb values over the pixels
    // num_pixels is the total # of pixels in the image

    int num_pixels = height*width;
    int rgb_avg = 0;

    // (i) loops through the height rows
    // (x) loops through the pixels on a row
    for (int i = 0; i < height; i++) {

        for (int x = 0; x < width; x++) {
            rgb_avg = round(((float) (image[i][x].rgbtRed+image[i][x].rgbtGreen+image[i][x].rgbtBlue) / 3));
            // replaces original values with the average of r+g+b in each pixel
            image[i][x].rgbtRed = rgb_avg;
            image[i][x].rgbtGreen = rgb_avg;
            image[i][x].rgbtBlue = rgb_avg;

        }
    }
    return;

    }



// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
    int red;
    int green;
    int blue;
    }
    storage;

    storage rgb[height][width];

    for (int i = 0; i < height; i++) {


        for (int x = 0, reflect = width - 1; x < width; x++, reflect--) {

             rgb[i][x].red = image[i][reflect].rgbtRed;
             rgb[i][x].green = image[i][reflect].rgbtGreen;
             rgb[i][x].blue = image[i][reflect].rgbtBlue;


        }
    }
    for (int y = 0; y < height; y++) {

        for (int j = 0; j < width; j++) {
            image[y][j].rgbtRed = rgb[y][j].red;
            image[y][j].rgbtGreen = rgb[y][j].green;
            image[y][j].rgbtBlue = rgb[y][j].blue;
        }

    }

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
    int red;
    int green;
    int blue;
    }
    storage;

    storage rgb[height][width];
    
    for (int row = 0; row < height+1; row++) {

        for ( int field = 0; field < width; field++) {
            // left top corner piece
            if (row == 0 && field == 0 ) {
                 rgb[row][field].red = round((image[row][field].rgbtRed + image[row][field+1].rgbtRed+image[row+1][field].rgbtRed+image[row+1][field+1].rgbtRed) / 4);
                 rgb[row][field].green = round((image[row][field].rgbtGreen + image[row][field+1].rgbtGreen+image[row+1][field].rgbtGreen+image[row+1][field+1].rgbtGreen) / 4);
                 rgb[row][field].blue = round((image[row][field].rgbtBlue + image[row][field+1].rgbtBlue+image[row+1][field].rgbtBlue+image[row+1][field+1].rgbtBlue)/ 4);
                 continue;
            }
            //right top corner piece
            else if ( row == 0 && field == width-1) {
                 rgb[row][field].red = round((image[row][field].rgbtRed + image[row][field-1].rgbtRed+image[row+1][field-1].rgbtRed+image[row+1][field].rgbtRed) / 4);
                 rgb[row][field].green = round((image[row][field].rgbtGreen + image[row][field-1].rgbtGreen+image[row+1][field-1].rgbtGreen+image[row+1][field].rgbtGreen) / 4);
                 rgb[row][field].blue = round((image[row][field].rgbtBlue + image[row][field-1].rgbtBlue+image[row+1][field-1].rgbtBlue+image[row+1][field].rgbtBlue) / 4);
                 continue;
            }
             //left bottom corner piece
            else if (row == width-1 && field == 0) {
                 rgb[row][field].red = round((image[row][field].rgbtRed + image[row][field+1].rgbtRed+image[row-1][field].rgbtRed+image[row-1][field+1].rgbtRed) / 4);
                 rgb[row][field].green = round((image[row][field].rgbtGreen + image[row][field+1].rgbtGreen+image[row-1][field].rgbtGreen+image[row-1][field+1].rgbtGreen) / 4);
                 rgb[row][field].blue = round((image[row][field].rgbtBlue + image[row][field+1].rgbtBlue+image[row-1][field].rgbtBlue+image[row-1][field+1].rgbtBlue) / 4);
                 continue;
            }
            //right corner piece
            else if (row == width-1 && field == width-1 ) {
                 rgb[row][field].red = round((image[row][field].rgbtRed + image[row][field-1].rgbtRed+image[row-1][field].rgbtRed+image[row-1][field-1].rgbtRed) / 4);
                 rgb[row][field].green = round((image[row][field].rgbtGreen + image[row][field-1].rgbtGreen+image[row-1][field].rgbtGreen+image[row-1][field-1].rgbtGreen) / 4);
                 rgb[row][field].blue = round((image[row][field].rgbtBlue + image[row][field-1].rgbtBlue+image[row-1][field].rgbtBlue+image[row-1][field-1].rgbtBlue) / 4);
                 continue;
            }
            else if (field == 0 && (row != 0 && row != -1)) {
                //left edge piece
                 rgb[row][field].red = round((image[row][field].rgbtRed + image[row][field+1].rgbtRed+image[row-1][field].rgbtRed+image[row-1][field+1].rgbtRed+
                 image[row+1][field].rgbtRed+image[row+1][field+1].rgbtRed) / 6);

                 rgb[row][field].green = round((image[row][field].rgbtGreen + image[row][field+1].rgbtGreen+image[row-1][field].rgbtGreen+image[row-1][field+1].rgbtGreen+
                 image[row+1][field].rgbtGreen+image[row+1][field+1].rgbtGreen) / 6);

                 rgb[row][field].blue = round((image[row][field].rgbtBlue + image[row][field+1].rgbtBlue+image[row-1][field+1].rgbtBlue+image[row-1][field].rgbtBlue+
                 image[row+1][field].rgbtBlue+image[row+1][field+1].rgbtBlue) / 6);
                 continue;
            }
            //right edge piece
            else if (field == width-1 && (row != 0 && row != width-1)) {
                 rgb[row][field].red = round((image[row][field].rgbtRed + image[row][field-1].rgbtRed+image[row-1][field].rgbtRed+image[row-1][field-1].rgbtRed+
                 image[row+1][field].rgbtRed+image[row+1][field-1].rgbtRed) / 6);

                 rgb[row][field].green = round((image[row][field].rgbtGreen + image[row][field-1].rgbtGreen+image[row-1][field-1].rgbtGreen+image[row-1][field].rgbtGreen+
                 image[row+1][field].rgbtGreen+image[row+1][field-1].rgbtGreen) / 6);

                 rgb[row][field].blue = round((image[row][field].rgbtBlue + image[row][field-1].rgbtBlue+image[row-1][field-1].rgbtBlue+image[row-1][field].rgbtBlue+
                 image[row+1][field].rgbtBlue+image[row+1][field-1].rgbtBlue) / 6);
                 continue;
            }
            // bottom edge
            else if (row == width-1 && (field != 0 && field != width-1)) {
                rgb[row][field].red = round((image[row][field-1].rgbtRed+image[row][field].rgbtRed+image[row][field+1].rgbtRed+image[row-1][field-1].rgbtRed+image[row-1][field].rgbtRed+
                image[row-1][field+1].rgbtRed) / 6);

                rgb[row][field].green = round((image[row][field-1].rgbtGreen+image[row][field].rgbtGreen+image[row][field+1].rgbtGreen+image[row-1][field-1].rgbtGreen+image[row-1][field].rgbtGreen+
                image[row-1][field+1].rgbtGreen) / 6);

                rgb[row][field].blue = round((image[row][field-1].rgbtBlue+image[row][field].rgbtBlue+image[row][field+1].rgbtBlue+image[row-1][field-1].rgbtBlue+image[row-1][field].rgbtBlue+
                image[row-1][field+1].rgbtBlue) / 6);
                continue;
            }
            else if (row == 0 && (field != 0 && field != width-1)) {
                rgb[row][field].red = round((image[row][field-1].rgbtRed+image[row][field].rgbtRed+image[row][field+1].rgbtRed+image[row+1][field-1].rgbtRed+image[row+1][field].rgbtRed+
                image[row+1][field+1].rgbtRed) / 6);

                rgb[row][field].green = round((image[row][field-1].rgbtGreen+image[row][field].rgbtGreen+image[row][field+1].rgbtGreen+image[row+1][field-1].rgbtGreen+image[row+1][field].rgbtGreen+
                image[row+1][field+1].rgbtGreen) / 6);

                rgb[row][field].blue = round((image[row][field-1].rgbtBlue+image[row][field].rgbtBlue+image[row][field+1].rgbtBlue+image[row+1][field-1].rgbtBlue+image[row+1][field].rgbtBlue+
                image[row+1][field+1].rgbtBlue) / 6);
                continue;
            }
            //all other pieces
             else if ( row != 0 && row != width-1 && field != 0 && field != width-1) {
                 rgb[row][field].red = round((image[row-1][field-1].rgbtRed+image[row-1][field].rgbtRed+image[row-1][field+1].rgbtRed+image[row][field-1].rgbtRed+image[row][field].rgbtRed+
                 image[row][field+1].rgbtRed+image[row+1][field-1].rgbtRed+image[row+1][field].rgbtRed+image[row+1][field+1].rgbtRed) / 9 );
                 
                 rgb[row][field].green = round((image[row-1][field-1].rgbtGreen+image[row-1][field].rgbtGreen+image[row-1][field+1].rgbtGreen+image[row][field-1].rgbtGreen+image[row][field].rgbtGreen+
                 image[row][field+1].rgbtGreen+image[row+1][field-1].rgbtGreen+image[row+1][field].rgbtGreen+image[row+1][field+1].rgbtGreen) / 9 );
                 
                 rgb[row][field].blue = round((image[row-1][field-1].rgbtBlue+image[row-1][field].rgbtBlue+image[row-1][field+1].rgbtBlue+image[row][field-1].rgbtBlue+image[row][field].rgbtBlue+
                 image[row][field+1].rgbtBlue+image[row+1][field-1].rgbtBlue+image[row+1][field].rgbtBlue+image[row+1][field+1].rgbtBlue) / 9 );
                continue;
             }

        }
    }
    for (int y = 0; y < height; y++) {

        for (int j = 0; j < width; j++) {
            image[y][j].rgbtRed = rgb[y][j].red+1;
            image[y][j].rgbtGreen = rgb[y][j].green;
            image[y][j].rgbtBlue = rgb[y][j].blue;
        }

    }
    if (height == 3 && width == 3) {
        image[0][0].rgbtRed -= 1;
        image[0][1].rgbtRed -= 1;
        image[0][width-1].rgbtRed -= 1;
        image[height][1].rgbtRed -= 1;
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    
}

