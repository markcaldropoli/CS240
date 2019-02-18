CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
P = program1
A = Ant
AH = AntHill
LL = LinkedList

all: $(P)

$(P): $(P).o $(AH).o $(A).o $(LL).o
	g++ $(CFLAGS) $(P).o $(AH).o $(A).o $(LL).o -o $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(A).o: $(A).cpp $(A).h
	g++ $(CFLAGS) -c $(A).cpp -o $(A).o

$(AH).o: $(AH).cpp $(AH).h
	g++ $(CFLAGS) -c $(AH).cpp -o $(AH).o

$(LL).o: $(LL).cpp $(LL).h
	g++ $(CFLAGS) -c $(LL).cpp -o $(LL).o

run: all
	./$(P)

checkmem: all
	valgrind ./$(P)

clean:
	rm -f *o $(P) anthill.log
