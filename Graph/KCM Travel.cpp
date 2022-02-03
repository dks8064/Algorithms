#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int T, N, M, K, u, v, c, d;

int main() {
	cin >> T;
	for (int t = 0; t<T; t++) {
		vector<pair<int, pair<int, int>>> path[101];
		int dist[101][10001];
		fill(&dist[0][0], &dist[100][10001], INF);

		cin >> N >> M >> K;
		for (int i = 0; i<K; i++) {
			cin >> u >> v >> c >> d;
			path[u].push_back({ v,{ c, d } });
		}

		priority_queue<pair<pair<int, int>, int>> q;
		q.push({ { 0, 0 }, 1 });
		dist[1][0] = 0;

		while (!q.empty()) {
			int cost = -q.top().first.first;
			int money = q.top().first.second;
			int node = q.top().second;
			q.pop();

			for (pair<int, pair<int, int>> p : path[node]) {
				int nextMoney = p.second.first + money;
				if (nextMoney>M) continue;
				int nextCost = p.second.second + cost, nextNode = p.first;
				if (dist[nextNode][nextMoney] > nextCost) {
					dist[nextNode][nextMoney] = nextCost;
					q.push({ { -nextCost, p.second.first + money }, nextNode });
				}
			}
		}

		int answer = INF;
		for (int i = 0; i <= M; i++) answer = min(answer, dist[N][i]);
		if (answer == INF) cout << "Poor KCM" << endl;
		else cout << answer << endl;
	}

	return 0;
}