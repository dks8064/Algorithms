#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> boards;
int n, m;

int blockx[3][4][6] = {
	{ { 0,0,0,1,-1,-1 },{ 0,0,1,2,-1,-1 },{ 0,1,1,1,0,0 },{ 0,1,2,2,0,1 } },
	{ { 0,0,0,1,-1,-1 },{ 0,1,2,2,0,1 },{ 0,1,1,1,0,0 },{ 0,0,1,2,-1,-1 } },
	{ { 0,1,1,1,0,0 },{ 0,1,1,2,-1,-1 },{ 0,0,0,1,-1,-1 },{ 0,1,1,2,-1,-1 } }
};

int blocky[3][4][6] = {
	{ { 0,1,2,2,-1,-1 },{ 0,1,0,0,-1,-1 },{ 0,0,1,2,1,2 },{ 0,0,0,-1,-1,-1 } },
	{ { 0,1,2,0,-1,-1 },{ 0,0,0,1,1,1 },{ 0,0,-1,-2,-1,-2 },{ 0,1,1,1,-1,-1 } },
	{ { 0,-1,0,1,-1,1 },{ 0,0,1,0,-1,-1 },{ 0,1,2,1,-1,-1 },{ 0,-1,0,0,-1,-1 } }
};

bool clearBlock(int x, int y, int i, int j) {
	for (int d = 0; d<4; d++) {
		int dx = x + blockx[i][j][d], dy = y + blocky[i][j][d];
		boards[dx][dy] = 0;
	}
	return true;
}

bool checkBlock(int x, int y) {
	int checkNum = boards[x][y];

	for (int i = 0; i<3; i++) {
		for (int j = 0; j<4; j++) {
			for (int d = 0; d<6; d++) {
				if (blockx[i][j][d] == -1 && blocky[i][j][d] == -1) break;
				int dx = x + blockx[i][j][d], dy = y + blocky[i][j][d];
				if (dx < 0 || dy < 0 || dx > n - 1 || dy > m - 1) break;
				if (boards[dx][dy] != checkNum) break;
				if (d == 3) checkNum = 0;
				if (d > 3) {
					dx = x + blockx[i][j][d];
					while (dx >= 0) {
						if (boards[dx--][dy] != 0) return false;
					}
				}
				if (d == 5) return clearBlock(x, y, i, j);
			}
		}
	}

	return false;
}

int solution(vector<vector<int>> board) {
	boards = board;
	n = board.size();
	m = board[0].size();
	int answer = 0;

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (boards[i][j] == 0) continue;
			if (checkBlock(i, j)) {
				answer++;
				j = -1;
			}
		}
	}

	return answer;
}