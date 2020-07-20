#include <iostream>
#include <list>
using namespace std;

/**
* https://algospot.com/judge/problem/read/JOSEPHUS
*/

int main() {

	int C, N, K;
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> N >> K;
		list<int> l;
		for (int n = 1; n <= N; n++) l.push_back(n);
		list<int>::iterator kill = l.begin();
		while (N > 2) {
			kill = l.erase(kill);
			if (kill == l.end()) kill = l.begin();
			N--;

			for (int k = 0; k < K - 1; k++) {
				kill++;
				if (kill == l.end()) kill = l.begin();
			}
		}
		cout << l.front() << " " << l.back() << endl;
	}

	return 0;
}