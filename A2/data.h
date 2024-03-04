#pragma once
#include <stdio.h>
#include <string.h>

class Data {
public:
	void setDest(int);
	int getDest();
	void setPL(const char*);
	char* getPL();
	void clear();
private:
	int dest;
	char PL[6];
};

void Data::setDest(int val) {
	dest = val;
}

int Data::getDest() {
	return dest;
}

void Data::setPL(const char *val) {
	strcpy_s(PL, val);
}

char* Data::getPL() {
	return PL;
}

void Data::clear() {
	dest = NULL;
	memset(PL, 0, sizeof(PL));
}