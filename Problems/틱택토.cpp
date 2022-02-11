#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int win[8][3] = {
	{ 0, 1, 2 },{ 3, 4, 5 },{ 6, 7, 8 },
	{ 0, 3, 6 },{ 1, 4, 7 },{ 2, 5, 8 },
	{ 0, 4, 8 },{ 2, 4, 6 }
};
string game;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> game;
	while (game != "end") {
		int xNum = 0, oNum = 0;
		for (int i = 0; i < 9; i++) {
			if (game[i] == 'X') xNum++;
			if (game[i] == 'O') oNum++;
		}

		bool oFlag = false, xFlag = false;
		for (int i = 0; i < 8; i++) {
			int oCnt = 0, xCnt = 0;
			for (int j = 0; j < 3; j++) {
				if (game[win[i][j]] == 'O') oCnt++;
				else if (game[win[i][j]] == 'X') xCnt++;
			}
			if (oCnt == 3) oFlag = true;
			if (xCnt == 3) xFlag = true;
		}

		if (xFlag && !oFlag && (xNum == oNum + 1)) cout << "valid\n";
		else if (!xFlag && oFlag && (xNum == oNum)) cout << "valid\n";
		else if (!xFlag && !oFlag && (xNum == 5) && (oNum == 4)) cout << "valid\n";
		else cout << "invalid\n";

		cin >> game;
	}

	return 0;
}