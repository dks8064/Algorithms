#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, answer = 11;
char map[21][21];
vector<pair<int, int>> coin;
int dir[4] = { -1, 0, 1, 0 };

void dfs(int count, int x1, int y1, int x2, int y2) {
	if (count == 11) return;

	for (int d = 0; d < 4; d++) {
		int dx1 = x1 + dir[d], dy1 = y1 + dir[3 - d];
		int dx2 = x2 + dir[d], dy2 = y2 + dir[3 - d];
		bool coin1 = (dx1 < 0 || dx1 >= N || dy1 < 0 || dy1 >= M);
		bool coin2 = (dx2 < 0 || dx2 >= N || dy2 < 0 || dy2 >= M);

		if (coin1 && coin2) continue;
		if (coin1 || coin2) {
			answer = min(answer, count);
			continue;
		}

		if (map[dx1][dy1] == '#') {
			dx1 = x1; dy1 = y1;
		}
		if (map[dx2][dy2] == '#') {
			dx2 = x2; dy2 = y2;
		}
		dfs(count + 1, dx1, dy1, dx2, dy2);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'o') {
				coin.push_back({ i, j });
				map[i][j] = '.';
			}
		}
	}

	dfs(1, coin[0].first, coin[0].second, coin[1].first, coin[1].second);


	cout << ((answer>10) ? -1 : answer);

	return 0;
}