#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, k;
pair<int, int> arr[200002];

int main() {
	cin >> n >> k;
	for (int i = 0; i < 200002; i++) arr[i] = { INF, -1 };

	queue<pair<int, int>> q;
	q.push({ n, 0 });
	arr[n] = { 0, -1 };

	while (!q.empty()) {
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (now == k) {
			cout << dist << endl;
			stack<int> path;
			while (now != -1) {
				path.push(now);
				now = arr[now].second;
			}
			while (!path.empty()) {
				cout << (path.top()) << " ";
				path.pop();
			}
			break;
		}

		if (now * 2 <= 200000 && arr[now * 2].first > dist + 1) {
			q.push({ now * 2, dist + 1 });
			arr[now * 2] = { dist + 1, now };
		}
		if (now + 1 <= 100000 && arr[now + 1].first > dist + 1) {
			q.push({ now + 1, dist + 1 });
			arr[now + 1] = { dist + 1, now };
		}
		if (now - 1 >= 0 && arr[now - 1].first > dist + 1) {
			q.push({ now - 1, dist + 1 });
			arr[now - 1] = { dist + 1, now };
		}
	}


	return 0;
}