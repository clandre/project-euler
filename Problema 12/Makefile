all: q12

q12: q12.o Matematica.o 
	gcc q12.o Matematica.o -o q12

q12.o: q12.c
	gcc -c q12.c
Matematica.o: Matematica.c
	gcc -c Matematica.c
clean: 
	rm -rf *o q12
