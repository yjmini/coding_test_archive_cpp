#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str = "WelcomeToSMUPC";

	int n;
	cin >> n;
	if (n % 14 == 0)
		n = 14;
	else
		n = n % 14;

	cout << str[n - 1] << '\n';

	return 0;
}