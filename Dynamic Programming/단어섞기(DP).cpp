#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int n;
string s1, s2, s3;
bool dp[202][202];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		fill(&dp[0][0], &dp[201][202], false);
		cin >> s1 >> s2 >> s3;

		dp[0][0] = true;
		for (int b = 0; b<s2.length(); b++) {
			if (s3[b] == s2[b]) dp[0][b + 1] = true;
		}

		for (int a = 1; a <= s1.length(); a++) {
			if (s3[a - 1] == s1[a - 1]) dp[a][0] = true;
			for (int b = 1; b <= s2.length(); b++) {
				if (dp[a - 1][b] && s3[a + b - 1] == s1[a - 1]) dp[a][b] = true;
				else if (dp[a][b - 1] && s3[a + b - 1] == s2[b - 1]) dp[a][b] = true;
			}
		}

		if (dp[s1.length()][s2.length()]) cout << "Data set " << i << ": yes" << endl;
		else cout << "Data set " << i << ": no" << endl;
	}

	return 0;
}