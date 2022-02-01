#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 98765432
#define MAX 100001

int N, M, S, E;
int arr[2001];
int dp[2001][2001];

int isPalindrome(int s, int e) {
	if (s>2000 || e<0) return 0;
	if (s == e || s>e) return 1;
	if (dp[s][e] != -1) return dp[s][e];

	if (arr[s] != arr[e]) return dp[s][e] = 0;
	return dp[s][e] = isPalindrome(s + 1, e - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	fill(&dp[0][0], &dp[2000][2001], -1);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cin >> M;
	for (int m = 0; m<M; m++) {
		cin >> S >> E;
		cout << isPalindrome(S, E) << '\n';
	}

	return 0;
}