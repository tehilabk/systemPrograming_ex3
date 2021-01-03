CC = gcc
FLAGS = -Wall -g

all: txtfind isort 

isort.o:isort.c myEx3.h
	$(CC) $(FLAGS) -c isort.c
txtfind.o:txtfind.c myEx3.h
	$(CC) $(FLAGS) -c txtfind.c
isort: isort.o 
	$(CC) $(FLAGS) isort.o -o isort
txtfind: txtfind.o 
	$(CC) $(FLAGS) txtfind.o -o txtfind	

.PHONY: all clean 
	
clean:
	rm  *.o txtfind isort
