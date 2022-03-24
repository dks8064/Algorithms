#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[5005];
int dp[5005][5005];

int palindrome(int s, int e) {
	if (s >= e) return dp[s][e] = 0;

	int ret = dp[s][e];
	if (ret != -1) return ret;

	ret = 0;
	if (arr[s] == arr[e]) ret += palindrome(s + 1, e - 1);
	else ret += (min(palindrome(s + 1, e), palindrome(s, e - 1)) + 1);

	return dp[s][e] = ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(dp, -1, sizeof(dp));

	cout << palindrome(0, N - 1);


	return 0;
}