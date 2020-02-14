#include <iostream>
#include <algorithm>
#include <string>
#include <random>


using namespace std;
// Program to find lexicographically smaller permutations of a string


string generateRandomString(int size, int probability) {

	string output = "";
	for (int i = 0; i < size; i++) {
		// make random number 
		int temp = rand() % 100;

		if (temp < probability) {
			output += "1";
		}
		else
		{
			output += "0";
		}
	}

	return output;
}


bool isItMatches(string packet, string iterator) {

	bool flag = true;
	for (int i = 0; i < packet.size(); i++) {
		if (packet[i] == 1 && iterator[i] != 1) {
			flag = false;
			break;
		}
	}
	return flag;

}

float oldAlgorithm(int k, int r, vector<string> partialPacketGenerated) {

	float totalPermutation = 0;


	string iterator = "";
	for (int i = 0; i < k + r; i++) {

		if (i < r) {
			iterator += "1";
		}
		else
		{
			iterator += "0";
		}
	}

	string originalIterator;
	//	copy(iterator.begin(), iterator.end(), originalIterator);
	originalIterator = iterator;


	for (int i = 0; i < partialPacketGenerated.size(); i++) {


		while (true) {
			totalPermutation += 1;
			if (isItMatches(partialPacketGenerated[i], iterator)) {
				break;
			}
			prev_permutation(begin(iterator), end(iterator));
		}
	}

	return 1;

}

int main()
{

	// initial Configuration

	int symbols = 5;
	int redundancy = 2;
	int errorProbability = 50;




	vector<string> partialPacketGenerated;
	for (int i = 0; i < 10000; i++) {
		partialPacketGenerated.push_back(generateRandomString(symbols + redundancy, errorProbability));
	}

	oldAlgorithm(symbols, redundancy, partialPacketGenerated);


	return 0;
}

