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

struct Tunnel {
	int c;
	int x, y;

	bool operator<(Tunnel t) {
		return c < t.c;
	}
};

int N, X, Y, Z;
long long cost = 0;
int parent[100001];
vector<Tunnel> edges;
vector<pair<int, int>> x;
vector<pair<int, int>> y;
vector<pair<int, int>> z;

int findParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}

void makeUnion(int x, int y) {
	parent[findParent(x)] = findParent(y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y >> Z;
		x.push_back({ X, i });
		y.push_back({ Y, i });
		z.push_back({ Z, i });
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	for (int i = 1; i < N; i++) {
		edges.push_back({ x[i].first - x[i - 1].first, x[i - 1].second, x[i].second });
		edges.push_back({ y[i].first - y[i - 1].first, y[i - 1].second, y[i].second });
		edges.push_back({ z[i].first - z[i - 1].first, z[i - 1].second, z[i].second });
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		if (findParent(edges[i].x) == findParent(edges[i].y)) continue;
		makeUnion(edges[i].x, edges[i].y);
		cost += edges[i].c;
	}

	cout << cost;

	return 0;
}