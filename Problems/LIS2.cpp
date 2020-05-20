#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
* https://www.acmicpc.net/problem/11053
*/

vector<int> vec;
int N, temp, num = 0;

int main() {

	cin >> N;
	cin >> temp;
	vec.push_back(temp);
	num++;
	for (int i = 1; i < N; i++) {
		cin >> temp;
		if (temp > vec.back()) {
			vec.push_back(temp);
			num++;
		}
		else {
			int index = lower_bound(vec.begin(), vec.end(), temp) - vec.begin();
			vec[index] = temp;
		}
	}

	cout << num << endl;

	return 0;
}