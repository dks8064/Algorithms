#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m, temp;
bool edge[201][201];
int id[201];
vector<int> path;

void setId(int now, int curId) {
	id[now] = curId;

	for (int i = 1; i <= n; i++) {
		if (edge[now][i] && id[i] == 0) setId(i, curId);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> edge[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		path.push_back(temp);
	}

	int curId = 1;
	for (int i = 1; i <= n; i++) {
		if (id[i] == 0) setId(i, curId++);
	}

	bool flag = true;
	for (int i = 1; i < path.size(); i++) {
		if (id[path[i]] != id[path[0]]) {
			flag = false;
			break;
		}
	}

	if (flag) cout << "YES";
	else cout << "NO";

	return 0;
}