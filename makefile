all: isort txtfind

isort: isort.o
	gcc -Wall isort.o -o isort
isort.o: isort.c
	gcc -Wall -c isort.c -o isort.o

txtfind: txtfind.o
	gcc -Wall txtfind.o -o txtfind
txtfind.o: txtfind.c
	gcc -Wall -c txtfind.c -o txtfind.o
	

clean: 
	rm *.o isort txtfind

