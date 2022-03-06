#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Arr {
	int num;
	int index;
};

bool cmp(const Arr &a, const Arr &b) {
	return a.num < b.num;
}

int main() {
	int n;
	cin >> n;
	vector<Arr> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].num;
		a[i].index = i;
	}

	stable_sort(a.begin(), a.end(), cmp);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < a[i].index - i) {
			ans = a[i].index - i;
		}
	}
	cout << ans + 1 << '\n';

	return 0;
}