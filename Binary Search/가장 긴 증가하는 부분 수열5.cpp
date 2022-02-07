#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321


int N;
int arr[1000001];
int index[1000001];
long long temp;
vector<long long> v;

int main() {
	cin >> N;
	for (int i = 0; i<N; i++) {
		cin >> temp;
		if (v.size() == 0 || temp > v.back()) {
			v.push_back(temp);
			index[i] = v.size() - 1;
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), temp) - v.begin();
			v[idx] = temp;
			index[i] = idx;
		}
		arr[i] = temp;
	}

	cout << v.size() << endl;

	int finalIdx = v.size() - 1;
	vector<long long> answer;
	for (int i = N - 1; i >= 0; i--) {
		if (index[i] == finalIdx) {
			finalIdx--;
			answer.push_back(arr[i]);
		}
	}

	for (int i = answer.size() - 1; i >= 0; i--) cout << answer[i] << " ";


	return 0;
}