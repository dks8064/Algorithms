#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define INF 98765432

int N, M, K, answer = -1;
char m[1001][1001];
bool visited[1001][1001][11] = { false, };
int dir[4] = { -1, 0, 1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> m[i];

	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { 0, 0 },{ 1, K } });
	visited[0][0][K] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		int wall = q.front().second.second;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			answer = dist;
			break;
		}

		for (int d = 0; d < 4; d++) {
			int dx = x + dir[d], dy = y + dir[3 - d], next = wall;
			if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
			if (m[dx][dy] == '1' && wall == 0) continue;
			if (m[dx][dy] == '1') next--;
			if (visited[dx][dy][next]) continue;
			q.push({ { dx, dy },{ dist + 1, next } });
			visited[dx][dy][next] = true;
		}
	}

	cout << answer;

	return 0;
}