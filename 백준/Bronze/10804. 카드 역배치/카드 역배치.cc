#include <iostream>
using namespace std;

int cards[21];

void swapArr(int a, int b)
{
	int temp;
	temp = cards[a];
	cards[a] = cards[b];
	cards[b] = temp;
}

int main()
{
	for (int i = 0; i < 21; i++)
	{
		cards[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		int a, b;
		cin >> a >> b;

		while (a < b)
		{
			swapArr(a, b);
			a++;
			b--;
		}
	}

	for (int i = 1; i < 21; i++)
	{
		cout << cards[i] << " ";
	}

	return 0;
}