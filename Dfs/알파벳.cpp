#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
* https://www.acmicpc.net/problem/1987
*/

int R, C;
char** map;
int dir[4] = { 1,-1,0,0 };
bool visit[26];
vector<pair<int, int>> v;

int func() {
	int x = v.back().first;
	int y = v.back().second;
	int ans = v.size();
	for (int i = 0; i < 4; i++) {
		if (x + dir[i] < 0 || x + dir[i] > R - 1 || y + dir[3 - i] < 0 || y + dir[3 - i] > C - 1) continue;
		if (visit[map[x + dir[i]][y + dir[3 - i]] - 65]) continue;
		if (find(v.begin(), v.end(), make_pair(x + dir[i], y + dir[3 - i])) != v.end()) continue;
		v.push_back(make_pair(x + dir[i], y + dir[3 - i]));
		visit[map[x + dir[i]][y + dir[3 - i]] - 65] = true;
		ans = max(ans, func());
		visit[map[x + dir[i]][y + dir[3 - i]] - 65] = false;
		v.pop_back();
	}

	return ans;
}

int main() {
	cin >> R >> C;
	map = new char* [R];
	for (int r = 0; r < R; r++) {
		map[r] = new char[C];
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
		}
	}

	v.push_back(make_pair(0, 0));
	visit[map[0][0] - 65] = true;
	cout << func();

	return 0;
}