#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 987654321

long long n, k, q, a, b;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k >> q;

	for (int i = 0; i < q; i++) {
		cin >> a >> b;

		long long x = max(a, b), y = min(a, b), xHeight = 1, yHeight = 1;

		if (k == 1) { cout << (x - y) << '\n'; continue; }
		while (((pow(k, xHeight) - 1) / (k - 1)) < x) xHeight++;
		while (((pow(k, yHeight) - 1) / (k - 1)) < y) yHeight++;

		long long xSeq = x - ((pow(k, (xHeight - 1)) - 1) / (k - 1)) - 1;
		long long ySeq = y - ((pow(k, (yHeight - 1)) - 1) / (k - 1)) - 1;

		long long low = yHeight, high = xHeight;
		long long path = xHeight - yHeight;
		while (low != high) {
			xSeq = (xSeq == 0) ? 0 : xSeq / k;
			high--;
		}
		while (xSeq != ySeq) {
			xSeq = (xSeq == 0) ? 0 : xSeq / k;
			ySeq = (ySeq == 0) ? 0 : ySeq / k;
			path += 2;
		}
		cout << path << '\n';
	}


	return 0;
}