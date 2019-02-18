CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
P = program2
C = Card
D = Deck
Py = Player
H = Heap
T = Table

all: $(P)

$(P): $(P).o $(C).o $(D).o $(Py).o $(H).o $(T).o
	g++ $(CFLAGS) $(P).o $(C).o $(D).o $(Py).o $(H).o $(T).o -o $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(C).o: $(C).cpp $(C).h
	g++ $(CFLAGS) -c $(C).cpp -o $(C).o

$(D).o: $(D).cpp $(D).h
	g++ $(CFLAGS) -c $(D).cpp -o $(D).o

$(Py).o: $(Py).cpp $(Py).h
	g++ $(CFLAGS) -c $(Py).cpp -o $(Py).o

$(H).o: $(H).cpp $(H).h
	g++ $(CFLAGS) -c $(H).cpp -o $(H).o

$(T).o: $(T).cpp $(T).h
	g++ $(CFLAGS) -c $(T).cpp -o $(T).o

run: all
	./$(P)

checkmem: all
	valgrind ./$(P)

clean:
	rm -f *o $(P)
