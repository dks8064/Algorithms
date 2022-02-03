#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define INF 98765432

int n, maxValue = 0, minValue = INF;
int arr[101][101];
int dir[4] = { -1, 0, 1, 0 };

bool check(int gap) {
	bool visited[101][101];
	queue<pair<int, int>> q;

	for (int i = minValue; i <= maxValue - gap; i++) {
		for (int a = 0; a<n; a++) {
			for (int b = 0; b<n; b++) {
				if (arr[a][b] >= i && arr[a][b] <= (i + gap)) visited[a][b] = false;
				else visited[a][b] = true;
			}
		}

		if (visited[0][0]) continue;
		q.push({ 0, 0 });
		visited[0][0] = true;

		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();

			if (x == n - 1 && y == n - 1) return true;

			for (int d = 0; d<4; d++) {
				int dx = x + dir[d], dy = y + dir[3 - d];
				if (dx<0 || dy<0 || dx >= n || dy >= n) continue;
				if (visited[dx][dy]) continue;
				visited[dx][dy] = true;
				q.push({ dx, dy });
			}
		}
	}

	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cin >> arr[i][j];
			maxValue = max(maxValue, arr[i][j]);
			minValue = min(minValue, arr[i][j]);
		}
	}

	int left = 0, right = maxValue - minValue;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) right = mid - 1;
		else left = mid + 1;
	}

	cout << right + 1;

	return 0;
}