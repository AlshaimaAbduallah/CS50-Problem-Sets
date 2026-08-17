#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // index
    int l = 0, s = 0, w = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            w++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s++;
        }
        else if (isalpha(text[i]))
        {
            l++;
        }
    }

    // Average letters and sentences per 100 words
    double L = (double) l / w * 100;
    double S = (double) s / w * 100;

    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
