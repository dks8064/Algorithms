#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define INF 98765432

int n, m;
char arr[1001][1001];
int visited[1001][1001];
int dir[4] = { -1, 0, 1, 0 };
map<int, int> idMap;

void setCount(int x, int y, int id) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = id;
	int cnt = 0;

	while (!q.empty()) {
		int qx = q.front().first, qy = q.front().second;
		q.pop();
		cnt++;

		for (int d = 0; d<4; d++) {
			int dx = qx + dir[d], dy = qy + dir[3 - d];
			if (dx<0 || dy<0 || dx >= n || dy >= m) continue;
			if (arr[dx][dy] == '1' || visited[dx][dy]>0) continue;
			visited[dx][dy] = id;
			q.push({ dx, dy });
		}
	}

	idMap[id] = cnt;
}

int setTotal(int x, int y) {
	set<int> idSet;

	for (int d = 0; d<4; d++) {
		int dx = x + dir[d], dy = y + dir[3 - d];
		if (dx<0 || dy<0 || dx >= n || dy >= m) continue;
		idSet.insert(visited[dx][dy]);
	}

	int total = 1;
	for (int num : idSet) {
		total = (total + idMap[num]) % 10;
	}

	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i<n; i++) cin >> arr[i];

	fill(&visited[0][0], &visited[1000][1001], 0);
	int id = 1;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (arr[i][j] == '0' && visited[i][j] == 0) setCount(i, j, id++);
		}
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (arr[i][j] == '1') cout << setTotal(i, j);
			else cout << 0;
		}
		cout << '\n';
	}

	return 0;
}