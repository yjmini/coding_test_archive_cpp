#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> asc;
priority_queue<int, vector<int>> desc;

void addNumber(int num)
{
	desc.push(num);
	asc.push(desc.top());
	desc.pop();

	if (desc.size() < asc.size())
	{
		desc.push(asc.top());
		asc.pop();
	}
}

int getMedian()
{
	return desc.top();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;
	
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		addNumber(temp);
		cout << getMedian() << '\n';
	}


	return 0;
}