#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int R, C, startX, startY, endX, endY, eraseX, eraseY;
char map[26][26];
bool visited[26][26] = { false, };
int dir[4] = { -1, 0, 1, 0 };
set<pair<int, int>> s;

void search(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		for (int d = 0; d<4; d++) {
			int di = i + dir[d], dj = j + dir[3 - d];
			if (di<0 || dj<0 || di >= R || dj >= C) continue;
			if (visited[di][dj]) continue;
			if (map[i][j] == '-' && (d % 2 == 0)) continue;
			if (map[i][j] == '|' && (d % 2 == 1)) continue;
			if (map[i][j] == '1' && (d == 0 || d == 3)) continue;
			if (map[i][j] == '2' && (d == 2 || d == 3)) continue;
			if (map[i][j] == '3' && (d == 1 || d == 2)) continue;
			if (map[i][j] == '4' && (d == 0 || d == 1)) continue;
			if ((map[i][j] == 'M' || map[i][j] == 'Z') &&
				(map[di][dj] == '.' || map[di][dj] == 'M' || map[di][dj] == 'Z')) continue;
			if (map[di][dj] == '.') {
				eraseX = di;
				eraseY = dj;
				s.insert({ i, j });
				continue;
			}
			visited[di][dj] = true;
			q.push({ di, dj });
		}
	}
}

char findChar() {
	if (s.size() == 0) { eraseX = (startX + endX) / 2; eraseY = (startY + endY) / 2; }
	if (s.size() == 0 || s.size() == 1) {
		s.insert({ startX, startY });
		s.insert({ endX, endY });
	}

	if (s.size() == 4) return '+';

	bool nextDir[4] = { false, };
	for (pair<int, int> p : s) {
		int x = p.first - eraseX, y = p.second - eraseY;
		for (int d = 0; d<4; d++) {
			if (dir[d] == x && dir[3 - d] == y) nextDir[d] = true;
		}
	}

	if (nextDir[0] && nextDir[2]) return '|';
	if (nextDir[1] && nextDir[3]) return '-';
	if (nextDir[1] && nextDir[2]) return '1';
	if (nextDir[0] && nextDir[1]) return '2';
	if (nextDir[0] && nextDir[3]) return '3';
	if (nextDir[2] && nextDir[3]) return '4';
}

int main() {
	cin >> R >> C;
	for (int i = 0; i<R; i++) {
		cin >> map[i];
		for (int j = 0; j<C; j++) {
			if (map[i][j] == 'M') { startX = i; startY = j; }
			else if (map[i][j] == 'Z') { endX = i; endY = j; }
		}
	}

	search(startX, startY);
	search(endX, endY);
	for (int i = 0; i<R; i++) {
		for (int j = 0; j<C; j++) {
			if (map[i][j] != '.' && !visited[i][j]) search(i, j);
		}
	}

	char lostPath = findChar();
	cout << eraseX + 1 << " " << eraseY + 1 << " " << lostPath << endl;

	return 0;
}