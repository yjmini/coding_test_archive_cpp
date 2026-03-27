#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int X;
	cin >> X;
	int cnt = 0;
	int left = 0;
	int right = N - 1;

	while (left < right)
	{
		if (arr[left] + arr[right] == X)
		{
			cnt++;
			left++;
			right--;
		}
		else if (arr[left] + arr[right] > X)
		{
			right--;
		}
		else
		{
			left++;
		}
	}

	cout << cnt;

	return 0;
}