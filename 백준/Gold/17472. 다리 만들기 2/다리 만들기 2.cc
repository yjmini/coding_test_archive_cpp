#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge
{
	int st; //출발부품 번호
	int en; //도착부품 번호
	int cost; //다리 길이
};

bool cmp(Edge a, Edge b)
{
	return a.cost < b.cost; //비용이 작은게 앞으로
}

int N, M;
int map[11][11];
int visited[11][11];
int parent[7]; //부품개수 최대 6개
vector<Edge> bridges; //모든 가능한 다리 목록

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int find(int tar)
{
	if (tar == parent[tar])
		return tar;

	int ret = find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void setUnion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2)
		return;
	
	parent[t2] = t1;
}

// 라벨링(섬 번호붙이기 bfs)
void labeling(int y, int x, int id)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = 1;
	map[y][x] = id;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (map[ny][nx] == 1 && visited[ny][nx] == 0)
			{
				visited[ny][nx] = 1;
				map[ny][nx] = id;
				q.push({ ny, nx });
			}
		}
	}
}

//다리만들기 (직진해서 다른 섬 닿으면 저장)
void makeBridge(int y, int x, int startNode)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y;
		int nx = x;
		int dist = 0;

		while (true)
		{
			ny += dy[i];
			nx += dx[i];

			//맵 밖이거나 내 땅이면 그만둬
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				break;
			if (map[ny][nx] == startNode) 
				break;

			//바다(0)가 아닌 곳(다른 섬)에 도착
			if (map[ny][nx] != 0)
			{
				//길이가 2 이상이어야 함
				if (dist >= 2)
				{
					bridges.push_back({ startNode, map[ny][nx], dist });
				}
				break;
			}
			dist++; //바다 건너는중
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	//라벨링
	int partCnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				partCnt++;
				labeling(i, j, partCnt);
			}
		}
	}

	//다리 후보 찾기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] != 0) //땅이면 다리 쏴보기
			{
				makeBridge(i, j, map[i][j]);
			}
		}
	}

	//크루스칼 
	sort(bridges.begin(), bridges.end(), cmp);

	//parent 초기화
	for (int i = 1; i <= partCnt; i++)
	{
		parent[i] = i;
	}

	int totalCost = 0; //비용합계
	int usedBridges = 0; //다리개수

	for (int i = 0; i < bridges.size(); i++)
	{
		Edge cur = bridges[i];

		//연결 안되어있으면 연결(사이클 방지)
		if (find(cur.st) != find(cur.en))
		{
			setUnion(cur.st, cur.en);
			totalCost += cur.cost;
			usedBridges++;
		}
	}

	//모든 부품(partCnt)이 연결되려면 다리가 partCnt-1개 필요함
	if (usedBridges == partCnt - 1)
		cout << totalCost << '\n';
	else
		cout << -1 << '\n';

	return 0;
}