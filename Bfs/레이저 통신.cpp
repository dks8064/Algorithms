#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int W, H;
char map[101][101];
int startX = -1, startY;
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };
int minCount = 98765432;
queue<pair<pair<int, int>, pair<int, int>>> q;

int main() {
	cin >> W >> H;
	for (int i = 0; i<H; i++) {
		cin >> map[i];
		for (int j = 0; j<W; j++) {
			if (map[i][j] == 'C' && startX == -1) {
				startX = i; startY = j;
			}
		}
	}

	vector<vector<int>> visited(101, vector<int>(101, 98765432));
	visited[startX][startY] = 0;
	q.push({ { startX, startY },{ 4, 0 } });

	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> p = q.front();
		int x = p.first.first, y = p.first.second;
		int pre = p.second.first, count = p.second.second;
		q.pop();


		visited[x][y] = min(visited[x][y], count);
		if (map[x][y] == 'C' && pre != 4) {
			minCount = min(minCount, count);
			continue;
		}

		for (int d = 0; d<4; d++) {
			int dx = x + dirX[d], dy = y + dirY[d];
			int addCount = ((pre == d) || pre == 4) ? 0 : 1;
			if (dx < 0 || dy < 0 || dx >= H || dy >= W) continue;
			if (map[dx][dy] == '*') continue;
			if (visited[dx][dy] < count + addCount) continue;
			visited[dx][dy] = count + addCount;
			q.push({ { dx, dy },{ d, count + addCount } });
		}

	}

	cout << minCount;

	return 0;
}