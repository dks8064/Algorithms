#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 987654321

int n, m, x, y;
int parent[100001][20];
int dist[100001];
vector<int> node[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}

	stack<pair<int, int>> path;
	path.push({ 1, 0 });
	parent[1][0] = 1;
	while (!path.empty()) {
		int cur = path.top().first;
		int cost = path.top().second;
		path.pop();

		dist[cur] = cost;
		for (int next : node[cur]) {
			if (parent[next][0] == 0) {
				parent[next][0] = cur;
				path.push({ next, cost + 1 });
			}
		}
	}

	for (int k = 1; k < 20; k++) {
		for (int i = 1; i <= n; i++) {
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;

		if (dist[x] > dist[y]) {
			int temp = y;
			y = x;
			x = temp;
		}

		int diff = dist[y] - dist[x];
		for (int k = 0; diff > 0; k++) {
			if (diff % 2 == 1) y = parent[y][k];
			diff /= 2;
		}

		for (int k = 19; k >= 0; k--) {
			if (parent[x][k] != parent[y][k]) {
				x = parent[x][k];
				y = parent[y][k];
			}
		}

		if (x != y) cout << parent[x][0] << '\n';
		else cout << x << '\n';
	}


	return 0;
}