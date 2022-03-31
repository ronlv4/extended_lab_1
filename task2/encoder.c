
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int HexToInt(char h);
void encoder(FILE *input, FILE *output, int encryptionAmount);
void debugger(FILE *input, FILE *output);

int main(int argc, char **argv)
{
    FILE *output = stdout;
    FILE *input = stdin;
    bool debugMode = false;
    int encryptionAmount = 0;
    int i;
    for (i = 1; i < argc; i++)
    {
        if (argv[i][1] == 'o')
            output = fopen(argv[i] + 2, "w");
        if (argv[i][1] == 'i')
            input = fopen(argv[i] + 2, "r");
        else if (strcmp(argv[i], "-D") == 0)
            debugMode = true;
        else if (argv[i][1] == 'e')
        {
            encryptionAmount = HexToInt(argv[i][2]);
            if (encryptionAmount == -1)
            {
                fprintf(output, "error: invalid hexadecimal value");
                exit(1);
            }
            if (argv[i][0] == '-')
            {
                encryptionAmount *= -1;
            }
        }
    }
    if (debugMode)
    {
        debugger(input, output);
    }
    else
    {
        encoder(input, output, encryptionAmount);
    }
    fprintf(output, "%c", '\n');
    fclose(output);
    return 0;
}

void ReadFromInputASCII(FILE *input, FILE *output)
{
    int currentLetterASCII = 0;
    char c;
    while ((c = fgetc(input)) != EOF)
    {
        if (c != '\n')
        {
            if (c != ' ')
            {
                currentLetterASCII += c;
            }
            else
            {
                fprintf(output, "%c", currentLetterASCII);
            }
        }
        else
        {
            fprintf(output, "%c", c);
        }
    }
}

void encoder(FILE *input, FILE *output, int encryption)
{
    char c;
    char firstLetter;
    int lettersCount = encryption;
    bool firstIteration = true;
    while ((c = fgetc(input)) != EOF)
    {
        if (firstIteration)
        {
            firstLetter = c;
            firstIteration = false;
        }
        if (c != '\n')
        {
            if (lettersCount < 0)
            {
                lettersCount++;
                continue;
            }
            fprintf(output, "%c", c);
        }
        else
        {
            int i;
            for (i = 0; i < lettersCount; i++)
            {
                fprintf(output, "%c", firstLetter);
            }
            lettersCount = encryption;
            firstIteration = true;
            fprintf(output, "%c", c);
        }
    }
}

void debugger(FILE *input, FILE *output)
{
    char c;
    int capitalCount = 0;
    while ((c = fgetc(input)) != EOF)
    {
        if (c != '\n')
        {
            fprintf(output, "%d ", c);
            if (c >= 'A' && c <= 'Z')
            {
                fprintf(output, "%d\n", '.');
                capitalCount++;
            }
            else
            {
                fprintf(output, "%d\n", c);
            }
        }
        else
        {
            fprintf(output, "the number of letters: %d\n", capitalCount);
            capitalCount = 0;
        }
    }
}

int HexToInt(char h)
{
    if ((h >= '0') && (h <= '9'))
    {
        return h - '0';
    }
    if ((h >= 'a') && (h <= 'f'))
    {
        return h - 'a' + 10;
    }
    if ((h >= 'A') && (h <= 'F'))
    {
        return ((h - 'A') + 10);
    }
    return -1;
}