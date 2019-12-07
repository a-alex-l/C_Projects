CXXFLAGS = -c -O2 -Wall -Werror -std=c++11 -I include

EXE = hw_02
TEST = test_02
INCLUDE = include/Board.hpp include/Test.hpp include/StdioBoardView.hpp include/BoardTest.hpp

all: obj $(EXE)

test: obj $(TEST)

$(EXE): obj/main.o obj/Board.o obj/StdioBoardView.o
	g++ $^ -o $@


$(TEST): obj/test.o obj/BoardTest.o obj/Test.o obj/Board.o
	g++ $^ -o $@

obj/main.o: obj src/main.cpp $(INCLUDE)
	g++ $(CXXFLAGS) src/main.cpp -o $@

obj/test.o: obj test/test.cpp $(INCLUDE)
	g++ $(CXXFLAGS) test/test.cpp -o $@

obj/Test.o: obj test/Test.cpp $(INCLUDE)
	g++ $(CXXFLAGS) test/Test.cpp -o $@

obj/BoardTest.o: obj test/BoardTest.cpp $(INCLUDE)
	g++ $(CXXFLAGS) test/BoardTest.cpp -o $@

obj/Board.o: obj src/Board.cpp $(INCLUDE)
	g++ $(CXXFLAGS) src/Board.cpp -o $@

obj/StdioBoardView.o: obj src/StdioBoardView.cpp $(INCLUDE)
	g++ $(CXXFLAGS) src/StdioBoardView.cpp -o $@


clean:
	rm -rf obj $(EXE)

obj:
	mkdir obj

.PHONY: clean all test
