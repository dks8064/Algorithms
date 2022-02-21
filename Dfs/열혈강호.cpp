#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;

#define INF 98765432

int N, M, K, work, cnt = 0;
vector<int> employ[1001];
bool visited[1001] = { false, };
int works[1001];
vector<vector<string>> answer;

bool dfs(int n) {
	visited[n] = true;
	for (int work : employ[n]) {
		if (works[work] == 0 || (!visited[works[work]] && dfs(works[work]))) {
			works[work] = n;
			return true;
		}

	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> work;
			employ[i].push_back(work);
		}
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) cnt++;
	}

	cout << cnt;

	return 0;
}
