#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

/**
* https://www.algospot.com/judge/problem/read/FENCE
*/

vector<int> fences;

int solve(int s, int e) {
	if (s == e) return fences[s];
	int mid = (s + e) / 2;
	int ans = max(solve(s, mid), solve(mid + 1, e));
	int low = mid;
	int high = mid + 1;
	int minHeight = min(fences[low], fences[high]);
	ans = max(ans, minHeight * 2);
	while (low > s || high < e) {
		if (high < e && ((low == s) || (fences[low - 1] < fences[high + 1]))) {
			high++;
			minHeight = min(minHeight, fences[high]);
		}
		else {
			low = low - 1;
			minHeight = min(minHeight, fences[low]);
		}
		ans = max(ans, (high - low + 1) * minHeight);
	}
	return ans;
}

int main() {

	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		int N;
		cin >> N;
		int temp;
		for (int j = 0; j < N; j++) {
			cin >> temp;
			fences.push_back(temp);
		}
		cout << solve(0, fences.size() - 1) << endl;
		fences.clear();
	}
	return 0;
}