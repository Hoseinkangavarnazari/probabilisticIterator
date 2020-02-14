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
		if (packet[i] == '1' && iterator[i] != '1') {
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
		iterator = originalIterator;
		cout << endl << "Packet: " << i << endl;
		do 
		{
			totalPermutation += 1;
			if (isItMatches(partialPacketGenerated[i], iterator)) {
				break;
			}
			
		} while (prev_permutation(begin(iterator), end(iterator)));
	}


	float avgIteration = totalPermutation / partialPacketGenerated.size();
	return avgIteration;
}

int main()
{

	// initial Configuration

	int symbols = 26;
	int redundancy = 5;
	int errorProbability = 12;
	int testBound = 10000;




	vector<string> partialPacketGenerated;
	for (int i = 0; i < testBound; i++) {
		partialPacketGenerated.push_back(generateRandomString(symbols + redundancy, errorProbability));
	}

	cout << "The old Algorithm iteration: " << oldAlgorithm(symbols, redundancy, partialPacketGenerated);


	return 0;
}

