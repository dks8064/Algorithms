#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

string a, b;
int dp[1002][1002];

int main() {
	cin >> a >> b;
	int aLength = a.length(), bLength = b.length();

	for (int i = 1; i <= aLength; i++) {
		for (int j = 1; j <= bLength; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[aLength][bLength] << endl;

	stack<char> st;
	int i = aLength, j = bLength;
	while (i > 0 && j > 0) {
		if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else {
			i--; j--;
			st.push(a[i]);
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}