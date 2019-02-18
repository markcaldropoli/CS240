CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
P = lab6
C = Card
D = Deck

all: $(P)

$(P): $(P).o $(C).o $(D).o
	g++ $(CFLAGS) $(P).o $(C).o $(D).o -o $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(C).o: $(C).cpp $(C).h
	g++ $(CFLAGS) -c $(C).cpp -o $(C).o

$(D).o: $(D).cpp $(D).h
	g++ $(CFLAGS) -c $(D).cpp -o $(D).o

run: all
	./$(P)

checkmem: all
	valgrind ./$(P)

clean:
	rm -f *o $(P)
