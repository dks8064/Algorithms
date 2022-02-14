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

int N, u, v, cost = 0;
int w[10001];
vector<int> tree[10001];
vector<int> path;
int dp[10001][2];
bool visited[10001] = { false, };

int dfs(int node, bool contain, int prev) {
	int ret = dp[node][contain];
	if (ret != 0) return ret;

	if (contain) {
		for (int child : tree[node]) {
			if (child == prev) continue;
			ret += dfs(child, false, node);
		}
		ret += w[node];
	}
	else {
		for (int child : tree[node]) {
			if (child == prev) continue;
			ret += max(dfs(child, false, node), dfs(child, true, node));
		}
	}

	return dp[node][contain] = ret;
}

void findPath(int node, int prev) {

	if (dp[node][true] > dp[node][false] && !visited[prev]) {
		path.push_back(node);
		visited[node] = true;
	}

	for (int child : tree[node]) {
		if (child == prev) continue;
		findPath(child, node);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> w[i];
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	cost = max(dfs(1, false, 0), dfs(1, true, 0));
	cout << cost << '\n';

	findPath(1, 0);
	sort(path.begin(), path.end());
	for (int p : path) cout << p << " ";


	return 0;
}