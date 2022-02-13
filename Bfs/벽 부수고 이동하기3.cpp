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

int N, M, K;
char m[1001][1001];
bool dist[1001][1001][11][2] = { false, };
int dir[5] = { -1, 0, 0, 1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> m[i];

	queue<pair<pair<pair<int, int>, bool>, pair<int, int>>> q;
	q.push({ { { 0, K }, true },{ 0, 0 } });
	dist[0][0][K][1] = true;
	int answer = INF;
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int t = q.front().first.first.first;
		int k = q.front().first.first.second;
		bool day = q.front().first.second;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			answer = min(answer, t + 1);
			break;
		}

		for (int d = 0; d < 5; d++) {
			int dx = x + dir[d], dy = y + dir[4 - d];
			if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
			if (m[dx][dy] == '1') {
				if (dx == x && dy == y) {
					if (dist[dx][dy][k][!day]) continue;
					q.push({ { { (t + 1), k }, !day },{ dx, dy } });
					dist[dx][dy][k][!day] = true;
				}
				else if (!day || (k == 0) || dist[dx][dy][k - 1][!day]) continue;
				else {
					q.push({ { { (t + 1), k - 1 }, !day },{ dx, dy } });
					dist[dx][dy][k - 1][!day] = true;
				}
			}
			else if (dist[dx][dy][k][!day]) continue;
			else {
				q.push({ { { (t + 1), k }, !day },{ dx, dy } });
				dist[dx][dy][k][!day] = true;
			}
		}
	}

	cout << ((answer == INF) ? -1 : answer);

	return 0;
}