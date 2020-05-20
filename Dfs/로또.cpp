#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* https://www.acmicpc.net/problem/6603
* dfs
*/

int num = 1;
vector<int> v;

void func(int n, string str) {
	if (num == 6) {
		cout << str << endl;
	}
	else {
		for (int i = n + 1; i < v.size(); i++) {
			num++;
			func(i, str + to_string(v[i]) + " ");
		}
	}
	num--;
}

int main() {
	int temp, N = 1;
	while (N != 0) {
		cin >> N;

		for (int n = 0; n < N; n++) {
			cin >> temp;
			v.push_back(temp);
		}

		for (int n = 0; n < N; n++) {
			num = 1;
			func(n, to_string(v[n]) + " ");
		}

		v.clear();
		cout << endl;
	}

	return 0;
}