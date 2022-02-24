#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;

#define INF 98765432

int N, M, r, c, d;
int m[51][51];
int dir[4] = { -1, 0, 1, 0 };
int answer = 1;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> m[i][j];
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ { r, c }, d });
	m[r][c] = 2;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();

		for (int i = 0; i < 5; i++) {
			if (i != 4) d = (d == 0) ? 3 : d - 1;
			int dx = x + dir[d], dy = y + dir[3 - d];
			if (i == 4) { dx = x - dir[d], dy = y - dir[3 - d]; }
			if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
			if (m[dx][dy] == 1) continue;
			if (i != 4 && m[dx][dy] == 2) continue;
			q.push({ { dx, dy }, d });
			if (i != 4) answer++;
			m[dx][dy] = 2;
			break;
		}
	}

	cout << answer;

	return 0;
}
