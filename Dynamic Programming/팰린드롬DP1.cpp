#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 98765432
#define MAX 100001

int N, M, S, E;
int arr[2001];
int dpO[2001];
int dpE[2001];

bool isPalindrome(int x, int y, int gap, int s) {
	if (s == -1) s = 0;
	for (int i = 0; i<gap - s; i++) {
		if (arr[x + i] != arr[y - i]) return false;
	}
	if ((y - x + 1) % 2 == 0) dpE[x + gap] = gap;
	else dpO[x + gap] = gap;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	fill(&dpO[0], &dpO[2000], -1);
	fill(&dpE[0], &dpE[2000], -1);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cin >> M;
	for (int m = 0; m<M; m++) {
		cin >> S >> E;
		int gap = (E - S + 1) / 2;
		if ((E - S + 1) % 2 == 0) {
			if ((dpE[S + gap] != -1) && (dpE[S + gap] >= gap)) cout << 1 << '\n';
			else if (isPalindrome(S, E, gap, dpE[S + gap])) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else {
			if ((dpO[S + gap] != -1) && (dpO[S + gap] >= gap)) cout << 1 << '\n';
			else if (isPalindrome(S, E, gap, dpO[S + gap])) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}

	return 0;
}