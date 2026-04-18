#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int performance = b / a;

	int answer = 3 * c * performance;

	cout << answer;

	return 0;
}