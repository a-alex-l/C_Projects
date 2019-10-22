all: lab_03

.PHONY: clean 

CFLAGS = -I include -Wall -Wextra -Werror -g

clean:
	rm -rf obj lab_03

lab_03: obj obj/main.o obj/clist.o
	gcc obj/main.o obj/clist.o -o lab_03

obj/main.o: obj src/main.c include/clist.h
	gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/clist.o: obj src/clist.c include/clist.h
	gcc $(CFLAGS) -c src/clist.c -o obj/clist.o

obj:
	mkdir obj
