#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed  = average;
            image[i][j].rgbtGreen  = average;
            image[i][j].rgbtBlue  = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           int originalRed = image[i][j].rgbtRed;
           int originalGreen = image[i][j].rgbtGreen;
           int originalBlue =  image[i][j].rgbtBlue;

           int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
           int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
           int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

           if (sepiaRed > 255)
           {
            sepiaRed =255;
           }
           if (sepiaGreen > 255)
           {
            sepiaGreen =255;
           }
           if (sepiaBlue > 255)
           {
            sepiaBlue =255;
           }

            image[i][j].rgbtRed  = sepiaRed;
            image[i][j].rgbtGreen  = sepiaGreen;
            image[i][j].rgbtBlue  = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2 ; j++)
        {
            // Swap pixels
           RGBTRIPLE temp = image[i][j];
           image[i][j] = image[i][width - 1 - j];
           image[i][width - 1 - j] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // نسخ الصورة الأصلية بالكامل أولاً
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // حساب الضبابية
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            float counter = 0.0;

            for (int row = i - 1; row <= i + 1; row++)
            {
                for (int col = j - 1; col <= j + 1; col++)
                {
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        totalRed += copy[row][col].rgbtRed;
                        totalGreen += copy[row][col].rgbtGreen;
                        totalBlue += copy[row][col].rgbtBlue;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtRed = round(totalRed / counter);
            image[i][j].rgbtGreen = round(totalGreen / counter);
            image[i][j].rgbtBlue = round(totalBlue / counter);
        }
    }
    return;

}
