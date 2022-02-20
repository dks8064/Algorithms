#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;

#define INF 98765432

int N, K;
vector<string> room;
set<string> answer[15];

vector<string> split(string str, string delimeter) {
	vector<string> result;
	int current = str.find(delimeter);
	int prev = 0;

	while (current != string::npos) {
		result.push_back(str.substr(prev, current - prev));
		prev = current + delimeter.length();
		current = str.find(delimeter, prev);
	}

	result.push_back(str.substr(prev, current - prev));

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		string s, all = "";
		for (int j = 0; j < K; j++) {
			cin >> s;
			all += (s + " ");
		}
		room.push_back(all);
	}

	sort(room.begin(), room.end());
	for (int i = 0; i<N; i++) {
		int k = 0;
		if (i != 0) {
			for (int c = 0; c<min(room[i - 1].length(), room[i].length()); c++) {
				if (room[i - 1][c] != room[i][c]) break;
				if (room[i][c] == ' ') k++;
			}
		}
		vector<string> vs = split(room[i], " ");
		for (int j = k; j<vs.size() - 1; j++) {
			string s = "";
			for (int k = 0; k<j * 2; k++) s += "-";
			cout << s << vs[j] << '\n';
		}
	}

	return 0;
}
