#include <stdlib.h>
#include <stdio.h>

void task1b(FILE* input, FILE* output){
    char c;
    int capitalCount = 0;
    while((c = fgetc(input))!= EOF){
        if(c != '\n'){
		fprintf(output, "%d ", c);
		if (c >= 'A' && c <= 'Z'){
			fprintf(output, "%d\n", '.');
			capitalCount++;
		}
		else{
			fprintf(output, "%d\n", c);
		}
	}
	else{
		fprintf(output, "the number of letters: %d\n", capitalCount);
		capitalCount = 0;
	}
    }
}
