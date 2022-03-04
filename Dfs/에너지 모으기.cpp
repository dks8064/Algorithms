#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer = 0;
int marble[10];
bool isUse[10] = { false, };

void dfs(int count, int energy) {
	if (count == N - 2) {
		answer = max(answer, energy);
		return;
	}

	for (int i = 1; i < N - 1; i++) {
		if (isUse[i]) continue;
		isUse[i] = true;
		int highIdx = i, lowIdx = i;
		while (isUse[highIdx]) highIdx++;
		while (isUse[lowIdx]) lowIdx--;
		dfs(count + 1, energy + marble[highIdx] * marble[lowIdx]);
		isUse[i] = false;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> marble[i];

	dfs(0, 0);

	cout << answer;

	return 0;
}