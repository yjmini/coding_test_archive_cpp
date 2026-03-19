#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//우선순위 큐에 넣을 세포 정보
struct Cell
{
	int time; //번식할 시간
	int life; //생명력
	int y; //좌표
	int x;
};

struct cmp
{
	bool operator() (Cell a, Cell b)
	{
		if (a.time == b.time) return a.life < b.life;
		return a.time > b.time;
		//기본적으로는 시간에대해 오름차순,
		//시간이 같다면 생명력에 대해 내림차순
	}
};

int visited[400][400];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

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

		//visited 배열 초기화
		for (int i = 0; i < 400; i++)
		{
			for (int j = 0; j < 400; j++)
			{
				visited[i][j] = 0;
			}
		}

		priority_queue<Cell, vector<Cell>, cmp> pq;
		vector<pair<int, int>> all_cells; //{생성된 시간, 생명력} 기록용

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int life;
				cin >> life;
				
				if (life > 0)
				{
					//번식하니까 일부러 중앙쯤에 배치
					visited[i + 150][j + 150] = 1;
					//처음 주어진 세포는 0시간에 생성됨
					all_cells.push_back({ 0, life });
					//번식 시간 = 생성시간(0) + 생명력 + 1
					pq.push({ life + 1, life, i + 150, j + 150 });
				}
			}
		}

		//시뮬레이션 시작
		while (!pq.empty())
		{
			Cell now = pq.top();
			pq.pop();

			//K시간 이후의 번식은 시뮬레이션할 필요 없음
			if (now.time > K) break;

			for (int i = 0; i < 4; i++)
			{
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];

				//빈공간이면 번식 성공
				if (visited[ny][nx] == 0)
				{
					visited[ny][nx] = 1;
					//새로운 세포가 현재 시간(now.time)에 생성됨
					all_cells.push_back({ now.time, now.life });
					//새 세포의 다음 번식시간 = 현재시간+생명력+1
					pq.push({ now.time + now.life + 1, now.life, ny, nx });
				}
			}
		}

		//살아있는 세포 개수 세기
		int alive_cnt = 0;
		for (auto c : all_cells)
		{
			int create_time = c.first;
			int life = c.second;
			int dead_time = create_time + (life * 2);

			//K시간일때 아직 죽지 않았다면
			if (K < dead_time)
			{
				alive_cnt++;
			}
		}

		cout << "#" << t << " " << alive_cnt << '\n';
	}

	return 0;
}