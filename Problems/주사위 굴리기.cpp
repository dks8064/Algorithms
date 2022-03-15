#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;


int N, M, X, Y, R, C, K, D;
int map[21][21];
int dirX[5] = { 0, 0, 0, -1, 1 };
int dirY[5] = { 0, 1, -1, 0, 0 };
int dice[7];

void changeDice(int d) {
	int temp[7];
	for (int i = 1; i < 7; i++) temp[i] = dice[i];

	if (d == 1) {
		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	else if (d == 2) {
		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[4] = temp[1];
		dice[6] = temp[4];
	}
	else if (d == 3) {
		dice[1] = temp[5];
		dice[2] = temp[1];
		dice[5] = temp[6];
		dice[6] = temp[2];
	}
	else {
		dice[1] = temp[2];
		dice[2] = temp[6];
		dice[5] = temp[1];
		dice[6] = temp[5];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> X >> Y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> map[i][j];
	}

	for (int k = 0; k < K; k++) {
		cin >> D;
		int dx = X + dirX[D], dy = Y + dirY[D];
		if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
		changeDice(D);
		if (map[dx][dy] == 0) {
			map[dx][dy] = dice[6];
		}
		else {
			dice[6] = map[dx][dy];
			map[dx][dy] = 0;
		}
		cout << dice[1] << '\n';
		X = dx; Y = dy;
	}

	return 0;
}

