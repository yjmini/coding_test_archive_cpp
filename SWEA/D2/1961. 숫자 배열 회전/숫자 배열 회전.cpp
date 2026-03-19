#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		vector<vector<int>> arr(n, vector<int>(n, 0));

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> arr[j][k];
			}
		}
		cout << "#" << i+1 << endl;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cout << arr[n-k-1][j];
			}
			cout << " ";
			for (int k = 0; k < n; k++) {
				cout << arr[n - j - 1][n - k - 1];
			}
			cout << " ";
			for (int k = 0; k < n; k++) {
				cout << arr[k][n - j - 1];
			}
			cout << endl;
		}
	}

	return 0;
}