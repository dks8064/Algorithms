#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, C, answer = 0;
int house[200001];

bool isPossible(int dist) {
	int cur = house[0], count = 0;
	for (int i = 1; i < N; i++) {
		if (house[i] - cur >= dist) {
			count++;
			cur = house[i];
		}
		if (count == C - 1) return true;
	}
	return false;
}

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) cin >> house[i];
	sort(house, house + N);

	int left = 0, right = house[N - 1] - house[0];
	while (left <= right) {
		int mid = (left + right) / 2;
		if (isPossible(mid)) left = mid + 1;
		else right = mid - 1;
	}

	cout << right;


	return 0;
}