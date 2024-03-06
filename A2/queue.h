#pragma once
#include "data.h"

using namespace std;

class Ring {
public:
	int enqueue(int,const char*);
	int dequeue();
	int head();
	int tail();
	int size();
	int empty();
	void display();
private:
	Device ring[6];
	Device temp;
	int ptrHead = 0;
	int ptrTail = 0;
};

// enqueues data from user input
int Ring::enqueue(int dest, const char* PL) {
	// checks to make sure destination is valid
	if (strlen(PL) > 5) {
		cout << endl << "Error: Please enter a payload under 6 characters" << endl;
		return -1;
	}
	// checks to make sure payload is valid
	if (dest < 0 || dest > 99) {
		cout << endl << "Error: Please enter a destination between 0 and 99" << endl;
		return -1;
	}

	// sets temp object to user input
	temp.setDest(dest);
	temp.setPL(PL);

	// set tail to temp object and clear temp
	ring[ptrTail] = temp;
	ptrTail++;
	temp.clear();

	return 0;
}

// dequeues data
int Ring::dequeue() {
	ptrHead++;
	return 0;
}

// returns head index
int Ring::head() {
	return ptrHead;
}

// returns tail index
int Ring::tail() {
	return ptrTail;
}

// return ring size
int Ring::size() {
	return ptrTail - ptrHead;
}

// sets both head and tail to 0
int Ring::empty() {
	ptrHead = 0;
	ptrTail = 0;

	return 0;
}

// displays ring contents
void Ring::display() {
	// loop through head and tail indexes
	for (int x = ptrHead; x < ptrTail; x++)
	{
		cout << "index " << x << ": Destination: " << ring[x].getDest() << ", Payload: " << ring[x].getPL() << endl;
	}

	// display current head and tail indexes
	cout << endl;
	cout << "head: " << ptrHead << endl;
	cout << "tail: " << ptrTail << endl;
}