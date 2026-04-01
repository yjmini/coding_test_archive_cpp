#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> dist(n, vector<int>(n, 21e8));

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (dist[a - 1][b - 1] > c)
			dist[a - 1][b - 1] = c;
	}

	for (int i = 0; i < n; i++)
	{
		dist[i][i] = 0;
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			if (dist[i][k] == 21e8)
				continue;

			for (int j = 0; j < n; j++)
			{
				if (dist[k][j] == 21e8)
					continue;

				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] == 21e8)
				dist[i][j] = 0;
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
