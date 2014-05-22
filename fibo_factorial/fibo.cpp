#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

// calculate fibonacci iteratively
// fibo(0) = 0, fibo(1) = 1, fibo(N) = fibo(N-1)+fibo(N-2)
int fiboIter(int N)
{
	if(N < 0)
	{
		cout << "Invalid input" << endl;
		return -1;
	}
	if(N == 0)
		return 0;
	if(N == 1)
		return 1;

	int prev1 = 1;
	int prev2 = 0;
	int result = 0;
	for(int i=2; i<=N; i++)
	{
		result = prev1 + prev2;
		prev2 = prev1;
		prev1 = result;
	}

	return result;
}

// calculate fibonacci recursively
int fiboRec(int N)
{
	if(N < 0)
	{
		cout << "Invalid input" << endl;
		return -1;
	}
	if(N == 0)
		return 0;
	if(N == 1)
		return 1;
	return fiboRec(N-1) + fiboRec(N-2);
}

// calculate fibonacci recursively with memoization
vector<int> fibos = vector<int> ();
//fibos.push_back(0); why do these cause compile error
//fibos.push_back(1);
int fiboMemo(int N)
{
	if(N < 0)
	{
		cout << "Invalid input" << endl;
		return -1;
	}

	if(fibos.size() < 2)
	{
		fibos.push_back(0);
		fibos.push_back(1);
	}

	// check if we have already calculated the answer
	if(fibos.size()-1 >= N)
		return fibos[N];

	int prev2 = fiboMemo(N-2);
	int prev1 = fiboMemo(N-1);
	int result = prev1 + prev2;
	fibos.push_back(result);

	return result;
}

template <typename T>
void printVector(vector<T>& vec)
{
	for(unsigned int i=0; i < vec.size(); i++)
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
		cout << "fiboIter(" << input << ") = " << fiboIter(input) << endl;
		cout << "fiboRec(" << input << ") = " << fiboRec(input) << endl;
		cout << "fiboMemo(" << input << ") = " << fiboMemo(input) << endl;
		cout << "fibos: "; printVector(fibos);
	}
	
	return 0;
}