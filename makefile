CC = gcc
AR = ar
OBJECTS_ISORT_MAIN = isort.o
OBJECTS_TXTFIND_MAIN = txtfind.o
FLAGS = -Wall -g

all: isort txtfind	

isort: $(OBJECTS_ISORT_MAIN) 
	$(CC) $(FLAGS) -o isort $(OBJECTS_ISORT_MAIN)
	
txtfind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS)  -o txtfind $(OBJECTS_TXTFIND_MAINMAIN)
	
isort.o: 	isort.c
	$(CC) $(FLAGS)  -o isort.c
	
txtfind.o: txtfind.c	
	$(CC) $(FLAGS)  -o txtfind.c
.PHONY: clean all

clean:
	rm -f *.o *.a *.so isort txtfind
