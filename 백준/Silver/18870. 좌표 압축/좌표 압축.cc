#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> original(N); //원본 배열
	vector<int> sorted(N); //정렬하고 중복 제거할 배열

	for (int i = 0; i < N; i++)
	{
		cin >> original[i];
		sorted[i] = original[i]; // 입력받고 똑같이 복사
	}

	sort(sorted.begin(), sorted.end()); //오름차순 정렬

	//숫자 = 순위 기록(예를 들어, 50,100,0 이 있을 때, <50,1>,<100,2>,<0,0> 이런식으로 엮는거)
	unordered_map<int, int> dict;
	int rank = 0; //0등부터 시작

	for (int i = 0; i < N; i++)
	{
		int num = sorted[i]; //정렬된 순서로 진행

		//만약 dict에서 이 숫자가 아직 안적혀있다면
		if (dict.find(num) == dict.end())
		{
			dict[num] = rank; //등수 적어주기
			rank++; //다음 등수로
		}
		//이미 사전에 적혀있다면 스킵
	}

	for (int i = 0; i < N; i++)
	{
		cout << dict[original[i]] << " ";
	}

	return 0;
}