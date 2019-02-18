CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
P = lab7
H = Hash

all: $(P)

$(P): $(P).o $(H).o
	g++ $(CFLAGS) $(P).o $(H).o -o $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(H).o: $(H).cpp $(H).h
	g++ $(CFLAGS) -c $(H).cpp -o $(H).o

run: all
	./$(P)

checkmem: all
	valgrind ./$(P)

clean:
	rm -f *o $(P)
