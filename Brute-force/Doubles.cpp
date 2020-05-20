#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* https://www.acmicpc.net/problem/4641
*/


int main() {

	int temp = 0;
	vector<int> numbers;
	while (true) {
		cin >> temp;
		if (temp == 0) {
			int count = 0;
			sort(numbers.begin(), numbers.end());
			for (int i = 0; i < numbers.size() - 1; i++) {
				for (int j = i + 1; j < numbers.size(); j++) {
					if (numbers[j] > numbers[i] * 2) break;
					else if (numbers[j] == numbers[i] * 2) {
						count++;
						break;
					}
				}
			}
			cout << count << endl;
			numbers.clear();
		}
		else if (temp == -1) break;
		else numbers.push_back(temp);
	}
	return 0;
}