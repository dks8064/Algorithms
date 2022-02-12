#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 987654321

struct dummy {
	int a, b, c;
};

int N, A, B, C;
dummy arr[20001];

long long underCount(long long x) {
	if (x <= 0) return 0;

	long long sum = 0;
	for (int i = 0; i < N; i++) {
		long long k = min((long long)arr[i].b, x) - arr[i].a;
		sum += ((k < 0) ? 0 : (k / arr[i].c) + 1);
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> A >> B >> C;
		arr[n] = { A, B, C };
	}

	long long left = 0, right = 2147483647;

	long long answer = -1;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (underCount(mid) % 2 == 0) left = mid + 1;
		else {
			answer = mid;
			right = mid - 1;
		}
	}

	if (answer == -1) cout << "NOTHING";
	else cout << answer << " " << (underCount(answer) - underCount(answer - 1));

	return 0;
}