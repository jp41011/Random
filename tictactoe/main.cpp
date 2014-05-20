#include <iostream>
#include "TGame.h"
using std::cout;
using std::cin;

int main()
{
	TGame game1 = TGame();
	game1.startGame();

	cout << "Redo (r)  Exit (e): ";
	char ch;
	cin >> ch;
	if(ch == 'r')
		main();
	return 0;
}