#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int target, int step, int ans) {
	if (step == numbers.size()) return (ans == target) ? 1 : 0;
	return dfs(numbers, target, step + 1, ans + numbers[step]) + dfs(numbers, target, step + 1, ans - numbers[step]);
}

int solution(vector<int> numbers, int target) {
	return dfs(numbers, target, 0, 0);
}