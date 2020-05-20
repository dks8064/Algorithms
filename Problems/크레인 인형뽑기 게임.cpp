#include <string>
#include <vector>
#include <stack>
using namespace std;

/**
* https://programmers.co.kr/learn/courses/30/lessons/64061
*/

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;
	for (int move : moves) {
		for (int i = 0; i < board.size(); i++) {
			if (board[i][move - 1] != 0) {
				if (!s.empty() && s.back() == board[i][move - 1]) {
					s.pop_back();
					answer += 2;
				}
				else s.push_back(board[i][move - 1]);
				board[i][move - 1] = 0;
				break;
			}
		}
	}
	return answer;
}