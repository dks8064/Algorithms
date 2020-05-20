#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/**
* https://www.acmicpc.net/problem/2589
*/

int dir[4] = { 1,-1,0,0 };

int main() {
	int answer = 0;
	int col, row;
	char** map;
	bool** visit;
	int** dist;
	cin >> col >> row;
	map = new char* [col];
	visit = new bool* [col];
	dist = new int* [col];
	for (int i = 0; i < col; i++) {
		map[i] = new char[row];
		visit[i] = new bool[row];
		dist[i] = new int[row];
		for (int j = 0; j < row; j++) {
			cin >> map[i][j];
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] != 'L') continue;
			q.push(make_pair(i, j));
			visit[i][j] = true;
			dist[i][j] = 0;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				for (int k = 0; k < 4; k++) {
					if (((x + dir[k]) < 0) || ((x + dir[k]) > (col - 1)) ||
						((y + dir[3 - k]) < 0) || ((y + dir[3 - k]) > (row - 1))) continue;
					if (!visit[x + dir[k]][y + dir[3 - k]] && map[x + dir[k]][y + dir[3 - k]] == 'L') {
						q.push(make_pair(x + dir[k], y + dir[3 - k]));
						visit[x + dir[k]][y + dir[3 - k]] = true;
						dist[x + dir[k]][y + dir[3 - k]] = dist[x][y] + 1;
						answer = max(answer, dist[x][y] + 1);
					}
				}
				q.pop();
			}
			for (int a = 0; a < col; a++) {
				for (int b = 0; b < row; b++) {
					visit[a][b] = false;
					dist[a][b] = 0;
				}
			}
		}
	}

	cout << answer;

	return 0;
}