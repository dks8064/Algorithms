#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007;

int N, K, d, finish;
vector<pair<int, int>> edge[11];
priority_queue < pair<int, pair<int, int>>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> d;
			if (i == j) continue;
			edge[i].push_back({ d, j });
		}
	}
	finish = (1 << N) - 1;
	int visited[1 << 11][11];
	memset(visited, 98765432, sizeof(visited));

	pq.push({ 0,{ K, 1 << K } });
	visited[1 << K][K] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int cur = pq.top().second.first;
		int visit = pq.top().second.second;
		pq.pop();

		if (visit == finish) {
			cout << dist;
			break;
		}

		for (pair<int, int> e : edge[cur]) {
			int next = (visit | (1 << e.second));
			if (visited[next][e.second] <= dist + e.first) continue;
			pq.push({ -(dist + e.first),{ e.second, next } });
			visited[next][e.second] = dist + e.first;
		}
	}


	return 0;
}