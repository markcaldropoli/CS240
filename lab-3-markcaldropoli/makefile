CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
P = lab3
A = Ant
AH = AntHill

all: $(P)

$(P): $(P).o $(A).o $(AH).o
	g++ $(P).o $(A).o $(AH).o -o $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(A).o: $(A).cpp $(A).h
	g++ $(CFLAGS) -c $(A).cpp -o $(A).o

$(AH).o: $(A).cpp $(AH).h
	g++ $(CFLAGS) -c $(AH).cpp -o $(AH).o

run: all
	./$(P)

checkmem: all
	valgrind ./$(P)

clean:
	rm -f *o $(P)
