#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

/**
* https://www.acmicpc.net/problem/11053
*/

int N;
int A[1001];
int dp[1001] = { 0, };
int num = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j])
				dp[i] = max(dp[j], dp[i]);
		}
		dp[i]++;
		num = max(dp[i], num);
	}

	cout << num;

	return 0;
}
