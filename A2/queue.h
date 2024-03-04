#pragma once
#include "data.h"

using namespace std;

class Ring {
public:
	int enqueue(int,const char*);
	int dequeue();
	void display();
private:
	Data ring[6];
	Data temp;
	int head = 0;
	int tail = 0;
};

int Ring::enqueue(int dest, const char* PL) {
	if (strlen(PL) > 5) {
		cout << "Error: Please enter a payload under 6 characters" << endl;
		return -1;
	}
	if (dest < 0 || dest > 99) {
		cout << "Error: Please enter a destination between 0 and 99" << endl;
		return -1;
	}

	temp.setDest(dest);
	temp.setPL(PL);
	ring[tail] = temp;
	tail++;
	temp.clear();

	return 0;
}

int Ring::dequeue() {
	head++;
	return 0;
}

void Ring::display() {
	for (int x = head; x < tail; x++)
	{
		cout << "index " << x << ": Destination: " << ring[x].getDest() << ", Payload: " << ring[x].getPL() << endl;
	}

	cout << endl;
	cout << "head: " << head << endl;
	cout << "tail: " << tail << endl;
}