#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321

struct stone {
	int x, y, z;
};

int total;
bool visited[501][1501];

bool check(int a, int b, int c) {
	queue<stone> q;
	q.push({ a, b, c });
	visited[a][b] = true;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().z;
		q.pop();

		if (x == y && y == z) return true;

		int x1 = x + x, y1 = y, z1 = z - x;
		int x2 = x + x, y2 = y - x, z2 = z;
		int x3 = x, y3 = y + y, z3 = z - y;

		int minT = min(x1, min(y1, z1));
		int maxT = max(x1, max(y1, z1));
		if (z1 > 0) {
			int midT = total - minT - maxT;
			if (!visited[minT][midT]) {
				q.push({ minT, midT, maxT });
				visited[minT][midT] = true;
			}
		}

		minT = min(x2, min(y2, z2));
		maxT = max(x2, max(y2, z2));
		if (y2 > 0) {
			int midT = total - minT - maxT;
			if (!visited[minT][midT]) {
				q.push({ minT, midT, maxT });
				visited[minT][midT] = true;
			}
		}

		minT = min(x3, min(y3, z3));
		maxT = max(x3, max(y3, z3));
		if (z3 > 0) {
			int midT = total - minT - maxT;
			if (!visited[minT][midT]) {
				q.push({ minT, midT, maxT });
				visited[minT][midT] = true;
			}
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	total = (a + b + c);

	int maxv = max(a, max(b, c));
	int minv = min(a, min(b, c));
	int midv = total - maxv - minv;

	if (check(minv, midv, maxv)) cout << 1;
	else cout << 0;


	return 0;
}