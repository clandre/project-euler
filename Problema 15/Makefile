all: problema15

problema15: problema15.o
	gcc problema15.o `pkg-config --libs gsl` -o problema15 

problema15.o: problema15.c
	gcc -c problema15.c `pkg-config --cflags gsl`

clean:
	rm *o problema15