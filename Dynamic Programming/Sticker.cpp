#include<iostream>
#include<algorithm>
using namespace std;

/**
* https://www.acmicpc.net/problem/9465
* Dynamic Programming
*/

int T, N;
int* sticker[2];
int* dp[2];

int func(int x, int y) {
	if (y > N) return 0;
	if (dp[x][y] != -1) return dp[x][y];

	int n = sticker[x][y];
	if (x == 0)
		n += max(func(1, y + 1), func(1, y + 2));
	else
		n += max(func(0, y + 1), func(0, y + 2));
	dp[x][y] = n;
	return n;
}

int main() {
	cin >> T;		// input

	while (T > 0) {
		cin >> N;
		for (int i = 0; i < 2; i++) {
			sticker[i] = new int[N];
			dp[i] = new int[N];
			fill(dp[i], dp[i] + N, -1);
			for (int j = 0; j < N; j++) {
				cin >> sticker[i][j];	// input
			}
		}
		cout << max(func(0, 0),func(1, 0)) << endl;	// output
		T--;
	}
	return 0;
}
