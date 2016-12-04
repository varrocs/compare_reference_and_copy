
#include <string>
#include <vector>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <cassert>

#include "testfunction.h"

using namespace std;
using namespace std::chrono;

const int MAX_STRING_LENGTH = 512;

void logExecutionTime(
		string label,
		int duration,
		int stringLength,
		int iterationCount)
{
	cout << label << " execution time: \t" << duration << " ms"
		<< ", (iteration: \t" 	<< iterationCount
		<< ", string length: \t"  << stringLength << ")"
		<< endl;
}

string generateRandomString(int stringLength) {
	assert(stringLength < MAX_STRING_LENGTH);
	char result[MAX_STRING_LENGTH];
	for (int i = 0; i < stringLength; ++i) {
		result[i]='a' + (rand() % ('z' - 'a' ) );
	}
	result[stringLength] = '\0';
	return string(result);
}

vector<string> generateStrings(int stringLength, int iterationCount) {
	vector<string> result(iterationCount);
	for (int i = 0; i < iterationCount; ++i) {
		result[i] = generateRandomString(stringLength);
	}
	return result;

}

void test(int stringLength, int iterationCount) {
//	cout << "Generating test strings" << endl;
	vector<string> stringsToCopy = generateStrings(stringLength, iterationCount);

//	cout << "Running tests" << endl;

	// ------------------- Copy ----------------------
	const auto startCopy = system_clock::now();
	int checksumCopy = 0;
	for (int i = 0; i < iterationCount; ++i) {
		checksumCopy ^= checksumWithCopy(stringsToCopy[i]);
	}
	const auto endCopy   = system_clock::now();
	logExecutionTime("Copy", chrono::duration_cast<milliseconds>(endCopy - startCopy).count(), stringLength, iterationCount);

	// ------------------- Ref ----------------------
	const auto startRef  = system_clock::now();
	int checksumRef = 0;
	for (int i = 0; i < iterationCount; ++i) {
		checksumRef ^= checksumWithRef(stringsToCopy[i]);
	}
	const auto endRef    = system_clock::now();
	logExecutionTime("Ref", chrono::duration_cast<milliseconds>(endRef- startRef).count(), stringLength, iterationCount);

	assert(checksumCopy == checksumRef);
	cout << endl;
}


int main() {
	std::srand(1111);	// Seed

	test(10,  1000000);
	test(10,  5000000);
	test(10,  10000000);

	test(50,  1000000);
	test(50,  5000000);
	test(50,  10000000);

	test(100, 1000000);
	test(100, 5000000);
	test(100, 10000000);
}
