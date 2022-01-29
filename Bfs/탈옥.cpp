#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

int T, H, W;
char map[104][104];
int dist[3][104][104];
int dir[4] = { -1, 0, 1, 0 };
int x1, y1, x2, y2;

void bfs(int num, int i, int j) {
	fill(&dist[num][0][0], &dist[num][H + 1][W + 1], 98765432);
	deque<pair<int, pair<int, int>>> dq;
	dq.push_front({ 0,{ i, j } });
	dist[num][i][j] = 0;

	while (!dq.empty()) {
		int count = dq.front().first;
		int x = dq.front().second.first, y = dq.front().second.second;
		dq.pop_front();

		for (int d = 0; d<4; d++) {
			int dx = x + dir[d], dy = y + dir[3 - d];
			if (dx<0 || dy<0 || dx>H + 1 || dy>W + 1) continue;
			if (map[dx][dy] == '*') continue;
			int nextCount = count + ((map[dx][dy] == '#') ? 1 : 0);
			if (dist[num][dx][dy] > nextCount) {
				if (map[dx][dy] == '#') dq.push_back({ nextCount,{ dx, dy } });
				else dq.push_front({ nextCount,{ dx, dy } });
				dist[num][dx][dy] = nextCount;
			}
		}
	}
}

int main() {
	cin >> T;
	for (int t = 0; t<T; t++) {
		x1 = -1;

		cin >> H >> W;
		for (int w = 0; w <= W + 1; w++) map[0][w] = '.';
		for (int h = 1; h <= H; h++) {
			map[h][0] = '.';
			cin >> map[h] + 1;
			for (int w = 1; w <= W; w++) {
				if (map[h][w] == '$') {
					if (x1 == -1) { x1 = h; y1 = w; }
					else { x2 = h; y2 = w; }
				}
			}
			map[h][W + 1] = '.';
		}
		for (int w = 0; w <= W + 1; w++) map[H + 1][w] = '.';

		bfs(0, 0, 0);
		bfs(1, x1, y1);
		bfs(2, x2, y2);

		int answer = 98765432;

		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				int total = 0;
				for (int d = 0; d<3; d++) total += dist[d][i][j];
				total -= (map[i][j] == '#') ? 2 : 0;
				answer = min(answer, total);
			}
		}

		cout << answer << endl;
	}

	return 0;
}