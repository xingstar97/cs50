#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE tmp;
            tmp.rgbtBlue = image[i][j].rgbtBlue;
            tmp.rgbtRed = image[i][j].rgbtRed;
            tmp.rgbtGreen = image[i][j].rgbtGreen;

            image[i][j].rgbtBlue = (tmp.rgbtBlue + tmp.rgbtRed + tmp.rgbtGreen);
            image[i][j].rgbtRed = image[i][j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][j].rgbtBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE tmp;
            tmp.rgbtBlue = image[i][j].rgbtBlue;
            tmp.rgbtRed = image[i][j].rgbtRed;
            tmp.rgbtGreen = image[i][j].rgbtGreen;

            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            float blue = 0;
            float red = 0;
            float green = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                if (k >= 0 && k < height)
                {

                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        // printf("i: %i, j: %i, k: %i, l: %i", i,j,k,l);

                        if (l >= 0 && l < width)
                        {
                            blue += image[k][l].rgbtBlue;
                            red += image[k][l].rgbtRed;
                            green += image[k][l].rgbtGreen;

                            count++;
                        }
                    }
                }
            }
            // printf("count: %i", count);
            // BYTE a = 128;
            // a += 128;
            // a += 10;
            // printf("a : %i", a);
            image[i][j].rgbtBlue = (blue / count);
            image[i][j].rgbtRed = (red / count);
            image[i][j].rgbtGreen = (green / count);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    double red1 = 0;
    double red2 = 0;
    double blue1 = 0;
    double blue2 = 0;
    double green1 = 0;
    double green2 = 0;
    RGBTRIPLE temp[height][width];

    // printf("image[9][9].rgbtBlue = %i", image[9][9].rgbtBlue);
    // printf("image[9][10].rgbtBlue = %i", image[9][10].rgbtBlue);
    // printf("image[9][11].rgbtBlue = %i", image[9][11].rgbtBlue);
    // printf("image[10][9].rgbtBlue = %i", image[10][9].rgbtBlue);
    // printf("image[10][10].rgbtBlue = %i", image[10][10].rgbtBlue);
    // printf("image[10][11].rgbtBlue = %i", image[10][11].rgbtBlue);
    // printf("image[11][9].rgbtBlue = %i", image[11][9].rgbtBlue);
    // printf("image[11][10].rgbtBlue = %i", image[11][10].rgbtBlue);
    // printf("image[11][11].rgbtBlue = %i\n", image[11][11].rgbtBlue);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red1 = 0;
            red2 = 0;
            blue1 = 0;
            blue2 = 0;
            green1 = 0;
            green2 = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                if (k >= 0 && k < height)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if (l >= 0 && l < width)
                        {
                          //  if(i == 10 && j == 10){
                           // printf("k = %i\n", k);
                           // printf("l = %i\n", l);

                            // printf("gx[k - i + 1][l - j + 1] = %i\n", gx[k - i + 1][l - j + 1]);
                            // printf("gy[k - i + 1][l - j + 1] = %i\n", gy[k - i + 1][l - j + 1]);
                            // printf("k - i + 1 = %i\n", k - i + 1);
                            // printf("[l - j + 1] = %i\n", l - j + 1);
                            //printf("image[k][l].rgbtBlue = %i\n", image[k][l].rgbtBlue);
                           // printf("image[9][9].rgbtBlue = %i\n", image[9][9].rgbtBlue);
                            // printf("blue2= %lf\n", blue2);
                          //  }
                            blue2 += image[k][l].rgbtBlue * gx[k - i + 1][l - j + 1];
                            red2 += image[k][l].rgbtRed * gx[k - i + 1][l - j + 1];
                            green2 += image[k][l].rgbtGreen * gx[k - i + 1][l - j + 1];

                            blue1 += image[k][l].rgbtBlue * gy[k - i + 1][l - j + 1];
                            red1 += image[k][l].rgbtRed * gy[k - i + 1][l - j + 1];
                            green1 += image[k][l].rgbtGreen * gy[k - i + 1][l - j + 1];
                            
                            // if(i == 10 && j == 10){
                            //     printf("image[%i][%i].rgbtBlue = %i\n", k,l, image[k][l].rgbtBlue);
                            //     printf("image[%i][%i].rgbtRed = %i\n", k,l, image[k][l].rgbtRed);
                            //     printf("image[%i][%i].rgbtGreen = %i\n", k,l, image[k][l].rgbtGreen);
                            //     // printf("image[%f][%f].rgbtBlue = %f\n", k,l, image[k][l].rgbtBlue);
                            //     // printf("image[%f][%f].rgbtBlue = %f\n", k,l, image[k][l].rgbtBlue);
                            //     // printf("image[%f][%f].rgbtBlue = %f\n", k,l, image[k][l].rgbtBlue);
                            // }
                        }
                    }
                }
            }
            // if(i == 10 && j == 10)
            // printf("before: image[%i][%i]=%i\n",i,j,image[i][j].rgbtBlue);
            int a = round(sqrt(blue1 * blue1 + blue2 * blue2));
            int b = round(sqrt(red1 * red1 + red2 * red2));
            int c = round(sqrt(green1 * green1 + green2 * green2));
            // if(i == 10 && j == 10){
            // printf("after: a=%i\n",a);
            // printf("after: b=%i\n",b);
            // printf("after: c=%i\n",c);
            // printf("after: blue1=%lf\n",blue1);
            // printf("after: blue2=%lf\n",blue2);
            // printf("after: c=%i\n",c);
            // printf("after: red1=%lf\n",red1);
            // printf("after: red2=%lf\n",red2);
            // printf("after: sqrt(red1)=%lf\n",sqrt(red1));
            // printf("after: red2=%lf\n",red2);
            // printf("after: image[%f][%f]=%f\n",i,j,image[i][j].rgbtBlue);
            }

            if (a > 255)
            {
                temp[i][j].rgbtBlue = 255;
            }
            else{
                temp[i][j].rgbtBlue = (int)a;
            }
            if (b > 255)
            {
                temp[i][j].rgbtRed = 255;
            }
            else{
                temp[i][j].rgbtRed = (int)b;
            }
            if (c > 255)
            {
                temp[i][j].rgbtGreen = 255;
            }
            else{
                temp[i][j].rgbtGreen = (int)c;
            }
        }
    }

    for (int i = 0; i<height; i++)
    {
        for (int j = 0; j<width; j++)
        {
            image[i][j]=temp[i][j];
        }
    }
}
