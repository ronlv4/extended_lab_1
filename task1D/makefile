# All Targets
all: encoder

libs: c-lib

encoder: encoder.o
	gcc -m32 -g -Wall -o encoder encoder.c

encoder.o: encoder.c
	gcc -g -Wall -m32 -ansi -c -o encoder.o encoder.c

#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean:
	rm -f *.o encoder
