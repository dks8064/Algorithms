#include<iostream>
#include<cmath>
using namespace std;

/**
* https://www.acmicpc.net/problem/2231
* Brute-force
*/

int main() {

	int N, M = 0;

	cin >> N;		// input

	for (int i = 1; i < N; i++) {
		M = i;
		int j = 0, k = i;
		while (k > 0) {
			M += k % 10;
			j++;
			k = i / pow(10, j);
		}
		if (M == N) {
			cout << i;	// output
			return 0;
		}
	}

	cout << 0;			// output
	return 0;
}	
