#include "Queue.h"
#include "LinkedList.h"
#include "Queue.h"
#include <iostream>
#include <cassert>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	srand(time(NULL));
	cerr << "\n\tTEST #1: Test create a integer List" << endl;
	LinkedList<int> list;
	list.insert(5);
	assert(list.read() == 5);
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #2: Test create a double List" << endl;
	LinkedList<double> double_list;
	double_list.insert(1.15);
	double_list.insert(2.15);
	double_list.insert(3.15);
	double var1 = double_list.read();
	assert(var1 == 1.15);
    double var2 = double_list.read();
	assert(var2 == 2.15);
    double var3 = double_list.read();
	assert(var3 == 3.15);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #3: Test delete elements from Linked List" << endl;
    assert(!double_list.empty());
	double_list.remove(var1);
	double_list.remove(var2);
	double_list.remove(var3);
	assert(double_list.empty());

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #4: Test add 1 element to a Queue" << endl;

	Queue<int> queue;
	queue.enqueue(5);
	assert(5 == queue.dequeue());

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #5: Test create a Queue" << endl;

	Queue<char> char_queue;
	char_queue.enqueue('a');
	char_queue.enqueue('b');
	char_queue.enqueue('c');
	char let1 = char_queue.dequeue();
	assert(let1 == 'a');
	assert(char_queue.empty() == false);
    char let2 = char_queue.dequeue();
	assert(let2 == 'b');
	assert(char_queue.empty() == false);
    char let3 = char_queue.dequeue();
	assert(let3 == 'c');
	assert(char_queue.empty());

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #6: Test Queue Order" << endl;

	char_queue.enqueue('z');
	char_queue.enqueue('y');
	char letz = char_queue.dequeue();
	assert(letz == 'z');
	char_queue.enqueue('x');
	char lety = char_queue.dequeue();
	assert(lety == 'y');
	char_queue.enqueue('w');
	char letx = char_queue.dequeue();
	assert(letx == 'x');
	char letw = char_queue.dequeue();
	assert(letw == 'w');
    cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #7: Test Queue Interface" << endl;

	assert(char_queue.empty());
	char_queue.enqueue('a');
	assert(!char_queue.empty());
	char_queue.enqueue('b');
	char_queue.enqueue('c');
	char leta = char_queue.peek();
	assert(leta == 'a');
	char leta2 = char_queue.dequeue();
	assert(leta2 == 'a');
	char_queue.clear();
	assert(char_queue.empty());
	cerr << "\n\t========================PASS========================\n" << endl;
    cerr << "\n\tDon't forget to run with Valgrind and commit to Github!\n" << endl;
    return 0;
}
