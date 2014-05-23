#include <iostream>
#include <string>
#include <ctype.h>

using std::cin;
using std::getline;
using std::cout;
using std::endl;
using std::string;

// initialize array to 0's
void initArray(int* array, int size)
{
	for(unsigned int i=0; i<size; i++)
		array[i] = 0;
	return;
}

// using counting sort method O(N)
char mostFreqChar(string& input)
{
	unsigned int length = input.size();
	int charCount [26]; // index corresponds to char 'a' = 0 ...
	initArray(charCount, 26);
	unsigned maxCount = 0;
	unsigned maxIndex = 0;
	unsigned tempIndex;
	for(unsigned int i=0; i < length; i++)
	{
		if(isalpha(input[i]) == false) // if not a letter
			continue; // skip to next char
		//else char is a letter
		if(islower(input[i]) == true) // letter is lower case alpha
			tempIndex = int(input[i] - 'a'); // calc index for char
		else // letter is upper case
			tempIndex = int(tolower(input[i]) - 'a'); // convert to lower & get index
		
		charCount[tempIndex]++; // increase count
		if(charCount[tempIndex] > maxCount)
		{
			maxCount = charCount[tempIndex];
			maxIndex = tempIndex;
		}
	}

	return char('a'+maxIndex);
}

int main()
{
	string input = ""; // will store user input string
	while(input != "-1") // -1 to exit
	{
		cout << "Input: ";
		//cin >> input; // space is the delimiter
		getline(cin, input); // to get entire line including spaces
		cout << "Most frequent: " << mostFreqChar(input) << endl;
		cout << "--------------------" << endl;
	}

	return 0;
}