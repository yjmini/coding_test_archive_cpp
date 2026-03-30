#include <iostream>
using namespace std;

int main()
{
	int W, H;
	cin >> W >> H;

	float area = float(W) * float(H) / 2;

	cout.precision(1);
	cout << fixed;
	cout << area;

	return 0;
}