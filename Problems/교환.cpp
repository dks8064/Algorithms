#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

#define INF 98765432
#define MAX 100001

int N, K;
int maxVal = -1;
set<string> sets[10];

void bfs(string s, int k) {
	if (k == 0) {
		maxVal = max(maxVal, atoi(s.c_str()));
		return;
	}

	for (int i = 0; i<s.length() - 1; i++) {
		for (int j = i + 1; j<s.length(); j++) {
			if (i == 0 && s[j] == '0') continue;
			char c = s[i];
			s[i] = s[j];
			s[j] = c;
			if (sets[k - 1].find(s) == sets[k - 1].end()) {
				sets[k - 1].insert(s);
				bfs(s, k - 1);
			}
			s[j] = s[i];
			s[i] = c;
		}
	}
}

int main() {
	cin >> N >> K;

	bfs(to_string(N), K);
	cout << maxVal;

	return 0;
}