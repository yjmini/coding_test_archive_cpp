#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(void) {
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		vector<int> arr_a(n), arr_b(m);

		for (int a = 0; a < n; a++) {
			cin >> arr_a[a];
		}
		for (int b = 0; b < m; b++) {
			cin >> arr_b[b];
		}

		if (n > m) {
			swap(n, m);
			swap(arr_a, arr_b);
		}

		int result = INT_MIN;


		for (int j = 0; j < m - n + 1; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++) {
				sum = sum + arr_a[k] * arr_b[k + j];
			}
			result = max(result, sum);
		}
		cout << "#" << i+1 << " " << result << endl;
	}

	return 0;
}