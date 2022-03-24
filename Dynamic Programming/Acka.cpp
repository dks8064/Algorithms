#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007;

int N;
int song[3];
long long dp[51][51][51][51];

long long sing(int n, int a, int b, int c) {
	if (n == 0) {
		if (a == 0 && b == 0 && c == 0) return 1;
		return 0;
	}

	long long& ret = dp[n][a][b][c];
	if (ret != -1) return ret;

	ret = 0;

	ret += sing(n - 1, a - 1, b, c);
	ret += sing(n - 1, a, b - 1, c);
	ret += sing(n - 1, a, b, c - 1);
	ret += sing(n - 1, a - 1, b - 1, c);
	ret += sing(n - 1, a, b - 1, c - 1);
	ret += sing(n - 1, a - 1, b, c - 1);
	ret += sing(n - 1, a - 1, b - 1, c - 1);

	ret %= MOD;
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> song[0] >> song[1] >> song[2];
	memset(dp, -1, sizeof(dp));
	cout << sing(N, song[0], song[1], song[2]);


	return 0;
}