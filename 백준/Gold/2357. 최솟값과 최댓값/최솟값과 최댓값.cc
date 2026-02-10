#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define ll long long 

ll arr[100001];

pair<ll, ll> tree[400001]; //min max

void myTree(ll node, ll left, ll right)
{
	if (left == right)
	{
		tree[node].first = arr[left];
		tree[node].second = arr[left];
		return;
	}

	ll mid = left + (right - left) / 2;
	myTree(node * 2, left, mid);
	myTree(node * 2 + 1, mid + 1, right);
	tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
	tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
}

pair<ll, ll> findMinMax(ll node, ll left, ll right, ll st, ll en)
{
	if (st > right || en < left)
		return { -1,-1 };
	if (left >= st && en >= right)
		return tree[node];

	ll mid = left + (right - left) / 2;
	pair<ll, ll> l = findMinMax(node * 2, left, mid, st, en);
	pair<ll, ll> r = findMinMax(node * 2 + 1, mid+1, right, st, en);

	if (l.first == -1)
	{
		return r;
	}
	if (r.first == -1)
	{
		return l;
	}
	return { min(l.first, r.first), max(l.second, r.second) };
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, M;
	cin >> N >> M;

	for (ll i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	myTree(1, 0, N-1);

	for (ll i = 0; i < M; i++)
	{
		ll a, b;
		cin >> a >> b;
		
		pair <ll, ll> result = findMinMax(1, 0, N - 1, a - 1, b - 1);
		cout << result.first << " " << result.second << '\n';
	}

	return 0;
}