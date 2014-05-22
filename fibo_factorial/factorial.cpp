#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

long factorialIter(int N)
{
	if(N<0)
	{
		cout << "Invalid Input" << endl;
		return -1;
	}

	if(N == 0)
		return 1;
	long result = 1;
	for(int i=N; i >= 1; i--)
		result = result*i;
	return result;
}

long factorialRecursive(int N)
{
	if(N<0)
	{
		cout << "Invalid Input" << endl;
		return -1;
	}
	if(N==0)
		return 1;
	return (N*factorialRecursive(N-1));
}

// vector of factorials that have already been calculated
vector<long> facts = vector<long> ();
long factorialMemo(int N)
{
	if(facts.size() == 0)
		facts.push_back(1);
	if(N<0)
	{
		cout << "Invalid Input" << endl;
		return 1;
	}
	// check if it has already been calculated before would be in vector
	if(facts.size()-1 >= N)
		return facts[N];
	//else not in vector. first time calculating factorial(N)
	long prev = factorialMemo(N-1); // get factorial(N-1)
	long result = N*prev;
	facts.push_back(result);
	return result;
}

template <typename T>
void printVector(vector<T>& vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

int main()
{
	int input=0;
	while(input != -1)
	{
		cout << "Input: ";
		cin >> input;
		cout << "FactorialIter(" << input << ") = " << factorialIter(input) << endl;
		cout << "FactorialRecursive(" << input << ") = " << factorialRecursive(input) << endl;
		cout << "FactorialMemo(" << input << ") = " << factorialMemo(input) << endl;
		cout << "Fac_Memo_Vec: "; printVector(facts);
		cout << "-----------------------------------" << endl;
	}
	return 0;
}