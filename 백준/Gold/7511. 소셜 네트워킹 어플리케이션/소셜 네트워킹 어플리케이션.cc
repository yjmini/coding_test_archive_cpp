#include <iostream>
using namespace std;

int parent[1000005];

int find(int tar)
{
	if (parent[tar] == tar)
		return tar;

	return parent[tar] = find(parent[tar]);
}

void setUnion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2)
		return;

	parent[t2] = t1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cout << "Scenario " << i << ":" << '\n';

		int n, k, m;
		cin >> n >> k;

		for (int j = 0; j < n; j++)
		{
			parent[j] = j;
		}

		int a, b;
		for (int j = 0; j < k; j++)
		{
			cin >> a >> b;
			setUnion(a, b);
		}
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;
			if (find(a) == find(b))
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		cout << '\n';
	}

	return 0;
}