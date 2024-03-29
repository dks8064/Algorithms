#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i<n; i++) {
		string str;
		for (int j = n - 1; j >= 0; j--) {
			if ((arr1[i] | arr2[i])&(1 << j)) str += "#";
			else str += " ";
		}
		answer.push_back(str);
	}
	return answer;
}