#include <iostream>
using namespace std;

int main()
{
	char str[101];
	cin >> str;
	
	int i = 0;
	int cnt[26] = { 0 };

	while (str[i] != '\0')
	{
		cnt[str[i] - 97]++;
		i++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << cnt[i] << " ";
	}

	return 0;
}