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

int N, M;
int m[8][8];
bool visited[8][8] = { false, };
int dir[4] = { -1, 0, 1, 0 };
int answer = 0;

void dfs(int x, int y) {
	for (int d = 0; d < 4; d++) {
		int dx = x + dir[d], dy = y + dir[3 - d];
		if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
		if (visited[dx][dy]) continue;
		visited[dx][dy] = true;
		dfs(dx, dy);
	}
}

void checkArea() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] != 0) visited[i][j] = true;
			else visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 2) dfs(i, j);
		}
	}

	int areaCount = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) areaCount++;
		}
	}

	answer = max(answer, areaCount);
}

void setWall(int sx, int sy, int num) {
	if (num == 3) {
		checkArea();
		return;
	}

	sy++;
	if (sy == M) {
		sx++; sy = 0;
	}
	if (sx >= N) return;

	for (int i = sx; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == sx && j == 0) j = sy;
			if (m[i][j] == 2 || m[i][j] == 1) continue;
			m[i][j] = 1;
			setWall(i, j, num + 1);
			m[i][j] = 0;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> m[i][j];
	}

	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 2 || m[i][j] == 1) continue;
			m[i][j] = 1;
			setWall(i, j, 1);
			m[i][j] = 0;
		}
	}

	cout << answer;

	return 0;
}
