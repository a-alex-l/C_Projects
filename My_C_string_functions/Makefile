all: lab_02

.PHONY: clean 

CFLAGS = -I include -Wall -Wextra -Werror -g

clean:
	rm -rf obj lab_02

lab_02: obj obj/str.o obj/test_str.o obj/test.o
	gcc obj/test.o obj/test_str.o obj/str.o -o lab_02

obj/str.o: obj src/str.c include/str.h
	gcc $(CFLAGS) -c src/str.c -o obj/str.o

obj/test_str.o: obj src/test_str.c include/test_str.h include/str.h
	gcc $(CFLAGS) -c src/test_str.c -o obj/test_str.o

obj/test.o: obj src/test.c include/str.h include/test_str.h
	gcc $(CFLAGS) -c src/test.c -o obj/test.o

obj:
	mkdir obj
