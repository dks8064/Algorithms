#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 98765432
#define MAX 10001

int N, M;
int useM[101];
int getM[101];
long long dp[101][MAX];


int main() {
	cin >> N >> M;
	for (int i = 0; i<N; i++) cin >> useM[i];
	for (int i = 0; i<N; i++) cin >> getM[i];
	fill(&dp[0][0], &dp[100][MAX], 0);

	int minCost = INF;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= MAX; j++) {
			if (j >= getM[i - 1]) {
				if (useM[i - 1] + dp[i - 1][j - getM[i - 1]] < dp[i - 1][j]) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = useM[i - 1] + dp[i - 1][j - getM[i - 1]];
			}
			else dp[i][j] = dp[i - 1][j];
			if (dp[i][j] >= M) minCost = min(minCost, j);
		}
	}

	cout << minCost;

	return 0;
}