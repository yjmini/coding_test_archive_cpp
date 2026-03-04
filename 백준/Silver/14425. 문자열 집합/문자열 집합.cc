#include <iostream>
#include <string>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
bool chk[MX];
int nxt[MX][26];

int c2i(char ch)
{
	return ch - 'A';
}

void insert(string& str)
{
	int now = ROOT;
	for (auto ch : str)
	{
		if (nxt[now][c2i(ch)] == -1)
			nxt[now][c2i(ch)] = unused++;
		now = nxt[now][c2i(ch)];
	}
	chk[now] = true;
}

bool find(string& str)
{
	int now = ROOT;
	for (auto ch : str)
	{
		if (nxt[now][c2i(ch)] == -1)
			return false;
		now = nxt[now][c2i(ch)];
	}
	//return true;
	return chk[now];
}

void erase(string& str)
{
	int now = ROOT;
	for (auto ch : str)
	{
		if (nxt[now][c2i(ch)] == -1)
			return;
		now = nxt[now][c2i(ch)];
	}
	chk[now] = false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < MX; i++)
	{
		fill(nxt[i], nxt[i] + 26, -1);
	}
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		insert(str);
	}

	int cnt = 0;

	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		if (find(str) == true)
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}