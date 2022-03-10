#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int N, M, X, Y, RX, RY, BX, BY;
char board[11][11];
int dir[4] = { -1, 0, 1, 0 };
bool visited[101][101] = { false, };

struct Marble {
	pair<int, int> pos[2];

	Marble(int rx, int ry, int bx, int by) {
		pos[0].first = rx;
		pos[0].second = ry;
		pos[1].first = bx;
		pos[1].second = by;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				RX = i; RY = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				BX = i; BY = j;
				board[i][j] = '.';
			}
		}
	}

	queue<pair<Marble, int>> q;
	q.push({ Marble(RX, RY, BX, BY), 0 });
	visited[RX*M + RY][BX*M + BY] = true;
	while (!q.empty()) {
		Marble marble = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (dist >= 10) continue;

		for (int d = 0; d < 4; d++) {
			RX = marble.pos[0].first;
			RY = marble.pos[0].second;
			BX = marble.pos[1].first;
			BY = marble.pos[1].second;
			for (int i = 0; i < 2; i++) {
				int dx = marble.pos[i].first + dir[d], dy = marble.pos[i].second + dir[3 - d];
				while (true) {
					if (board[dx][dy] == '#') {
						dx -= dir[d];
						dy -= dir[3 - d];
						break;
					}
					if (board[dx][dy] == 'O') break;
					dx += dir[d];
					dy += dir[3 - d];
				}
				if (i == 0) { RX = dx; RY = dy; }
				else { BX = dx; BY = dy; }
			}

			if (RX == marble.pos[0].first && RY == marble.pos[0].second
				&& BX == marble.pos[1].first && BY == marble.pos[1].second) continue;
			if (board[BX][BY] == 'O') continue;
			if (board[RX][RY] == 'O') {
				cout << dist + 1;
				return 0;
			}
			if (RX == BX && RY == BY) {
				int Rdist = (abs(RX - marble.pos[0].first) + abs(RY - marble.pos[0].second));
				int Bdist = (abs(BX - marble.pos[1].first) + abs(BY - marble.pos[1].second));
				if (Rdist > Bdist) {
					RX -= dir[d]; RY -= dir[3 - d];
				}
				else {
					BX -= dir[d]; BY -= dir[3 - d];
				}
			}
			if (visited[RX*N + RY][BX*N + BY]) continue;
			visited[RX*M + RY][BX*M + BY] = true;
			q.push({ Marble(RX, RY, BX, BY), dist + 1 });
		}
	}

	cout << -1;

	return 0;
}

