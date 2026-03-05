#include <iostream>
using namespace std;

int main()
{
	int arr[3][4];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 0)
				cnt++;
		}
		if (cnt == 0) cnt = 5;
		cout << (char)(cnt + 'A' - 1) << '\n';
	}

	return 0;
}