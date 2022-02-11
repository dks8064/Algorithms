#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define INF 987654321

int T, F;
string s1, s2;
int parent[200001];
int friendNum[200001];
map<string, int> mId;

int findParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}

void makeUnion(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	parent[x] = y;
	if (x != y) friendNum[y] += friendNum[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> F;
		int curId = 1;
		for (int i = 0; i<200001; i++) {
			parent[i] = i;
			friendNum[i] = 1;
		}
		int id1, id2;
		for (int f = 0; f < F; f++) {
			cin >> s1 >> s2;
			if (mId.find(s1) == mId.end()) {
				mId[s1] = curId;
				id1 = curId++;
			}
			else id1 = mId[s1];
			if (mId.find(s2) == mId.end()) {
				mId[s2] = curId;
				id2 = curId++;
			}
			else id2 = mId[s2];

			makeUnion(id1, id2);
			cout << friendNum[findParent(id1)] << '\n';
		}
	}

	return 0;
}