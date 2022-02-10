#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int n;
string s1, s2, s3;
bool visited[202][202];

bool bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0,0 },0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (c == s3.length()) return true;
		if (a<s1.length() && !visited[a + 1][b] && s1[a] == s3[c]) {
			q.push({ { a + 1, b }, c + 1 });
			visited[a + 1][b] = true;
		}
		if (b<s2.length() && !visited[a][b + 1] && s2[b] == s3[c]) {
			q.push({ { a, b + 1 }, c + 1 });
			visited[a][b + 1] = true;
		}
	}

	return false;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		fill(&visited[0][0], &visited[201][202], false);
		cin >> s1 >> s2 >> s3;

		if (bfs()) cout << "Data set " << i << ": yes" << endl;
		else cout << "Data set " << i << ": no" << endl;
	}

	return 0;
}