#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int N = 8;
char map[8][8];
int dirX[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dirY[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

bool bfs() {
	queue<pair<int, int>> q;
	q.push({ N - 1, 0 });

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i<size; i++) {
			pair<int, int> p = q.front();
			int x = p.first, y = p.second;
			q.pop();

			if (map[x][y] == '#') continue;
			if (x == 0 && y == N - 1) return true;
			for (int d = 0; d<9; d++) {
				int dx = x + dirX[d], dy = y + dirY[d];
				if (dx<0 || dy<0 || dx >= N || dy >= N) continue;
				if (map[dx][dy] == '#') continue;
				q.push({ dx, dy });
			}
		}

		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j<N; j++) {
				if (i == 0) map[i][j] = '.';
				else map[i][j] = map[i - 1][j];
			}
		}
	}

	return false;
}

int main() {

	for (int i = 0; i<N; i++) cin >> map[i];
	if (bfs()) cout << 1;
	else cout << 0;

	return 0;
}