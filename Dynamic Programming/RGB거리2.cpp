#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321

int N, r, g, b;
int house[1003][3];
int dp[1003][3][3];
int minCost = INF;

int dfs(int color[1003], int i, int start) {
	if (dp[i][color[i]][start] != INF) return dp[i][color[i]][start];
	if (i == N) return dp[i][color[i]][start] = house[i][color[i]];

	int ret = INF;
	for (int k = 0; k < 3; k++) {
		if (color[i] == k) continue;
		if (i + 1 == N && color[1] == k) continue;
		color[i + 1] = k;
		int count = dfs(color, i + 1, start);
		ret = min(ret, count);
	}
	return dp[i][color[i]][start] = ret + house[i][color[i]];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> house[i][0] >> house[i][1] >> house[i][2];
	house[0][0] = house[0][1] = house[0][2] = 0;
	house[N + 1][0] = house[N + 1][1] = house[N + 1][2] = -1;

	fill(&dp[0][0][0], &dp[1002][3][3], INF);
	int color[1003];
	int minCost = INF;
	for (int k = 0; k < 3; k++) {
		color[1] = k;
		minCost = min(minCost, dfs(color, 1, k));
	}

	cout << minCost;

	return 0;
}