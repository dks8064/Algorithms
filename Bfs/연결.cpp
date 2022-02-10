#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define INF 987654321

struct Line {
	int x, y;
	vector<pair<int, int>> path;
};

int n, m, sn1, sm1, en1, em1, sn2, sm2, en2, em2;
bool visited[101][101];
int dir[4] = { -1, 0, 1, 0 };

int bfs(int sx1, int sy1, int ex1, int ey1, int sx2, int sy2, int ex2, int ey2) {
	fill(&visited[0][0], &visited[100][101], false);
	int total = 0;
	queue<Line> q;
	q.push({ sx1, sy1,{ make_pair(sx1, sy1) } });
	visited[sx1][sy1] = true;
	visited[sx2][sy2] = true;
	visited[ex2][ey2] = true;

	while (!q.empty()) {
		Line line = q.front();
		q.pop();

		if (total == 0 && line.x == ex1 && line.y == ey1) {
			total += line.path.size() - 1;
			while (!q.empty()) q.pop();
			fill(&visited[0][0], &visited[100][101], false);
			for (pair<int, int> p : line.path) visited[p.first][p.second] = true;
			q.push({ sx2, sy2,{ make_pair(sx2, sy2) } });
			visited[sx2][sy2] = true;
			continue;
		}

		if (total != 0 && line.x == ex2 && line.y == ey2) return total + line.path.size() - 1;

		for (int d = 0; d < 4; d++) {
			int dx = line.x + dir[d], dy = line.y + dir[3 - d];
			if (dx <0 || dy<0 || dx>n || dy>m) continue;
			if (visited[dx][dy]) continue;
			line.path.push_back({ dx, dy });
			q.push({ dx, dy, line.path });
			line.path.pop_back();
			visited[dx][dy] = true;
		}
	}

	return INF;
}

int main() {
	cin >> n >> m;
	cin >> sn1 >> sm1 >> en1 >> em1;
	cin >> sn2 >> sm2 >> en2 >> em2;

	int ret = INF;
	ret = min(bfs(sn1, sm1, en1, em1, sn2, sm2, en2, em2),
		bfs(sn2, sm2, en2, em2, sn1, sm1, en1, em1));

	if (ret == INF) cout << "IMPOSSIBLE";
	else cout << ret;

	return 0;
}