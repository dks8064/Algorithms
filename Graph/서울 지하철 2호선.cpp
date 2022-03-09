#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;


int N, X, Y;
vector<int> edge[3001];
bool cycle[3001] = { false, };
bool visited[3001] = { false, };
int parent[3001];
bool isCycle = false;
int dist[3001];

void findCycle(int node) {
	visited[node] = true;
	for (int e : edge[node]) {
		if (isCycle) return;
		if (visited[e]) {
			if (parent[node] == e) continue;
			isCycle = true;
			cycle[node] = true;
			while (node != e) {
				cycle[parent[node]] = true;
				node = parent[node];
			}
		}
		else {
			parent[e] = node;
			findCycle(e);
		}
	}

}

void bfs() {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++) {
		if (cycle[i]) {
			visited[i] = true;
			q.push({ i, 0 });
		}
	}

	while (!q.empty()) {
		int node = q.front().first;
		int d = q.front().second;
		q.pop();

		for (int e : edge[node]) {
			if (visited[e]) continue;
			dist[e] = d + 1;
			visited[e] = true;
			q.push({ e, d + 1 });
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		edge[X].push_back(Y);
		edge[Y].push_back(X);
	}

	findCycle(1);
	bfs();

	for (int i = 1; i <= N; i++) cout << dist[i] << " ";

	return 0;
}