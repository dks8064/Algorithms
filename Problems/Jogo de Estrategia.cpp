#include <iostream>
#include <cstring>
using namespace std;

/**
* https://www.acmicpc.net/problem/13604
*/

int J, R, score;
int scores[500];
int lastScores[500];

int main() {
	memset(scores, 0, sizeof(scores));
	memset(lastScores, 0, sizeof(lastScores));

	cin >> J >> R;
	for (int i = 0; i<R; i++) {
		for (int j = 0; j<J; j++) {
			cin >> score;
			scores[j] += score;
			if (i == R - 1) lastScores[j] = score;
		}
	}

	int highScore = -1, highIdx = 0;
	for (int j = 0; j<J; j++) {
		if ((highScore < scores[j]) || (highScore == scores[j] && lastScores[j] >= lastScores[highIdx])) {
			highScore = scores[j];
			highIdx = j;
		}
	}

	cout << highIdx + 1;

	return 0;
}