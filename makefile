gradebook: main.o Functions.o
	gcc -o gradebook main.o Functions.o 
main.o: main.c functions.h Structures.h
	gcc -c main.c
Functions.o: Functions.c functions.h Structures.h
	gcc -c Functions.c
clean:
	rm main.o Functions.o
