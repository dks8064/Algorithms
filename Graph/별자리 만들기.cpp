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

struct Star {
	int id;
	double x, y;
};

struct Edge {
	double d;
	int a, b;

	bool operator<(Edge e) {
		return d < e.d;
	}
};

int n, num = 1;
double x, y, cost = 0;
vector<Star> nodes;
vector<Edge> edges;
int parent[101];

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

	cin >> n;
	for (int i = 0; i < 101; i++) parent[i] = i;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		nodes.push_back({ num++, x, y });
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = round(100 * sqrt(pow(abs(nodes[i].x - nodes[j].x), 2) +
				pow(abs(nodes[i].y - nodes[j].y), 2))) / 100.0;
			edges.push_back({ dist, nodes[i].id, nodes[j].id });
		}
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		if (findParent(edges[i].a) == findParent(edges[i].b)) continue;

		makeUnion(edges[i].a, edges[i].b);
		cost += edges[i].d;
	}

	cout << cost;

	return 0;
}