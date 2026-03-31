#include <iostream>
using namespace std;

int main()
{
	char ch;
	cin >> ch;

	if (ch == 'M')
		cout << "MatKor";
	else if (ch == 'W')
		cout << "WiCys";
	else if (ch == 'C')
		cout << "CyKor";
	else if (ch == 'A')
		cout << "AlKor";
	else if (ch == '$')
		cout << "$clear";

	return 0;
}