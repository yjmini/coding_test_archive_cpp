#include <iostream>
#include <string>
using namespace std;

int stackArr[10000];

int main() {


	int idx = -1;

	int iter;
	cin >> iter;



	for (int i = 0; i < iter; i++)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int n;
			cin >> n;
			idx++;
			stackArr[idx] = n;
		}
		else if (cmd == "pop") {
			if (idx <0) {
				cout << -1 << endl;
			}
			else {
				cout << stackArr[idx] << endl;
				idx--;
			}

		}
		else if (cmd == "size") {
			cout << ++idx << endl;
			idx--;
		}
		else if (cmd == "empty") {
			if (idx < 0) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (cmd == "top") {
			if (idx < 0) {
				cout << -1 << endl;
			}
			else {
				cout << stackArr[idx] << endl;
			}

		}
	}



	return 0;
}