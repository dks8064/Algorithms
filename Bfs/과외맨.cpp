#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

struct Tile {
	int number, left, right;
};

Tile tile;
int N, L, R, cnt = 1, maxNum = 1;
Tile arr[505][505];
int parent[250001];
int dist[250001];
int dir[4] = { -1, 0, 1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i % 2 == 1 && j == N - 1) break;
			cin >> L >> R;
			tile.number = cnt;
			tile.left = L;
			tile.right = R;
			arr[i][j] = tile;
			cnt++;
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0, 0 }, 1 });
	dist[1] = 1;
	parent[1] = 0;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int distance = q.front().second;
		int cur = arr[x][y].number;
		q.pop();

		for (int d = 0; d < 3; d++) {
			int dx = x + dir[d], dy = y + dir[3 - d];
			if (x % 2 == 1 && d != 1) dy++;
			int next = arr[dx][dy].number;
			if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
			if (dx % 2 == 1 && dy == N - 1) continue;
			if (dist[next] != 0 && dist[next] <= distance + 1) continue;
			if (arr[x][y].right == arr[dx][dy].left) {
				parent[next] = cur;
				dist[next] = distance + 1;
				maxNum = max(maxNum, next);
				if (next == cnt - 1) break;
				q.push({ { dx, dy }, distance + 1 });
			}
		}

		for (int d = 2; d < 5; d++) {
			int dx = x + dir[d % 4], dy = y + dir[3 - (d % 4)];
			if (x % 2 == 0 && d != 3) dy--;
			int next = arr[dx][dy].number;
			if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
			if (dx % 2 == 1 && dy == N - 1) continue;
			if (dist[next] != 0 && dist[next] <= distance + 1) continue;
			if (arr[x][y].left == arr[dx][dy].right) {
				parent[next] = cur;
				dist[next] = distance + 1;
				maxNum = max(maxNum, next);
				if (next == cnt - 1) break;
				q.push({ { dx, dy }, distance + 1 });
			}
		}
	}

	cout << dist[maxNum] << endl;

	stack<int> path;
	while (maxNum != 0) {
		path.push(maxNum);
		maxNum = parent[maxNum];
	}
	while (!path.empty()) {
		cout << path.top() << " ";
		path.pop();
	}

	return 0;
}

