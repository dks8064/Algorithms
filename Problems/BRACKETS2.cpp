#include <iostream>
#include <stack>
using namespace std;

/**
* https://algospot.com/judge/problem/read/BRACKETS2
*/

int main() {

	int C;
	string str;
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> str;
		stack<char> s;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '{' || str[i] == '[') s.push(str[i]);
			else if (s.empty()) { s.push('('); break; }
			else if (s.top() == '(' && str[i] == ')') s.pop();
			else if (s.top() == '{' && str[i] == '}') s.pop();
			else if (s.top() == '[' && str[i] == ']') s.pop();
			else break;
		}

		if (s.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}