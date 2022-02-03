#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321

int n, m, a, b, c;
int path[101][101];

int main() {
	fill(&path[0][0], &path[100][101], INF);
	cin >> n >> m;
	for (int i = 0; i<m; i++) {
		cin >> a >> b >> c;
		path[a][b] = min(path[a][b], c);
		path[a][a] = path[b][b] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				path[j][k] = min(path[j][k], path[j][i] + path[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << ((path[i][j] == INF) ? 0 : path[i][j]) << " ";
		}
		cout << endl;
	}

	return 0;
}