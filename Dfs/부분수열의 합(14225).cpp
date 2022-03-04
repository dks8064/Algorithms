#include <iostream>
#include <algorithm>
using namespace std;

int N;
int S[20];
bool arr[2000001] = { false, };

void dfs(int start, int num) {
	arr[num] = true;
	if (start == N - 1) return;

	for (int i = start + 1; i < N; i++) {
		dfs(i, num + S[i]);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];

	dfs(-1, 0);

	for (int i = 1; i <= 2000000; i++) {
		if (arr[i]) continue;
		cout << i;
		break;
	}

	return 0;
}