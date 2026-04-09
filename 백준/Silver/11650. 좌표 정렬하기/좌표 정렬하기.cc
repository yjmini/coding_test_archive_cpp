#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

int cmp(Point a, Point b)
{
	if (a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<Point> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].x << " " << arr[i].y << '\n';
	}

	return 0;
}