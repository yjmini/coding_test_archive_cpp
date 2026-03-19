#include <iostream>
#include <vector>
using namespace std;

// 상하좌우
int dr_plus[] = { -1, 1, 0, 0 };
int dc_plus[] = { 0, 0, -1, 1 };

// 왼위/오위/왼아/오아(대각선)
int dr_cross[] = { -1, -1, 1, 1 };
int dc_cross[] = { -1, 1, -1, 1 };

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> arr(n, vector<int>(n, 0));

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> arr[j][k];
			}
		}
		int max_kill = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                int sum1 = arr[r][c];

                for (int d = 0; d < 4; d++) { 
                    for (int k = 1; k < m; k++) { 
                        int nr = r + dr_plus[d] * k;
                        int nc = c + dc_plus[d] * k;

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            sum1 += arr[nr][nc];
                        }
                    }
                }

                int sum2 = arr[r][c]; 

                for (int d = 0; d < 4; d++) {
                    for (int k = 1; k < m; k++) {
                        int nr = r + dr_cross[d] * k;
                        int nc = c + dc_cross[d] * k;

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            sum2 += arr[nr][nc];
                        }
                    }
                }

                if (sum1 > max_kill) max_kill = sum1;
                if (sum2 > max_kill) max_kill = sum2;
            }
        }

        cout << "#" << i+1 << " " << max_kill << endl;

	}

	return 0;
}