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

struct God {
	double c;
	int x, y;

	bool operator<(God n) {
		return c < n.c;
	}
};

int N, M, X, Y;
double cost = 0;
int parent[10001];
vector<God> nodes;
vector<pair<int, int>> gods;

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

	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		gods.push_back({ X, Y });
	}
	for (int i = 0; i < M; i++) {
		cin >> X >> Y;
		makeUnion(X, Y);
	}
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (findParent(i) == findParent(j)) continue;
			double dist = sqrt(pow(abs(gods[i - 1].first - gods[j - 1].first), 2) + pow(abs(gods[i - 1].second - gods[j - 1].second), 2));
			nodes.push_back({ dist, i, j });
		}
	}

	sort(nodes.begin(), nodes.end());

	for (int i = 0; i < nodes.size(); i++) {
		if (findParent(nodes[i].x) == findParent(nodes[i].y)) continue;
		makeUnion(nodes[i].x, nodes[i].y);
		cost += nodes[i].c;
	}

	cout << fixed;
	cout.precision(2);
	cout << cost;

	return 0;
}