#pragma once
#include <string.h>

class Device {
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

// dest setter
void Device::setDest(int val) {
	dest = val;
}

// dest getter
int Device::getDest() {
	return dest;
}

// PL setter
void Device::setPL(const char *val) {
	strcpy_s(PL, val);
}

// PL getter
char* Device::getPL() {
	return PL;
}

// sets all variables to null
void Device::clear() {
	dest = NULL;
	memset(PL, 0, sizeof(PL));
}