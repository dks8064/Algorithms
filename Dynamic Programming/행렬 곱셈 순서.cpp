#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define INF 1000000000

int N, K, r, c;
int dp[501][501];
vector<pair<int, int>> v;

int main()
{
	cin >> K;
	for (int i = 0; i<K; i++) {
		cin >> r >> c;
		v.push_back({ r, c });
		dp[i][i] = 0;
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= K - i; j++) {
			dp[j][i + j] = INF;
			for (int k = j; k < i + j; k++) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + (v[j].first*v[k].second*v[i + j].second));
			}
		}
	}

	cout << dp[0][K - 1] << endl;

}