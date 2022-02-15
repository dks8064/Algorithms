#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define INF 98765432

int N, u, v;
int people[10001];
vector<int> tree[10001];
int dp[10001][2];

int dfs(int node, bool selected, int prev) {
	int ret = dp[node][selected];
	if (ret != 0) return ret;

	for (int child : tree[node]) {
		if (child == prev) continue;
		if (selected) ret += dfs(child, false, node);
		else ret += max(dfs(child, false, node), dfs(child, true, node));
	}
	if (selected) ret += people[node];

	return dp[node][selected] = ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> people[i];
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	cout << max(dfs(1, true, 0), dfs(1, false, 0));

	return 0;
}