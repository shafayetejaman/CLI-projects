#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // convarting every row and coloum
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            float blue = image[r][c].rgbtBlue;
            float green = image[r][c].rgbtGreen;
            float red = image[r][c].rgbtRed;

            float sum = blue + green + red;
            int avg = round(sum / 3.00);

            image[r][c].rgbtBlue = avg;
            image[r][c].rgbtGreen = avg;
            image[r][c].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            float Blue = image[r][c].rgbtBlue;
            float Green = image[r][c].rgbtGreen;
            float Red = image[r][c].rgbtRed;

            int sepiaRed = round(.393 * Red + .769 * Green + .189 * Blue);
            int sepiaGreen = round(.349 * Red + .686 * Green + .168 * Blue);
            int sepiaBlue = round(.272 * Red + .534 * Green + .131 * Blue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[r][c].rgbtBlue = sepiaBlue;
            image[r][c].rgbtGreen = sepiaGreen;
            image[r][c].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0, i = width/2; c < width/2  || i >= 0; c++, i--)
        {
            RGBTRIPLE temp1 = image[r][c];
            image[r][c] = image[r][i];
            image[r][i] = temp1;
        }

    }
    return;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            temp[r][c] = image[r][c];
        }
    }
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            int sum_Blue, sum_Red, sum_Green;
            sum_Blue = sum_Red = sum_Green = 0.0;
            float count = 0.0;
            for (int x = r - 1; x < r + 2; x++)
            {
                for (int y = c - 1; y < c + 2; y++)
                {
                    if (x < 0 || x > (height - 1) || y < 0 || y > (width - 1))
                    {
                        continue;
                    }

                    sum_Blue += image[x][y].rgbtBlue;
                    sum_Green += image[x][y].rgbtGreen;
                    sum_Red += image[x][y].rgbtRed;
                    count++;
                }
            }
            temp[r][c].rgbtBlue = round(sum_Blue / count);
            temp[r][c].rgbtGreen = round(sum_Green / count);
            temp[r][c].rgbtRed = round(sum_Red / count);
        }
    }

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            image[r][c] = temp[r][c];
        }
    }

    return;
}
