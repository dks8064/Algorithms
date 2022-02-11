#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m, a, b, c, startNode, endNode;
vector<pair<int, int>> graph[1001];
pair<int, int> dist[1001];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
	cin >> startNode >> endNode;

	for (int i = 1; i <= n; i++) dist[i] = { INF, -1 };

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, startNode });
	dist[startNode] = { 0, -1 };

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (now == endNode) {
			cout << cost << endl;
			stack<int> path;
			while (now != -1) {
				path.push(now);
				now = dist[now].second;
			}
			cout << (path.size()) << endl;
			while (!path.empty()) {
				cout << (path.top()) << " ";
				path.pop();
			}
			break;
		}

		for (pair<int, int> p : graph[now]) {
			if (dist[p.first].first > (cost + p.second)) {
				pq.push({ -(cost + p.second), p.first });
				dist[p.first] = { (cost + p.second), now };
			}
		}
	}

	return 0;
}