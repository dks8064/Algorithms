#include <iostream>
#include <queue>
using namespace std;

char map[1001][1001];
bool visit[1001][1001][2];
int dir[4] = { 1, -1, 0, 0 };

int main() {
	// your code goes here
	int N, M;
	cin >> N >> M;
	for (int n = 0; n<N; n++) {
		for (int m = 0; m<M; m++) {
			cin >> map[n][m];
		}
	}

	queue<pair<pair<int, int>, pair<int, bool>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(1, false)));
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int sec = q.front().second.first;
		bool flag = q.front().second.second;
		if (x == N - 1 && y == M - 1) {
			cout << sec << endl;
			break;
		}
		q.pop();
		if (x>N - 1 || x<0 || y>M - 1 || y<0) continue;
		if (visit[x][y][flag]) continue;
		if (map[x][y] == '1') {
			if (flag) continue;
			flag = true;
		}
		visit[x][y][flag] = true;
		for (int i = 0; i<4; i++) {
			q.push(make_pair(make_pair(x + dir[i], y + dir[3 - i]), make_pair(sec + 1, flag)));
		}

	}

	if (q.empty()) cout << "-1" << endl;

	return 0;
}