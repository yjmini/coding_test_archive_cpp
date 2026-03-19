#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Point
{
	int y;
	int x;
	int cnt;
	int dir;
	int time;
};

struct cmp
{
	bool operator() (Point a, Point b)
	{
		if (a.time != b.time) return a.time > b.time;
		if (a.y != b.y) return a.y > b.y;
		if (a.x != b.x) return a.x > b.x;
		return a.cnt < b.cnt;
	}
};

//상하좌우(1,2,3,4)
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };

int reverse_dir(int dir)
{
	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else if (dir == 4) return 3;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N, M, K;
		cin >> N >> M >> K;

		priority_queue<Point, vector<Point>, cmp> pq;
		
		int c, r, cnt, dir;
		for (int i = 0; i < K; i++)
		{
			cin >> c >> r >> cnt >> dir;
			pq.push({ c, r, cnt, dir, 0 }); // 초기군집은 time 0
		}

		int result = 0;

		while (!pq.empty())
		{
			Point now = pq.top();
			pq.pop();

			//큐의 다음 꺼가 나와 같은 시간, 같은 위치면 합치기
			while (!pq.empty() &&
				pq.top().time == now.time &&
				pq.top().y == now.y &&
				pq.top().x == now.x)
			{
				//흡수 후 큐에서 제거
				now.cnt += pq.top().cnt;
				pq.pop();
			}

			//목표시간에 도달한 경우 정답에 더하고 끝
			if (now.time == M)
			{
				result += now.cnt;
				continue;
			}

			//다음 시간으로 이동
			int ny = now.y + dy[now.dir];
			int nx = now.x + dx[now.dir];
			int ncnt = now.cnt;
			int ndir = now.dir;

			//약품구역 처리
			if (ny == 0 || ny == N - 1 || nx == 0 || nx == N - 1)
			{
				ncnt = ncnt / 2;
				ndir = reverse_dir(ndir);
			}

			if (ncnt > 0)
			{
				//살아남은 애들만 다음 시간으로 진행
				pq.push({ ny, nx, ncnt, ndir, now.time + 1 });
			}

		}
		cout << "#" << t << " " << result << '\n';

	}

	return 0;
}