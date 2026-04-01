#include <iostream>
using namespace std;

int tree[80'005];

void update(int node, int left, int right, int idx)
{
	tree[node]++;

	if (left == right)
	{
		return;
	}

	int mid = left + (right - left) / 2;

	if (left <= idx && idx <= mid)
		update(node * 2, left, mid, idx);
	else
		update(node * 2 + 1, mid + 1, right, idx);
}

int query(int node, int left, int right, int kth)
{
	int mid = left + (right - left) / 2;

	if (left == right)
	{
		return left;
	}

	if (kth > tree[node * 2])
	{
		return query(node * 2 + 1, mid + 1, right, kth - tree[node * 2]);
	}
	else
	{
		return query(node * 2, left, mid, kth);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		update(1, -10000, 10000, temp);
		cout << query(1, -10000, 10000, i / 2 + 1) << '\n';
	}

	return 0;
}

