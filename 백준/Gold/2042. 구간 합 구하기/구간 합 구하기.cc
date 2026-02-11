#include <iostream>
using namespace std;

#define ll long long 

ll arr[1000001]; //N
ll tree[4000001]; //4N

void myTree(ll node, ll left, ll right)
{
	if (left == right) // 마지막 말단노드에 값 배정
	{
		tree[node] = arr[left];
		return;
	}
	ll mid = left + (right - left) / 2; //가운데 인덱스 안전하게 구하기

	myTree(node * 2, left, mid);			//왼쪽
	myTree(node * 2 + 1, mid + 1, right);	//오른쪽
	tree[node] = tree[node * 2] + tree[node * 2 + 1]; //각 노드 값 채우기
}

void update(ll node, ll left, ll right, ll newIdx, ll newVal)
{
	if (left == right) //목표 노드값 갱신
	{
		tree[node] = newVal;
		return;
	}

	ll mid = left + (right - left) / 2;

	if (left <= newIdx && newIdx <= mid) //왼쪽꺼면 왼쪽으로
	{
		update(node * 2, left, mid, newIdx, newVal);
	}
	else //오른쪽꺼면 오른쪽으로 
	{
		update(node * 2 + 1, mid + 1, right, newIdx, newVal);
	}

	tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 갱신된 자식으로부터 부모 갱신
	return;
}

ll prefixSum(ll node, ll left, ll right, ll startIdx, ll endIdx)
{
	if (left > endIdx || right < startIdx) //범위 밖일때
	{
		return 0; // 합에 영향 안주기 위해 0 
	}
	if (startIdx <= left && right <= endIdx) //완전히 포함될때
	{
		return tree[node]; //내려갈필요 없이 그냥 그 값 사용
	}

	ll mid = left + (right - left) / 2;
	return prefixSum(node * 2, left, mid, startIdx, endIdx) + prefixSum(node * 2 + 1, mid + 1, right, startIdx, endIdx);
	//걸쳐있을 때는 절반 쪼개서 구함
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

	//다 입력받았으니 일단 트리 생성
	myTree(1, 0, N - 1); //tree에 1번 인덱스부터 배정. 이유는 왼쪽을 *2, 오른쪽을 *2+1하기 위해

	for (ll i = 0; i < M + K; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;

		//a==1일때 업데이트 발생
		if (a == 1)
		{
			update(1, 0, N - 1, b - 1, c);
		}

		//a==2일 때 구간합 계산
		if (a == 2)
		{
			cout << prefixSum(1, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}

	return 0;
}