#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 98765432

int N, M, A, B, C;
int bus[501];
long long dist[501];
vector<pair<int, int>> path[501];

int main() {
	cin >> N >> M;
	for (int i = 0; i<M; i++) {
		cin >> A >> B >> C;
		path[A].push_back({ B, C });
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}


	bool check = false;
	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k<path[j].size(); k++) {
				int des = path[j][k].first, cost = path[j][k].second;
				if (dist[j] != INF && dist[des]>dist[j] + cost) {
					dist[des] = dist[j] + cost;
					if (i == N) { check = true; break; }
				}
			}
		}
	}


	if (check) cout << -1 << endl;
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) cout << -1 << endl;
			else   cout << dist[i] << endl;
		}
	}


	return 0;
}