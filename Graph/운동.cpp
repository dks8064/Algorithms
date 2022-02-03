#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int N, V, E, a, b, c;
int dist[401][401];
int answer = INF;

int main() {
	fill(&dist[0][0], &dist[400][401], INF);
	cin >> V >> E;
	for (int i = 0; i<E; i++) {
		cin >> a >> b >> c;
		dist[a][b] = c;
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (dist[i][j] != INF && dist[j][i] != INF) answer = min(answer, dist[i][j] + dist[j][i]);
		}
	}

	if (answer == INF) cout << -1;
	else cout << answer;

	return 0;
}