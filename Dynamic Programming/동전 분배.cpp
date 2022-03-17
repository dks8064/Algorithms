#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

int N, P, C;
int total = 0;
vector<pair<int, int>> v;
int money[50001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int t = 0; t < 3; t++) {
		cin >> N;
		memset(money, 0, sizeof(money));
		v.clear();
		total = 0;
		for (int i = 0; i < N; i++) {
			cin >> P >> C;
			v.push_back({ P, C });
			total += (P*C);
		}

		if (total % 2 == 1) {
			cout << 0 << '\n';
			continue;
		}

		money[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 50000; j >= v[i].first; j--) {
				if (money[j - v[i].first]) {
					for (int k = 0; (k < v[i].second) && (j + k*v[i].first) <= 50000; k++) {
						money[j + k*v[i].first] = 1;
					}
				}
			}
		}

		cout << money[total / 2] << '\n';
	}


	return 0;
}

