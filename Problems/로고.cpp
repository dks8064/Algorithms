#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321

int N, x1, y1, x2, y2;
bool map[2004][2004] = { false, };
bool visited[2004][2004] = { false, };
int dir[4] = { -1, 0, 1, 0 }; // ╩С, ©Л, го, аб

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i<N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1 = (x1 + 500) * 2; y1 = (y1 + 500) * 2; x2 = (x2 + 500) * 2; y2 = (y2 + 500) * 2;
		for (int y = y1; y <= y2; y++) {
			map[x1][y] = true; map[x2][y] = true;
		}
		for (int x = x1; x <= x2; x++) {
			map[x][y1] = true; map[x][y2] = true;
		}
	}

	int cnt = 0;
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			if (!map[i][j] || visited[i][j]) continue;
			queue<pair<int, int>> q;
			q.push({ i, j });
			visited[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int d = 0; d<4; d++) {
					int dx = x + dir[d], dy = y + dir[3 - d];
					if (dx<0 || dy<0 || dx>2000 || dy>2000) continue;
					if (visited[dx][dy] || !map[dx][dy]) continue;
					q.push({ dx, dy });
					visited[dx][dy] = true;
				}
			}
			cnt++;
		}
	}

	cout << (map[1000][1000] ? cnt - 1 : cnt);

	return 0;
}