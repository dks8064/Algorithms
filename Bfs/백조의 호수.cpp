#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C, sX, sY, day = 0;
char map[1500][1500];
int dir[4] = { -1, 0, 1, 0 };
queue<pair<int, int>> iceQ;
queue<pair<int, int>> swanQ;
bool visited[1500][1500] = { false, };
bool swanVisited[1500][1500] = { false, };

void putIceQueue() {
	for (int i = 0; i<R; i++) {
		for (int j = 0; j<C; j++) {
			if (map[i][j] == '.' || map[i][j] == 'L') {
				for (int d = 0; d<4; d++) {
					int di = i + dir[d], dj = j + dir[3 - d];
					if (di < 0 || dj < 0 || di >= R || dj >= C) continue;
					if (map[di][dj] != 'X' || visited[di][dj]) continue;
					visited[di][dj] = true;
					iceQ.push({ di, dj });
				}
			}
		}
	}

}

void melt() {
	if (iceQ.empty()) putIceQueue();
	int qSize = iceQ.size();
	for (int i = 0; i<qSize; i++) {
		int x = iceQ.front().first, y = iceQ.front().second;
		iceQ.pop();

		map[x][y] = '.';

		bool isConnect = false;
		for (int d = 0; d<4; d++) {
			int dx = x + dir[d], dy = y + dir[3 - d];
			if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
			if (map[dx][dy] == 'X' && !visited[dx][dy]) {
				visited[dx][dy] = true;
				iceQ.push({ dx, dy });
			}
			if (!isConnect && swanVisited[dx][dy]) {
				isConnect = true;
				swanQ.push({ x, y });
			}
		}

	}

}

bool isMeet() {
	while (!swanQ.empty()) {
		int x = swanQ.front().first, y = swanQ.front().second;
		swanQ.pop();
		swanVisited[x][y] = true;

		for (int d = 0; d<4; d++) {
			int dx = x + dir[d], dy = y + dir[3 - d];
			if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
			if (map[dx][dy] == 'X' || swanVisited[dx][dy]) continue;
			if (map[dx][dy] == 'L') return true;
			swanVisited[dx][dy] = true;
			swanQ.push({ dx, dy });
		}
	}

	return false;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i<R; i++) {
		cin >> map[i];
		for (int j = 0; j<C; j++) {
			if (map[i][j] == 'L') {
				sX = i; sY = j;
				break;
			}
		}
	}

	swanQ.push({ sX, sY });

	while (!isMeet()) {
		melt();
		day++;
	};

	cout << day;

	return 0;
}