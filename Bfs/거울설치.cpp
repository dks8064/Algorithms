#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int N, startX = -1, startY, endX, endY;
char map[51][51];
int dist[51][51][4];
int dir[4] = { -1, 0, 1, 0 };

int main() {
	cin >> N;
	for (int i = 0; i<N; i++) {
		cin >> map[i];
		for (int j = 0; j<N; j++) {
			if (map[i][j] == '#') {
				if (startX == -1) { startX = i; startY = j; }
				else { endX = i; endY = j; }
			}
		}
	}

	for (int d = 0; d<4; d++) fill(&dist[0][0][d], &dist[50][51][d], INF);

	priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
	pq.push({ { 0, -1 },{ startX, startY } });
	for (int d = 0; d<4; d++) dist[startX][startY][d] = 0;

	while (!pq.empty()) {
		pair<pair<int, int>, pair<int, int>> p = pq.top();
		int cnt = p.first.first, direction = p.first.second;
		int x = p.second.first, y = p.second.second;
		pq.pop();

		for (int d = 0; d<4; d++) {
			int dx = x + dir[d], dy = y + dir[3 - d];
			if (dx<0 || dy<0 || dx >= N || dy >= N) continue;
			if (map[x][y] == '.' && direction != d) continue;
			if (map[dx][dy] == '*') continue;
			int nextCnt = cnt;
			if (map[x][y] == '!') {
				if (direction % 2 != d % 2) nextCnt++;
				else if (direction != d) continue;
			}
			if (dist[dx][dy][d] <= nextCnt) continue;
			dist[dx][dy][d] = nextCnt;
			pq.push({ { nextCnt, d },{ dx, dy } });
		}
	}

	int answer = INF;
	for (int d = 0; d<4; d++) answer = min(answer, dist[endX][endY][d]);
	cout << answer;

	return 0;
}