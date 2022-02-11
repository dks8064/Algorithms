#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define INF 987654321

int G, P, g;
int parent[100001];

int findParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}

bool makeUnion(int x) {
	x = findParent(x);
	if (x == 0) return false;
	int y = findParent(x - 1);
	parent[x] = y;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = -1;
	for (int i = 0; i < 100001; i++) parent[i] = i;

	cin >> G >> P;
	for (int i = 0; i < P; i++) {
		cin >> g;
		if (answer != -1) continue;
		if (!makeUnion(g)) answer = i;
	}

	cout << ((answer == -1) ? P : answer);

	return 0;
}