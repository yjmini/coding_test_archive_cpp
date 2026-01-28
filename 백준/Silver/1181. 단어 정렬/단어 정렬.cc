#include <iostream>
#include <vector>
#include <string>
using namespace std;

string arr[20000];
string sortTemp[20000];

	
bool compare(string a, string b) {
	if (a.length() < b.length()) {
		return true;
	}
	else if (a.length() > b.length()) {
		return false;
	}
	else {
		return a < b;
	}
}

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left; //정렬될놈 인덱스


	while (i<=mid && j <=right) //정렬
	{
		if (compare(arr[i], arr[j]) == true) {
			sortTemp[k] = arr[i];
			k++;
			i++;
		}
		else {
			sortTemp[k] = arr[j];
			k++; 
			j++;
		}
	}

	while (i <= mid) { //남은놈들 처리
		sortTemp[k] = arr[i];
		k++;
		i++;
	}
	while (j <= right) {
		sortTemp[k] = arr[j];
		k++;
		j++;
	}
	for (int idx = left; idx <=right; idx++)
	{
		arr[idx] = sortTemp[idx];
	}
}

void mergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		mergeSort(left, mid);
		mergeSort(mid + 1, right);

		merge(left, mid, right);
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	mergeSort(0, N - 1);

	for (int i = 0; i < N; i++)
	{
		if (i == 0) {
			cout << arr[i] << endl;
		}
		else if (arr[i] != arr[i - 1]) {
			cout << arr[i] << endl;
		}
	}

	return 0;
}