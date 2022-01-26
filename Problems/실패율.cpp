#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct Stage {
	int num;
	double rate;
	Stage(int num, double rate) : rate(rate), num(num) {}
};

struct cmp {
	bool operator()(Stage t, Stage u) {
		if (t.rate == u.rate) return t.num > u.num;
		return t.rate < u.rate;
	}
};

vector<int> solution(int N, vector<int> s) {

	priority_queue<Stage, vector<Stage>, cmp> pq;
	int stages[501];
	memset(stages, 0, sizeof(stages));

	for (int stage : s) stages[stage]++;


	int player = s.size();
	for (int i = 1; i <= N; i++) {
		if (player == 0) pq.push(Stage(i, 0));
		else pq.push(Stage(i, (double)stages[i] / player));
		player -= stages[i];
	}

	vector<int> answer;
	while (!pq.empty()) {
		answer.push_back(pq.top().num);
		pq.pop();
	}

	return answer;
}