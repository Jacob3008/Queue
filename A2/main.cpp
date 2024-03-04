#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

int prompt(Ring&);

int main() {
	Ring queue;
	while(true)
		prompt(queue);
	return 0;
}

int prompt(Ring& queue) {
	cout << "1. enqueue" << endl;
	cout << "2. dequeue" << endl;
	cout << "3. display" << endl;
	cout << "4. exit" << endl << endl;

	int choice;
	cout << "Enter your choice: ";
	cin >> choice;

	if (choice == 1) {
		int dest;
		string tempPL;
		cout << "Enter destination 0-99: ";
		cin >> dest;
		cout << "Enter payload up to 5 characters: ";
		cin.ignore();
		getline(cin, tempPL);
		
		const char* PL = tempPL.c_str();
		queue.enqueue(dest, PL);
		cout << endl;
	}
	else if (choice == 2) {
		queue.dequeue();
	}
	else if (choice == 3) {
		queue.display();
	}
	return 0;
}