#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class NumberSet
{
private:
public:
	vector<float> elements;
	vector<double> sums;
	
	NumberSet()
	{
		elements = vector<float>();
		sums = vector<double>(1,0); // initialized with a 0 value
	}
	
	~NumberSet(){}

	void addElem(float elem)
	{
		elements.push_back(elem); // add elem to vector of elements
		double newSum = sums[sums.size()-1] + elem; // calc new sum
		sums.push_back(newSum);
	}

	double lastNavg(int N)
	{
		if(N > elements.size())
		{
			cout << "N greater than number of elements available" << endl;
			return 0;
		}
		double mySum = sums[sums.size()-1];
		mySum = mySum - sums[sums.size()-1-N];
		return mySum/double(N);
	}

	void printElements()
	{
		cout << "Elements: ";
		for(int i=0; i < elements.size(); i++)
			cout << elements[i] << " ";
		cout << endl;
	}
};

int main()
{
	NumberSet set = NumberSet();
	set.addElem(1);
	set.addElem(2);
	set.addElem(3);
	set.addElem(5);
	set.addElem(7);
	set.addElem(8);
	set.addElem(10);
	set.addElem(11);
	set.addElem(17);
	set.printElements();

	cout << "Average of last 1: " << set.lastNavg(1) << endl;
	cout << "Average of last 2: " << set.lastNavg(2) << endl;
	cout << "Average of last 5: " << set.lastNavg(5) << endl;
	cout << "Average of last 8: " << set.lastNavg(8) << endl;
	cout << "Average of last 11: " << set.lastNavg(11) << endl; //error
	
	return 0;
}