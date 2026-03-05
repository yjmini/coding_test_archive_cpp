#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int y=0, m=0;
	for (int i = 0; i < N; i++)
	{
		int weightY = 10;
		int weightM = 15;
		int tempY = arr[i] / 30;
		int tempM = arr[i] / 60;
		y = y + (tempY + 1) * weightY;
		m = m + (tempM + 1) * weightM;
	}

	if (y == m)
	{
		cout << "Y M " << y;
	}
	else if (y > m)
	{
		cout << "M " << m;
	}
	else
	{
		cout << "Y " << y;
	}

	return 0;
}