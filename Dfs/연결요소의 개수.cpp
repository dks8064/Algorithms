#include <iostream>
#include <algorithm>
using namespace std;

class CNT {
public:
	int u, v;
};

int* arr;
CNT* countness;
int counts = 0;
int N, M = 0;
int cnt = 0;

void DFS(int i) {
	arr[i] = 1;
	for (int j = 0; j < M; j++) {
		if ((countness[j].u == i + 1) && (arr[countness[j].v - 1] == 0)) {
			DFS(countness[j].v - 1);
		}
		if ((countness[j].v == i + 1) && (arr[countness[j].u - 1] == 0)) {
			DFS(countness[j].u - 1);
		}
	}
}

int main() {

	cin >> N >> M;
	arr = new int[N];
	countness = new CNT[M];
	for (int i = 0; i < N; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		cin >> (countness[i].u) >> countness[i].v;
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] == 0) {
			DFS(i);
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}