#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, EX, EY;
char map[51][51];
int dir[4] = { -1, 0, 1, 0 };
bool visited[51][51] = { false, };
bool isEnd = false;

void dfs(int x, int y, int cnt) {
	visited[x][y] = true;
	if (isEnd) return;

	for (int d = 0; d < 4; d++) {
		int dx = x + dir[d], dy = y + dir[3 - d];
		if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
		if (cnt >= 4 && EX == dx && EY == dy) {
			isEnd = true; return;
		}
		if (visited[dx][dy] || (map[dx][dy] != map[x][y])) continue;
		dfs(dx, dy, cnt + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> map[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(visited, false, sizeof(visited));
			EX = i;
			EY = j;
			dfs(i, j, 1);

			if (isEnd) {
				cout << "Yes";
				return 0;
			}
		}
	}

	cout << "No";

	return 0;
}