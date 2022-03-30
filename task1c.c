#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void task1c(FILE* input, FILE* output, int encryption){
    char c;
    char firstLetter;
    int lettersCount = encryption;
    bool firstIteration = true;
    while((c = fgetc(input))!= EOF){
        if (firstIteration)
        {
            firstLetter = c;
            firstIteration = false;
        }
        if(c != '\n'){
            if (lettersCount < 0)
            {
                lettersCount++;
                continue;
            }
            fprintf(output, "%c", c);
        }
        else{
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
