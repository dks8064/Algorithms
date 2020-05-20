#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

/**
* https://www.acmicpc.net/problem/10434
*/

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		cout << num << " ";
		cin >> num;
		cout << num << " ";
		if (num == 1) {
			cout << "NO" << endl;
			continue;
		}
		int j = 2;
		bool flag = false;
		while (j <= (int)sqrt(num)) {
			if (num % j == 0) {
				flag = true;
				break;
			}
			j++;
		}
		if (!flag) {
			vector<int> past;
			while (num <= 10000) {
				for (int i = 0; i < past.size(); i++) {
					if (past[i] == num) {
						flag = true;
						break;
					}
				}
				if (flag == true) {
					cout << "NO" << endl;
					break;
				}
				past.push_back(num);
				int temp = num;
				num = 0;
				while (temp / 10 != 0) {
					num += pow(temp % 10, 2);
					temp /= 10;
				}
				num += pow(temp % 10, 2);
				if (num == 1) {
					cout << "YES" << endl;
					break;
				}
			}
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}