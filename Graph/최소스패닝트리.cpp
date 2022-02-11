#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define INF 987654321

struct Node {
	int c, x, y;

	bool operator<(Node n) {
		return c < n.c;
	}
};

int V, E, A, B, C;
long long cost = 0;
int parent[10001];
vector<Node> nodes;

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

	cin >> V >> E;
	for (int i = 1; i <= V; i++) parent[i] = i;
	for (int e = 0; e < E; e++) {
		cin >> A >> B >> C;
		nodes.push_back({ C, A, B });
	}

	sort(nodes.begin(), nodes.end());

	for (int i = 0; i < nodes.size(); i++) {
		if (findParent(nodes[i].x) == findParent(nodes[i].y)) continue;

		cost += nodes[i].c;
		makeUnion(nodes[i].x, nodes[i].y);
	}

	cout << cost;

	return 0;
}