all: lab_04

.PHONY: clean 

CFLAGS = -I include -Wall -Wextra -Werror -g

clean:
	rm -rf obj lab_04

lab_04: obj obj/main.o obj/mergesort.o
	gcc obj/main.o obj/mergesort.o -o lab_04

obj/main.o: obj src/main.c include/mergesort.h
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/mergesort.o: obj src/mergesort.c include/mergesort.h
	gcc $(CFLAGS) -c src/mergesort.c -o obj/mergesort.o

obj:
	mkdir obj
