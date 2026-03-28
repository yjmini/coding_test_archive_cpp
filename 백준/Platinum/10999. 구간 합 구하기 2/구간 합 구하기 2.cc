#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long 

ll arr[1'000'001];
ll tree[4'000'001];
ll lazy[4'000'001];

//트리 초기화
void init(ll node, ll left, ll right)
{
	//마지막 말단 노드일 때
	if (left == right)
	{
		tree[node] = arr[left];
		return;
	}

	ll mid = left + (right - left) / 2;
	init(node * 2, left, mid);
	init(node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_lazy(ll node, ll left, ll right)
{
	//미뤄둔 작업이 있을 때
	if (lazy[node] != 0)
	{
		//현재 노드가 담당하는 구간의 길이(right-left+1)만큼 미뤄둔 값을 곱해서 더함
		tree[node] += (right - left + 1) * lazy[node];

		//말단 노드가 아니라면, 자식들한테 미룰 값을 누적함
		if (left != right)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		
		//내 노드의 갱신은 끝났으므로 비워줌
		lazy[node] = 0;
	}
}

//구간 업데이트 함수 (start~end 구간에 diff를 더함)
void update_range(ll node, ll left, ll right, ll start, ll end, ll diff)
{
	//방문했으니 일단 미뤄둔 거 진행
	update_lazy(node, left, right);

	//구간이 완전히 벗어난 경우
	if (end < left || right < start)
		return;

	//목표 구간(start~end)이 노드 구간(left~right)을 완전히 포함하는 경우
	if (start <= left && right <= end)
	{
		//자식까지 내려가지 않고 현재 노드만 갱신후 자식들에게 미룸
		tree[node] += (right - left + 1) * diff;

		if (left != right)
		{
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}

	//구간이 걸쳐있는 경우 (쪼개서 탐색)
	ll mid = left + (right - left) / 2;
	update_range(node * 2, left, mid, start, end, diff);
	update_range(node * 2 + 1, mid + 1, right, start, end, diff);

	//자식들의 갱신이 끝났으니 부모 노드도 갱신
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll node, ll left, ll right, ll start, ll end)
{
	//값을 올바르게 조회하기 위해 미뤄둔 거 진행
	update_lazy(node, left, right);

	//구간 밖일 때
	if (end < left || right < start)
		return 0; //합에 영향 없도록 0 반환

	//완전히 포함될때
	if (start <= left && right <= end)
		return tree[node];

	//걸쳐있을 때는 쪼개서 구함
	ll mid = left + (right - left) / 2;
	return query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, M, K;
	cin >> N >> M >> K;

	for (ll i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//트리 생성(루트는 1, 범위는 arr의 0부터 N-1까지)
	init(1, 0, N - 1);

	for (ll i = 0; i < M+K; i++)
	{
		ll a;
		cin >> a;

		if (a == 1) //1 b c d : b부터 c까지 d를 더해라
		{
			ll b, c, d;
			cin >> b >> c >> d;

			//배열 인덱스에 맞게 -1씩 해줌
			update_range(1, 0, N - 1, b - 1, c - 1, d);
		}
		else if (a == 2) //2  b c : b부터 c까지의 합을 구해라
		{
			ll b, c;
			cin >> b >> c;
			cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}

	return 0;
}