#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;

	set<int> uniform;
	set<int> notUniform;

	for (int r : reserve) {
		if (find(lost.begin(), lost.end(), r) == lost.end()) uniform.insert(r);
		else notUniform.insert(r);
	}

	sort(lost.begin(), lost.end());
	for (int i = 0; i<lost.size(); i++) {
		if (notUniform.count(lost[i])) continue;
		else if (uniform.count(lost[i] - 1)) uniform.erase(lost[i] - 1);
		else if (uniform.count(lost[i] + 1)) uniform.erase(lost[i] + 1);
		else answer--;
	}


	return answer;
}