#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N);
	
	//-4000~4000 까지의 DAT(0부터 8001까지)
	vector<int> cnt(8001, 0);

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		cnt[arr[i] + 4000]++;
	}

	int avg = round(((double)sum / N));

	sort(arr.begin(), arr.end());
	int maxCnt = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] > maxCnt)
		{
			maxCnt = cnt[i];
		}
	}

	vector<int> maxArr;
	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] == maxCnt)
		{
			maxArr.push_back(i - 4000);
		}
	}
	
	int ret = 0;
	if (maxArr.size() == 1)
		ret = maxArr[0];
	else
		ret = maxArr[1];

	cout << avg << '\n';
	cout << arr[N / 2] << '\n';
	cout << ret << '\n';
	cout << arr[N - 1] - arr[0] << '\n';

	return 0;
}