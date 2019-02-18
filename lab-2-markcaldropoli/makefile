CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
P = lab2
A = AntHill

all: $(P)

$(P): $(P).o $(A).o
	g++ $(P).o $(A).o -o $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(A).o: $(A).cpp $(A).h
	g++ $(CFLAGS) -c $(A).cpp -o $(A).o

run: all
	./$(P)

checkmem: all
	valgrind ./$(P)

clean:
	rm -f *o $(P)
