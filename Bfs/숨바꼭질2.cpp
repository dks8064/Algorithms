#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

/**
* https://www.acmicpc.net/problem/12851
*/

queue<pair<int, int>> q;

int main() {

	int s, e, count = 1;
	int n = 200002;
	int visit[200002];

	cin >> s >> e;
	fill(visit, visit + 200002, -1);
	q.push(make_pair(s, 0));
	visit[s] = 0;
	while (!q.empty()) {
		pair<int, int> xy = q.front();
		if (xy.first == e) {
			if (n == xy.second) {
				count++;
			}
			n = min(n, xy.second);
		}
		else if (xy.second >= n) {
		}
		else if (xy.first < e) {
			if ((visit[(xy.first + 1)] >= xy.second + 1) || (visit[xy.first + 1] == -1)) {
				q.push(make_pair(xy.first + 1, xy.second + 1));
				visit[(xy.first + 1)] = xy.second + 1;
			}
			if ((visit[(xy.first * 2)] >= xy.second + 1) || (visit[xy.first * 2] == -1)) {
				q.push(make_pair(xy.first * 2, xy.second + 1));
				visit[(xy.first * 2)] = xy.second + 1;
			}
			if (xy.first > 0) {
				if ((visit[(xy.first - 1)] >= xy.second + 1) || (visit[xy.first - 1] == -1)) {
					q.push(make_pair(xy.first - 1, xy.second + 1));
					visit[xy.first - 1] = xy.second + 1;
				}
			}
		}
		else {
			if (xy.first > 0) {
				if ((visit[xy.first - 1] >= xy.second + 1) || (visit[xy.first - 1] == -1)) {
					q.push(make_pair(xy.first - 1, xy.second + 1));
					visit[xy.first - 1] = xy.second + 1;
				}
			}
		}
		q.pop();
	}
	cout << n << endl << count;

	return 0;
}