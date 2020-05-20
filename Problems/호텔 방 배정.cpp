#include <string>
#include <vector>
#include <map>
using namespace std;

/**
* https://programmers.co.kr/learn/courses/30/lessons/64063
*/

map<long long, long long> p;

long long find(long long x) {
	if (p[x] == 0) return x;
	else {
		p[x] = find(p[x]);
		return p[x];
	}
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	for (long long x : room_number) {
		long long y = find(x);
		answer.push_back(y);
		p[y] = y + 1;
	}
	return answer;
}