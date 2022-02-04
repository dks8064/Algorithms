#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321

int N, M, K;
char map[101][101];
string alpha;
int dir[4] = { -1, 0, 1, 0 };
int dist[101][101][81];

int dfs(int x, int y, int cnt) {
	if (cnt == alpha.length() - 1) return dist[x][y][cnt] = 1;

	if (dist[x][y][cnt] != INF) return dist[x][y][cnt];

	int ret = 0;
	for (int k = 1; k <= K; k++) {
		for (int d = 0; d<4; d++) {
			int dx = x + dir[d] * k, dy = y + dir[3 - d] * k;
			if (dx<0 || dy<0 || dx >= N || dy >= M) continue;
			if (map[dx][dy] != alpha[cnt + 1]) continue;
			ret += dfs(dx, dy, cnt + 1);
		}
	}
	return dist[x][y][cnt] = ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i<N; i++) {
		cin >> map[i];
		fill(&dist[i][0][0], &dist[i][101][81], INF);
	}
	cin >> alpha;

	int path = 0;

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			if (map[i][j] == alpha[0]) path += dfs(i, j, 0);
		}
	}

	cout << path;

	return 0;
}