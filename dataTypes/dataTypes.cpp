#include <iostream>
#include <typeinfo>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	// Testing typeid and looking at size of variables
	cout << "Bool: " << typeid(bool).name() << "\t\tsize: " << sizeof(bool) << endl;
	cout << "Char: " << typeid(char).name() << "\t\tsize: " << sizeof(char) << endl;
	cout << "String: " << typeid(string).name() << "\tsize: " << sizeof(string) << endl;
	cout << "Short: " << typeid(short).name() << "\tsize: " << sizeof(short) << endl;
	cout << "Int: " << typeid(int).name() << "\t\tsize: " << sizeof(int) << endl;
	cout << "Long: " << typeid(long).name() << "\t\tsize: " << sizeof(long) << endl;
	cout << "Float: " << typeid(float).name() << "\tsize: " << sizeof(float) << endl;
	cout << "Double: " << typeid(double).name() << "\tsize: " << sizeof(double) << endl;
	cout << "Pointers" << endl;
	cout << "Char*: " << typeid(char*).name() << "\t\tsize: " << sizeof(char*) << endl;
	cout << "String*: " << typeid(string*).name() << "\tsize: " << sizeof(string*) << endl;
	cout << "Int*: " << typeid(int*).name() << "\t\tsize: " << sizeof(int*) << endl;
	cout << "float*: " << typeid(float*).name() << "\tsize: " << sizeof(float*) << endl;
	// size of pointers = 4 bytes (on 32-bit machine)
	// 					  8 bytes (on 64-bit machine)
	return 0;
}
