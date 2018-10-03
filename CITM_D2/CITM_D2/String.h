#ifndef _STRING_H
#define _STING_H

#include <string.h>

class String {
private:
	char* st = nullptr;
	unsigned int alloc = 0u;

public:
	

	String() {
	}
	String(const char* string) {
		if (string != nullptr) {
			alloc = strlen(string) + 1;
			this->st = new char[alloc];
			strcpy_s(st,alloc, string);
		}
	}

	String(const String &otherString) {
		//st = otherString.st;
		if (otherString.st != nullptr) {
			alloc = otherString.alloc;
			this->st = new char[alloc];
			strcpy_s(st, alloc, otherString.st);
		}
	}

	String operator =(const char* string) {
		if (string != nullptr) {
			if ((strlen(string)+1) <= alloc) {
				strcpy_s(st, alloc, string);
			}
			else {
				alloc = strlen(string) + 1;
				delete[] st;
				this->st = new char[alloc];
				strcpy_s(st, alloc, string);
			}
		}
		return *this;
	}


	~String()
	{
		if (st != NULL) {
			delete[] st;
			st = nullptr;
		}
		
	};

};

#endif