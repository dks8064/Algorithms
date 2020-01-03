#include<iostream>
#include<algorithm>
using namespace std;

/**
* https://www.acmicpc.net/problem/2309
* Brute-force
*/

#define N 9
#define MAX 100

int main() {

	int dwarfs[N], total = 0;

	for (int i = 0; i < N; i++) {	// input
		cin >> dwarfs[i];
		total += dwarfs[i];
	}

	total -= MAX;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (dwarfs[i] + dwarfs[j] == total) {
				dwarfs[i] = dwarfs[j] = -1;
				sort(dwarfs, dwarfs+N);
				break;
			}
		}
		if (dwarfs[0] == -1)
			break;
	}

	for (int i = 2; i < N; i++)		// output
		cout << dwarfs[i] << endl;

	return 0;
}