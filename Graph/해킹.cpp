#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define INF 987654321

int T, n, d, c, a, b, s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		vector<pair<int, int>> computer[10001];
		cin >> n >> d >> c;

		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			computer[b].push_back({ a, s });
		}

		int dist[10001];
		fill(&dist[0], &dist[10001], INF);
		priority_queue<pair<int, int>> q;
		q.push({ 0, c });
		dist[c] = 0;
		int count = 1, time = 0;
		while (!q.empty()) {
			int t = -q.top().first;
			int node = q.top().second;
			if (dist[node] >= t) time = t;
			q.pop();

			for (pair<int, int> p : computer[node]) {
				if (dist[p.first] == INF) count++;
				if (dist[p.first] > t + p.second) {
					q.push({ -(t + p.second), p.first });
					dist[p.first] = t + p.second;
				}
			}
		}
		cout << count << " " << time << '\n';
	}

	return 0;
}