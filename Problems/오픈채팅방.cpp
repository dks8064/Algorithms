#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(string str, char delimiter)
{
	vector<string> vs;
	string temp;
	for (int i = 0; !(str[i] == 13 /* Line Feed */ || str[i] == '\n' || str[i] == 0); i++)
	{
		if (str[i] == delimiter)
		{
			vs.push_back(temp);
			temp.clear();
			continue;
		}
		temp.push_back(str[i]);
	}
	vs.push_back(temp);
	return vs;
}

vector<string> solution(vector<string> records) {
	vector<string> answer;
	map<string, string> m;

	for (string record : records) {
		vector<string> s;
		s = split(record, ' ');
		if (s[0] == "Enter") {
			m[s[1]] = s[2];
		}
		else if (s[0] == "Change") {
			m[s[1]] = s[2];
		}
	}

	for (string record : records) {
		vector<string> s;
		s = split(record, ' ');
		if (s[0] == "Enter") {
			answer.push_back(m[s[1]] + "님이 들어왔습니다.");
		}
		else if (s[0] == "Leave") {
			answer.push_back(m[s[1]] + "님이 나갔습니다.");
		}
	}

	return answer;
}