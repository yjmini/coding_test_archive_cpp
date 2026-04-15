#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	int k;
	for (int i = 0; i < N; i++)
	{
		cin >> k;
		if (k == 0)
		{
			if (pq.size() > 0)
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else
		{
			pq.push(k);
		}
	}

	return 0;
}