#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int dfs(int s, int p) {
	int ret = 0;

	for (int i = s; i<v.size(); i++) {
		if ((i + v[i].first) <= v.size()) {
			ret = max(ret, dfs(i + v[i].first, v[i].second));
		}
	}

	return p + ret;
}

int main() {
	int N, a, b;
	cin >> N;
	for (int i = 0; i<N; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}

	cout << dfs(0, 0);

	return 0;
}