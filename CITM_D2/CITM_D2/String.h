#ifndef _STRING_H
#define _STING_H

#include <string.h>

class string {
private:
	char* st;

public:
	

	string() {
	}

	string(const string &otherString) {
		st = otherString.st;
	}

	string(const char* text) {
		this->st = (char*)text;
	}

};

#endif