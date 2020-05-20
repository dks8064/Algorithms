#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

/**
* https://www.acmicpc.net/problem/1697
* Bfs
*/


queue<pair<int, int>> q;

int main() {

	int s, e;
	int n = 1000001;
	bool visit[1000001] = { false };

	cin >> s >> e;
	q.push(make_pair(s, 0));
	visit[s] = true;
	while (!q.empty()) {
		pair<int, int> xy = q.front();
		if (xy.first == e) {
			n = min(n, xy.second);
		}
		else if (xy.second >= n) {
		}
		else if (xy.first < e) {
			if (!visit[xy.first + 1]) {
				q.push(make_pair(xy.first + 1, xy.second + 1));
				visit[xy.first + 1] = true;
			}
			if (!visit[xy.first * 2]) {
				q.push(make_pair(xy.first * 2, xy.second + 1));
				visit[xy.first * 2] = true;
			}
			if (!visit[xy.first - 1]) {
				q.push(make_pair(xy.first - 1, xy.second + 1));
				visit[xy.first - 1] = true;
			}
		}
		else {
			if (!visit[xy.first - 1]) {
				q.push(make_pair(xy.first - 1, xy.second + 1));
				visit[xy.first - 1] = true;
			}
		}
		q.pop();
	}
	cout << n;

	return 0;
}