CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
P = lab5
BST = BSTree

all: $(P)

$(P): $(P).o $(BST).o
	g++ $(CFLAGS) $(P).o $(BST).o -o $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(BST).o: $(BST).cpp $(BST).h
	g++ $(CFLAGS) -c $(BST).cpp -o $(BST).o

run: all
	./$(P)

checkmem: all
	valgrind ./$(P)

clean:
	rm -f *o $(P)
