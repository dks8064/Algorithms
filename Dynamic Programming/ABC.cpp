#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int dp[31][31][31][500];
char answer[31];

bool pairCount(int a, int b, int c, int k) {
	if (a + b + c == N) return !k;
	if (k <= 0) return false;

	int& ret = dp[a][b][c][k];
	if (ret != -1) return ret;

	answer[a + b + c] = 'A';
	if (pairCount(a + 1, b, c, k)) return ret = 1;
	answer[a + b + c] = 'B';
	if (pairCount(a, b + 1, c, k - a)) return ret = 1;
	answer[a + b + c] = 'C';
	if (pairCount(a, b, c + 1, k - a - b)) return ret = 1;

	return ret = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> K;
	memset(dp, -1, sizeof(dp));

	if (K == 0) {
		for (int i = 0; i < N; i++) cout << 'A';
	}
	else if (!pairCount(0, 0, 0, K)) {
		cout << -1;
	}
	else {
		for (int i = 0; i<N; i++) cout << answer[i];
	}

	return 0;
}