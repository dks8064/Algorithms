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

int N;
int W[17][17];
int dp[17][1 << 18];

int dfs(int node, int visit, int start) {
	if (dp[node][visit] != INF) return dp[node][visit];

	if ((visit&((1 << N) - 1)) == ((1 << N) - 1)) return (W[node][start] == 0) ? INF : W[node][start];

	int ret = INF;
	for (int i = 0; i < N; i++) {
		if ((W[node][i] == 0) || ((visit&(1 << i)) == (1 << i))) continue;
		ret = min(ret, dfs(i, (visit | (1 << i)), start) + W[node][i]);
	}

	return dp[node][visit] = ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	fill(&(dp[0][0]), &(dp[0][0]) + 17 * (1 << 18), INF);

	cout << dfs(0, (1 << 0), 0);

	return 0;
}