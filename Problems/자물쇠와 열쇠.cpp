#include <string>
#include <vector>
using namespace std;

/**
* https://programmers.co.kr/learn/courses/30/lessons/60059
*/

vector<vector<int>> key;
vector<vector<int>> lock;
bool checkKey(int x, int y, int count) {
	for (int d = 0; d < 4; d++) {
		int c = 0;
		for (int i = 0; i < key.size(); i++) {
			if (x + i < 0) continue;
			if (x + i > lock.size() - 1) break;
			for (int j = 0; j < key.size(); j++) {
				if (y + j < 0) continue;
				if (y + j > lock.size() - 1) break;
				int s = i, e = j;
				switch (d) {
				case 1: {s = key.size() - 1 - j; e = i; break; }
				case 2: {s = key.size() - 1 - i; e = key.size() - 1 - j; break; }
				case 3: {s = j; e = key.size() - 1 - i; break; }
				}
				if (lock[x + i][y + j] == key[s][e]) { c = -1; break; }
				if (key[s][e] == 1) c++;

			}
			if (c == -1) break;
		}
		if (c == count) return true;
	}
	return false;
}

bool solution(vector<vector<int>> keys, vector<vector<int>> locks) {
	key = keys;
	lock = locks;
	int count = 0;
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock.size(); j++) {
			if (lock[i][j] == 0) count++;
		}
	}
	cout << count << endl;
	for (int x = 0; x < lock.size() + key.size() - 1; x++) {
		for (int y = 0; y < lock.size() + key.size() - 1; y++) {
			if (checkKey(x - key.size() + 1, y - key.size() + 1, count)) return true;
		}
	}
	return false;
}