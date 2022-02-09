#include <iostream>
#include <algorithm>
using namespace std;

string s1, s2, answer = "";
string dp[1002][1002];

int main() {
	cin >> s1 >> s2;

	for (int i = 0; i<s1.length(); i++) {
		for (int j = 0; j<s2.length(); j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + s1[i];
			}
			else {
				if (dp[i][j + 1].length() >= dp[i + 1][j].length())
					dp[i + 1][j + 1] = dp[i][j + 1];
				else
					dp[i + 1][j + 1] = dp[i + 1][j];
			}
		}
	}

	cout << dp[s1.length()][s2.length()].length() << endl << dp[s1.length()][s2.length()];

	return 0;
}