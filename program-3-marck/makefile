CFLAGS = -g -Wall -Wextra -DDEBUG -pedantic -std=c++14
P = program3
M = Map
C = City

all: $(P)

$(P): $(P).o $(M).o $(C).o
	g++ $(CFLAGS) $(P).o $(M).o $(C).o -o $(P)

$(P).o: $(P).cpp $(M).h $(C).h
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(M).o: $(M).cpp $(M).h $(C).h
	g++ $(CFLAGS) -c $(M).cpp -o $(M).o

$(C).o: $(C).cpp $(C).h
	g++ $(CFLAGS) -c $(C).cpp -o $(C).o

run: all
	./$(P)

checkmem: all
	valgrind ./$(P) --leak-check=full -v


clean:
	rm -f *o $(P)
