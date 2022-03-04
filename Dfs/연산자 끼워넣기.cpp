#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N;
int number[20];
int operate[4];
int maxVal = INT_MIN, minVal = INT_MAX;

int cal(int x, int y, int o) {
	switch (o) {
	case 0: return x + y;
	case 1: return x - y;
	case 2: return x * y;
	case 3: return x / y;
	}
}

void dfs(int start, int num) {
	if (start == N - 1) {
		maxVal = max(maxVal, num);
		minVal = min(minVal, num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operate[i] > 0) {
			operate[i]--;
			dfs(start + 1, cal(num, number[start + 1], i));
			operate[i]++;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> number[i];
	for (int i = 0; i < 4; i++) cin >> operate[i];

	dfs(0, number[0]);

	cout << maxVal << endl << minVal;

	return 0;
}