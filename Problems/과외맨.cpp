#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321

struct Tile {
	int n, x, y, l, r;
};

int N, A, B;
Tile map[501][501];
int dist[501][501];
int dir[4] = { -1, 0, 1, 0 };

int main() {
	cin >> N;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			cin >> A >> B;
			map[i][j] = { (i + 1),i, j, A, B };
			if (i % 2 == 1 && j == N - 2) break;
		}
	}

	fill(&dist[0][0], &dist[500][501], INF);
	queue<pair<Tile, vector<int>>> q;
	vector<int> v; v.push_back(map[0][0].n);
	q.push({ map[0][0], v });
	dist[0][0] = 0;
	while (!q.empty()) {
		Tile t = q.front().first, vector<int> v = q.front().second;
		q.pop();

		for (int d = 0; d<4; d++) {
			int dx = t.x + dir[d], dy = t.y + dir[3 - d];
			if (dx<0 || dy<0 || dx >= N || dy >= N) continue;
			if (map[x1][y1] != map[dx][dy]) continue;

		}
	}

	return 0;
}