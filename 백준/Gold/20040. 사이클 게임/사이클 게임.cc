#include <iostream>
using namespace std;

int parent[500005];
int cnt;

int find(int tar)
{
	if (parent[tar] == tar)
		return tar;
	return parent[tar] = find(parent[tar]);
}

int setUnion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2)
		return cnt;

	parent[t2] = t1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cnt++;
		int cycle = setUnion(a, b);
		if (cycle > 0)
		{
			cout << cycle;
			return 0;
		}
	}

	cout << 0;

	return 0;
}