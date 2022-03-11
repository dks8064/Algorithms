#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N, C, X, Y, answer = 0, cnt = 0;
vector<pair<int, int>> nodes;
vector<pair<int, pair<int, int>>> edges;
int parent[2001];

int findParent(int n) {
	if (parent[n] == n) return n;
	return parent[n] = findParent(parent[n]);
}

void Union(int x, int y, int c) {
	x = findParent(x);
	y = findParent(y);
	if (x == y) return;
	answer += c;
	cnt++;
	parent[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		nodes.push_back({ X, Y });
		parent[i] = i;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int dist = pow(nodes[i].first - nodes[j].first, 2) + pow(nodes[i].second - nodes[j].second, 2);
			if (dist >= C) edges.push_back({ dist ,{ i, j } });
		}
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		int x = edges[i].second.first, y = edges[i].second.second;
		Union(x, y, edges[i].first);
	}

	cout << ((cnt == N - 1) ? answer : -1);

	return 0;
}

