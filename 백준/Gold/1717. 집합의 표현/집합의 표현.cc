#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int cmp;
	int setA;
	int setB;
};

int parent[1000001];

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
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	vector<Node> arr(m);

	for (int i = 0; i < m; i++)
	{
		cin >> arr[i].cmp >> arr[i].setA >> arr[i].setB;
	}

	for (int i = 0; i < m; i++)
	{
		if (arr[i].cmp == 0)
		{
			setUnion(arr[i].setA, arr[i].setB);
		}
		else if (arr[i].cmp == 1)
		{
			if (find(arr[i].setA) == find(arr[i].setB))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}