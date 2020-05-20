#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

/**
* https://programmers.co.kr/learn/courses/30/lessons/60060
*/

bool cmp(const string& s1, const string& s2) {
	if (s1.size() == s2.size()) {
		return s1 < s2;
	}
	else {
		return s1.size() < s2.size();
	}
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	vector<string> front;
	vector<string> back;
	set<string> check;

	for (string word : words) {  // 중복제거, abc와 cba를 각각 front와 back에 삽입
		if (check.find(word) == check.end()) {
			check.insert(word);
			front.push_back(word);
			reverse(word.begin(), word.end());
			back.push_back(word);
		}
	}

	sort(front.begin(), front.end(), cmp);
	sort(back.begin(), back.end(), cmp);

	for (string query : queries) {
		string a(query);
		string b(query);
		replace(a.begin(), a.end(), '?', 'a');
		replace(b.begin(), b.end(), '?', 'z');
		if (query[0] == '?') {
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			long x = lower_bound(back.begin(), back.end(), a, cmp) - back.begin();
			long y = lower_bound(back.begin(), back.end(), b, cmp) - back.begin();
			answer.push_back(y - x);
		}
		else {
			long x = lower_bound(front.begin(), front.end(), a, cmp) - front.begin();
			long y = lower_bound(front.begin(), front.end(), b, cmp) - front.begin();
			answer.push_back(y - x);
		}
	}

	return answer;
}