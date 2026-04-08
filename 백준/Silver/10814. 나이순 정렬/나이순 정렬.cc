#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct member
{
	int age;
	string name;
};

int cmp (member a, member b)
{
	return a.age < b.age;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<member> members(N);

	for (int i = 0; i < N; i++)
	{
		cin >> members[i].age >> members[i].name;
	}

	stable_sort(members.begin(), members.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cout << members[i].age << " " << members[i].name << '\n';
	}

	return 0;
}