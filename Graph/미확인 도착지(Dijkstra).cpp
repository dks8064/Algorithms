#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 98765432

int T, n, m, t, s, g, h, a, b, d, x;
int path[2001][2001];
vector<int> v;

void destination() {
	int dist[2001][2001];
	fill(&dist[0][0], &dist[2000][2001], INF);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				path[i][k] = min(path[i][k], path[i][j]+ path[j][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << v[i] << " ";
}

int main() {
	cin >> T;
	for (int k = 0; k<T; k++) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		fill(&path[0][0], &path[2000][2001], INF);
		v.clear();
		for (int i = 0; i<m; i++) {
			cin >> a >> b >> d;
			path[a][b] = d;
			path[b][a] = d;
		}
		for (int i = 0; i<t; i++) {
			cin >> x;
			v.push_back(x);
		}
		destination();
		sort(v.begin(), v.end());
		for (int i = 0; i<v.size(); i++) cout << v[i] << " ";
		cout << endl;
	}

	return 0;
}