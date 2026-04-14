#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ISBN;
	cin >> ISBN;

	int sum = 0;
	int starIndex = -1;

	for (int i = 0; i < ISBN.length(); i++)
	{
		if (ISBN[i] == '*')
		{
			starIndex = i;
		}
		else if (ISBN[i] >= '0' && ISBN[i] <= '9')
		{
			if (i % 2 == 0)
			{
				sum += (ISBN[i] - '0') * 1;
			}
			else
			{
				sum += (ISBN[i] - '0') * 3;
			}
		}
	}

	int weight = starIndex % 2 == 0 ? 1 : 3;

	for (int i = 0; i < 10; i++)
	{
		if ((sum + weight * i) % 10 == 0)
		{
			cout << i;
		}
	}

	return 0;
}