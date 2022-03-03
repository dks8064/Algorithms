#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, A, B;
vector<int> child[32001];
int level[32001];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		child[A].push_back(B);
		level[B]++;
	}

	priority_queue<int> pq;
	for (int i = 1; i <= N; i++) {
		if (level[i] == 0) pq.push(-i);
	}

	while (!pq.empty()) {
		int now = -pq.top();
		pq.pop();

		cout << now << " ";

		for (int next : child[now]) {
			level[next]--;
			if (level[next] == 0) pq.push(-next);
		}
	}

	return 0;
}