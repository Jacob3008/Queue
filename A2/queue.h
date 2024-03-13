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
		cout << endl << "Error: Please enter a payload under 6 characters";
		return -1;
	}
	// checks to make sure payload is valid
	if (dest < 0 || dest > 99) {
		cout << endl << "Error: Please enter a destination between 0 and 99";
		return -1;
	}

	// checks for overflow
	if (!ring[ptrTail].isEmpty()) {
		cout << endl << "Error: Overflow";
		return -1;
	}

	// sets temp object to user input
	temp.setDest(dest);
	temp.setPL(PL);

	// set tail to temp object and clear temp
	ring[ptrTail] = temp;
	temp.clear();

	// check for wraparound
	if (ptrTail == (sizeof(ring) / sizeof(Device)) - 1) {
		ptrTail = 0;
	}
	else {
		ptrTail++;
	}

	return 0;
}

// dequeues data
int Ring::dequeue() {
	// check for underflow
	if (ring[ptrHead].isEmpty()) {
		cout << endl << "Error: Underflow";
		return -1;
	}

	ring[ptrHead].clear();

	// check for wraparound
	if (ptrHead == (sizeof(ring) / sizeof(Device)) - 1) {
		ptrHead = 0;
	}
	else {
		ptrHead++;
	}

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
	// check for wraparound
	if (ptrTail < ptrHead) {
		return sizeof(ring) / sizeof(Device) + ptrTail - ptrHead;
	}

	else if (ptrTail == ptrHead) {
		// check for empty ring
		if (ring[ptrHead].isEmpty()) {
			return 0;
		}
		// check for full ring
		else {
			return sizeof(ring) / sizeof(Device);
		}
	}
	else {
		return ptrTail - ptrHead;
	}
}

// sets both head and tail to 0
int Ring::empty() {
	// clear ring elements
	for (int x = 0; x < sizeof(ring) / sizeof(Device); x++) {
		ring[x].clear();
	}

	// reset head and tail
	ptrHead = 0;
	ptrTail = 0;

	return 0;
}

// displays ring contents
void Ring::display() {
	const int RING_SIZE = sizeof(ring) / sizeof(Device);

	if (ptrHead == ptrTail) {
		// check for empty ring
		if (ring[ptrHead].isEmpty()) {
			cout << "Ring is empty" << endl;
		}
		// list all elements
		else {
			for (int x = ptrHead; x < RING_SIZE + ptrHead; x++) {
				// check for wraparound
				if (x >= RING_SIZE) {
					cout << "index " << x - RING_SIZE << ": Destination: " << ring[x - RING_SIZE].getDest() << ", Payload: " << ring[x - RING_SIZE].getPL() << endl;
				}
				else {
					cout << "index " << x << ": Destination: " << ring[x].getDest() << ", Payload: " << ring[x].getPL() << endl;
				}
			}
		}
	}

	// check for wraparound
	if (ptrTail < ptrHead) {
		for (int x = ptrHead; x < RING_SIZE + ptrTail; x++) {
			if (x >= RING_SIZE) {
				cout << "index " << x - RING_SIZE << ": Destination: " << ring[x - RING_SIZE].getDest() << ", Payload: " << ring[x - RING_SIZE].getPL() << endl;
			}
			else {
				cout << "index " << x << ": Destination: " << ring[x].getDest() << ", Payload: " << ring[x].getPL() << endl;
			}
		}
	}

	// no wraparound
	else {
		for (int x = ptrHead; x < ptrTail; x++)
		{
			if (x >= RING_SIZE) {
				cout << "index " << x - RING_SIZE << ": Destination: " << ring[x - RING_SIZE].getDest() << ", Payload: " << ring[x - RING_SIZE].getPL() << endl;
			}
			else {
				cout << "index " << x << ": Destination: " << ring[x].getDest() << ", Payload: " << ring[x].getPL() << endl;
			}
		}
	}

	// display current head and tail indexes
	cout << endl;
	cout << "head: " << ptrHead << endl;
	cout << "tail: " << ptrTail << endl;
}