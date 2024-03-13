#pragma once
#include <string.h>

class Device {
public:
	Device();
	void setDest(int);
	int getDest();
	void setPL(const char*);
	char* getPL();
	void clear();
	bool isEmpty();
private:
	int dest;
	char PL[6];
};

Device::Device() {
	dest = NULL;
	memset(PL, 0, sizeof(PL));
}

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

// returns true if device is empty
bool Device::isEmpty() {
	if (dest == NULL && PL == memset(PL, 0, sizeof(PL))) {
		return true;
	}
	else {
		return false;
	}
}