#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int minVal = 1e9;

	if (x - 0 < minVal)
		minVal = x;
	if (abs(x - w) < minVal)
		minVal = abs(x - w);
	if (y - 0 < minVal)
		minVal = y;
	if (abs(y - h) < minVal)
		minVal = abs(y - h);

	cout << minVal;

	return 0;
}