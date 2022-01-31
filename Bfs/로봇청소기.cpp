#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 98765432

struct compare {
	bool operator()(pair<pair<int, int>, pair<int, int>> p1, pair<pair<int, int>, pair<int, int>> p2) {
		return p1.second.first > p2.second.first;
	}
};

int dir[4] = { -1, 0, 1, 0 };
int R, C, N, startX, startY;
char map[21][21];
pair<int, int> clear[11];
int dist[21][21][1025];

int findIndex(int x, int y) {
	for (int i = 0; i<N; i++) {
		if (clear[i].first == x && clear[i].second == y) return i;
	}
	return -1;
}

int main() {
	while (true) {
		cin >> C >> R;
		if ((R == 0) && (C == 0)) break;

		priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, compare> q;
		N = 0;

		for (int i = 0; i<R; i++) {
			cin >> map[i];
			for (int j = 0; j<C; j++) {
				if (map[i][j] == 'o') { startX = i; startY = j; }
				else if (map[i][j] == '*') clear[N++] = { i, j };
				for (int k = 0; k<1025; k++) dist[i][j][k] = INF;
			}
		}

		dist[startX][startY][(1 << N) - 1] = 0;
		q.push({ { startX, startY },{ 0, (1 << N) - 1 } });

		while (!q.empty()) {
			pair<pair<int, int>, pair<int, int>> p = q.top();
			int x = p.first.first, y = p.first.second;
			int cost = p.second.first, remain = p.second.second;
			q.pop();

			for (int d = 0; d<4; d++) {
				int dx = x + dir[d], dy = y + dir[3 - d];
				if (dx<0 || dy<0 || dx >= R || dy >= C) continue;
				if (map[dx][dy] == 'x') continue;

				int remainIdx = remain;
				if (map[dx][dy] == '*') {
					int clearIdx = (1 << findIndex(dx, dy));
					if ((remainIdx&clearIdx) == clearIdx) remainIdx ^= clearIdx;
				}
				if (dist[dx][dy][remainIdx]>cost + 1) {
					q.push({ { dx, dy },{ cost + 1, remainIdx } });
					dist[dx][dy][remainIdx] = cost + 1;
				}
			}
		}

		int minCost = INF;
		for (int i = 0; i<R; i++) {
			for (int j = 0; j<C; j++) {
				minCost = min(minCost, dist[i][j][0]);
			}
		}
		minCost = (minCost == INF) ? -1 : minCost;
		cout << minCost << endl;
	}

	return 0;
}