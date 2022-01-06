#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int R, C, sX, sY;
int dir[4] = { -1, 0, 1, 0 };
char map[1501][1501];


bool isMeet(int x, int y, bool visited[1501][1501]) {
	for (int d = 0; d<4; d++) {
		int dx = x + dir[d], dy = y + dir[3 - d];
		if (dx < 0 || dy < 0 || dx > R - 1 || dy > C - 1) continue;
		if (map[dx][dy] == 'X' || visited[dx][dy]) continue;
		visited[dx][dy] = true;
		if (map[dx][dy] == 'L') return true;
		if (isMeet(dx, dy, visited)) return true;
	}

	return false;
}

void melt() {
	bool visited[1501][1501] = { false, };
	for (int i = 0; i<R; i++) {
		for (int j = 0; j<C; j++) {
			if (map[i][j] == 'X') {
				bool isMelt = false;
				for (int d = 0; d<4; d++) {
					int dx = i + dir[d], dy = j + dir[3 - d];
					if (dx < 0 || dy < 0 || dx > R - 1 || dy > C - 1) continue;
					if (map[dx][dy] != 'X' && !visited[dx][dy]) {
						isMelt = true;
						break;
					}
				}
				if (isMelt) {
					map[i][j] = '.';
					visited[i][j] = true;
				}
			}
		}
	}
}

int main() {
	cin >> R >> C;
	bool isFind = false;
	for (int i = 0; i<R; i++) {
		cin >> map[i];
		if (!isFind) {
			for (int j = 0; j<C; j++) {
				if (map[i][j] == 'L') {
					sX = i;
					sY = j;
					isFind = true;
				}
			}
		}
	}

	int date = 0;
	bool visited[1501][1501] = { false, };
	visited[sX][sY] = true;
	while (!isMeet(sX, sY, visited)) {
		memset(visited, false, sizeof(visited));
		visited[sX][sY] = true;
		date++;
		melt();
	}

	cout << date;

	return 0;
}