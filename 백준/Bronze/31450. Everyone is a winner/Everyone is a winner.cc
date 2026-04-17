#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	if (N % M == 0)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}