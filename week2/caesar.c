#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // validate the command line
    if (argc != 2 || strlen(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    while (key >= 26)
    {
        key -= 26;
    }

    // take input from the user
    string plain = get_string("plaintext: ");

    // print the text
    printf("ciphertext: ");

    int temp = 0;

    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                temp = plain[i] + key;
                if (temp > 90)
                {
                    printf("%c", temp - 26);
                }
                else
                {
                    printf("%c", temp);
                }
            }
            else
            {
                temp = plain[i] + key;
                if (temp > 122)
                {
                    printf("%c", temp - 26);
                }
                else
                {
                    printf("%c", temp);
                }
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
