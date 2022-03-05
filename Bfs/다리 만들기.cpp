#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int N, number, answer = INT_MAX, id = 2;
int map[101][101];
bool visited[101][101];
int dir[4] = { -1, 0, 1, 0 };

int bfs(int id) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == id) {
				visited[i][j] = true;
				q.push({ i, j });
			}
		}
	}

	int dist = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int d = 0; d < 4; d++) {
				int dx = x + dir[d], dy = y + dir[3 - d];
				if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
				if (visited[dx][dy]) continue;
				if (map[dx][dy] > 0) return dist;
				visited[dx][dy] = true;
				q.push({ dx, dy });
			}
		}
		dist++;
	}

	return INT_MAX;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> map[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 1) continue;
			map[i][j] = id;
			q.push({ i, j });
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();

				for (int d = 0; d < 4; d++) {
					int dx = x + dir[d], dy = y + dir[3 - d];
					if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
					if (map[dx][dy] != 1) continue;
					map[dx][dy] = id;
					q.push({ dx, dy });
				}
			}
			id++;
		}
	}

	for (int i = 2; i < id; i++) {
		answer = min(answer, bfs(i));
	}

	cout << answer;


	return 0;
}