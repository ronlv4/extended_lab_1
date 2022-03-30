
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void task1a(FILE* input, FILE* output);
void task1b(FILE* input, FILE* output);
void task1c(FILE* input, FILE* output, int encryption);
int HexToInt(char h);

int main(int argc, char **argv) {
    FILE * output = stdout;
    FILE * input = stdin;
    bool debugMode = false;
    int encryptionAmount = 0;
    int i;
    int flag = 0;
    for(i = 1; i < argc; i++){
        if(strcmp(argv[i],"-o")==0)
            output = fopen(argv[++i],"w");
        else if(strcmp(argv[i],"-i")==0)
            input = fopen(argv[++i], "r");
        else if (strcmp(argv[i],"-D")==0){
            debugMode = true;
        }
        else if((strcmp(argv[i],"-c")==0)) {
            flag = 2;
        }
        else if(argv[i][1] == 'e')
        {
            encryptionAmount = HexToInt(argv[i][2]);
            if (encryptionAmount == -1)
            {
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
    if(debugMode){
        task1b(input, output);
    }
    else if(flag == 2){
        task1c(input, output, debugMode);
    }
    else{
        task1a(input, output);
    }
    fprintf(output, "%c", '\n');
    fclose(output);
    return 0;
}



