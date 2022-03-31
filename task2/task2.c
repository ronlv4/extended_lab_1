
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void task1a(FILE *input, FILE *output);
void task1b(FILE *input, FILE *output);
void task1c(FILE *input, FILE *output, int encryption);
int HexToInt(char h);

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
    if (encryptionAmount != 0)
    {
        task1c(input, output, encryptionAmount);
    }
    else if (debugMode)
    {
        task1b(input, output);
    }
    else
    {
        task1a(input, output);
    }
    fprintf(output, "%c", '\n');
    fclose(output);
    return 0;
}
