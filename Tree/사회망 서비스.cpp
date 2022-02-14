#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int N, u, v, cost = 0, root;
vector<int> tree[1000001];
int dp[1000001][2];

int dfs(int node, int contain, int prev) {
	int ret = dp[node][contain];
	if (ret != 0) return ret;

	if (contain) {
		for (int child : tree[node]) {
			if (child == prev) continue;
			ret += min(dfs(child, false, node), dfs(child, true, node));
		}
		ret++;
	}
	else {
		for (int child : tree[node]) {
			if (child == prev) continue;
			ret += dfs(child, true, node);
		}
	}

	return dp[node][contain] = ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	cout << min(dfs(1, true, 0), dfs(1, false, 0));


	return 0;
}