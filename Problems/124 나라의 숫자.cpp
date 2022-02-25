#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
	string answer = "";

	while (n>0) {
		int part = n % 3;
		switch (part) {
		case 1: answer += "1"; break;
		case 2: answer += "2"; break;
		case 0: answer += "4"; break;
		}
		n /= 3;
		if (part == 0) n--;
	}

	reverse(answer.begin(), answer.end());

	return answer;
}