#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int arr[5];
	int cnt = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 5; i++)
	{
		if (arr[i] == T)
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}