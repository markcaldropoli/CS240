CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
P = lab4
LL = LinkedList
Q = Queue

all: $(P)

$(P): $(P).o $(LL).h $(Q).h
	g++ $(CFLAGS) $(P).o -o $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

run: all
	./$(P)

checkmem: all
	valgrind ./$(P)

clean:
	rm -f *o $(P)
