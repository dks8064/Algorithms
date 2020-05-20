#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/**
* https://www.acmicpc.net/problem/5427
*/

int T, W, H;
char map[1001][1001];
int dir[4] = { 1,-1,0,0 };
bool flag = false;
queue<pair<pair<int, int>, int>> q;
queue<pair<pair<int, int>, int>> fire;

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> H >> W;
		for (int w = 0; w < W; w++) {
			for (int h = 0; h < H; h++) {
				cin >> map[w][h];
				if (map[w][h] == '@') q.push(make_pair(make_pair(w, h), 1));
				else if (map[w][h] == '*') {
					fire.push(make_pair(make_pair(w, h), 1));
					map[w][h] = '#';
				}
			}
		}

		while (true) {
			if (q.empty()) {
				cout << "IMPOSSIBLE" << endl;
				while (!q.empty()) q.pop();
				while (!fire.empty()) fire.pop();
				break;
			}
			int sec = q.front().second;
			while (!q.empty()) {
				if (q.front().second != sec) break;
				int x = q.front().first.first;
				int y = q.front().first.second;
				q.pop();
				if (map[x][y] == '#') continue;
				for (int i = 0; i < 4; i++) {
					if (x + dir[i]<-1 || x + dir[i]>W || y + dir[3 - i]<-1 || y + dir[3 - i]>H) continue;
					if (x + dir[i] == -1 || x + dir[i] == W || y + dir[3 - i] == -1 || y + dir[3 - i] == H) {
						flag = true;
						break;
					}
					if (map[x + dir[i]][y + dir[3 - i]] == '#') continue;
					if (map[x + dir[i]][y + dir[3 - i]] == '@') continue;
					map[x + dir[i]][y + dir[3 - i]] = '@';
					q.push(make_pair(make_pair(x + dir[i], y + dir[3 - i]), sec + 1));
				}
				if (flag) break;
			}

			if (flag) {
				cout << sec << endl;
				while (!q.empty()) q.pop();
				while (!fire.empty()) fire.pop();
				flag = false;
				break;
			}

			while (!fire.empty()) {
				if (fire.front().second != sec) break;
				int x = fire.front().first.first;
				int y = fire.front().first.second;
				fire.pop();
				for (int i = 0; i < 4; i++) {
					if (x + dir[i]<0 || x + dir[i]>W - 1 || y + dir[3 - i]<0 || y + dir[3 - i]>H - 1) continue;
					if (map[x + dir[i]][y + dir[3 - i]] == '#') continue;
					map[x + dir[i]][y + dir[3 - i]] = '#';
					fire.push(make_pair(make_pair(x + dir[i], y + dir[3 - i]), sec + 1));
				}
			}

		}
	}

	return 0;
}