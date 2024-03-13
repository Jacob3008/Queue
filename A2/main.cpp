#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

int prompt(Ring&);

int main() {
	Ring queue;

	// repeat prompt until user exits
	int choice;
	do {
		choice = prompt(queue);
	} while (choice != -1);

	return 0;
}

int prompt(Ring& queue) {
	// list choices
	cout << "1. enqueue" << endl;
	cout << "2. dequeue" << endl;
	cout << "3. head" << endl;
	cout << "4. tail" << endl;
	cout << "5. size" << endl;
	cout << "6. empty" << endl;
	cout << "7. display" << endl;
	cout << "8. exit" << endl << endl;

	// grabs choice from user input
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;

	// validate user input
	while (choice < 1 || choice > 8) {
		cout << "Please enter a value from 1-8: ";
		cin >> choice;
	}

	// enqueue
	if (choice == 1) {
		int dest;
		string tempPL;

		// get user input
		cout << "Enter destination 0-99: ";
		cin >> dest;
		cout << "Enter payload up to 5 characters: ";
		cin.ignore();
		getline(cin, tempPL);
		
		// convert to c_str and enqueue data
		const char* PL = tempPL.c_str();
		cout << endl << "Return code: " << queue.enqueue(dest, PL) << endl;
	}
	// dequeue
	else if (choice == 2) {
		cout << endl << "Return code: " << queue.dequeue() << endl;
	}
	// head
	else if (choice == 3) {
		cout << endl << "Head index: " << queue.head() << endl;
	}
	// tail
	else if (choice == 4) {
		cout << endl << "Tail index: " << queue.tail() << endl;
	}
	// size
	else if (choice == 5) {
		cout << endl << "Size of queue: " << queue.size() << endl;
	}
	// empty
	else if (choice == 6) {
		cout << endl << "Return code: " << queue.empty() << endl;
	}
	// display
	else if (choice == 7) {
		cout << endl;
		queue.display();
	}
	// exit
	else {
		return -1;
	}

	cout << endl;
	return 0;
}