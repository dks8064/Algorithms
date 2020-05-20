#include <iostream>
using namespace std;

/**
* https://www.acmicpc.net/problem/10844
*/

int main() {
	int N;
	int sum = 0;
	long arr[101][10];

	cin >> N;
	arr[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		arr[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		arr[i][0] = arr[i - 1][1];
		for (int j = 1; j < 9; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
		}
		arr[i][9] = arr[i - 1][8];
	}

	for (int i = 0; i < 10; i++) {
		sum = (sum + arr[N][i]) % 1000000000;
	}

	cout << sum % 1000000000;
}