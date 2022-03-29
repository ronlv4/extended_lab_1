#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void task1a(FILE* input, FILE* output){
    char c;
    while((c = fgetc(input))!= EOF){
        if(c != '\n'){
		if (c >= 'A' && c <= 'Z'){
			fprintf(output, "%c", '.');
		}
		else{
			fprintf(output, "%c", c);
		}
	}
	else{
		fprintf(output, "%c", c);
	}
    }
}
