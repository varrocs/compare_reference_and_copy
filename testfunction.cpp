#include "testfunction.h"

using namespace std;

int checksumWithCopy(string str) {
	int result = 0;
	for (int i = 0; i<str.length(); ++i) {
		result ^= str.at(i);
	}
	return result;
}

int checksumWithRef(const string& str) {
	int result = 0;
	for (int i = 0; i<str.length(); ++i) {
		result ^= str.at(i);
	}
	return result;
}
