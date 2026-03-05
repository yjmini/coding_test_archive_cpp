#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[7];
	for (int i = 0; i < 7; i++)
	{
		cin >> arr[i];
	}

	int sum = 0;
	int minVal = 1000;

	for (int i = 0; i < 7; i++)
	{
		if (arr[i] % 2 != 0)
		{
			sum += arr[i];
			minVal = min(minVal, arr[i]);
		}
	}

	if (minVal != 1000)
	{
		cout << sum << '\n' << minVal;
	}
	else
		cout << -1;

	return 0;
}