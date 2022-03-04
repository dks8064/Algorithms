#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, number;
int card[500001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> card[i];
	sort(card, card + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> number;
		int num = *lower_bound(card, card + N, number);
		if (num == number) cout << 1 << " ";
		else cout << 0 << " ";
	}

	return 0;
}