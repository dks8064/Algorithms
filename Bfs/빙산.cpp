#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[301][301];
bool visit[301][301];
int dir[4] = { 1, -1, 0, 0 };

bool check(queue<pair<pair<int, int>, pair<int, int>>> q) {
	bool check[301][301];
	queue<pair<int, int>> visit;
	int n = q.front().first.first;
	int m = q.front().first.second;
	visit.push(make_pair(n, m));
	check[n][m] = true;
	int count = 0;
	while (!visit.empty()) {
		count++;
		int x = visit.front().first;
		int y = visit.front().second;
		visit.pop();
		for (int i = 0; i<4; i++) {
			if (x + dir[i]>N - 1 || x + dir[i]<0 || y + dir[3 - i]>M - 1 || y + dir[3 - i]<0) continue;
			if (check[x + dir[i]][y + dir[3 - i]]) continue;
			if (map[x + dir[i]][y + dir[3 - i]] > 0) {
				visit.push(make_pair(x + dir[i], y + dir[3 - i]));
				check[x + dir[i]][y + dir[3 - i]] = true;
			}
		}
	}
	if (count == q.size()) return false;
	return true;
}

int main() {
	cin >> N >> M;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	for (int n = 0; n<N; n++) {
		for (int m = 0; m<M; m++) {
			cin >> map[n][m];
			if (map[n][m] != 0) q.push(make_pair(make_pair(n, m), make_pair(map[n][m], 0)));
		}
	}

	int sec = 0;
	queue<pair<int, int>> del;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int age = q.front().second.first;
		if (sec != q.front().second.second) {
			while (!del.empty()) {
				map[del.front().first][del.front().second] = 0;
				del.pop();
			}
			if (check(q)) {
				cout << q.front().second.second << endl;
				break;
			}
			sec = q.front().second.second;
		}
		q.pop();
		for (int i = 0; i<4; i++) {
			if (x + dir[i]>N - 1 || x + dir[i]<0 || y + dir[3 - i]>M - 1 || y + dir[3 - i]<0) continue;
			if (map[x + dir[i]][y + dir[3 - i]] == 0) age--;
		}
		if (age > 0) q.push(make_pair(make_pair(x, y), make_pair(age, sec + 1)));
		else del.push(make_pair(x, y));
	}

	if (q.empty()) cout << "0" << endl;

	return 0;
}