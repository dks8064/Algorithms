#include <iostream>
#include <string>
#define MAX 360000
using namespace std;
int n, id;
string a, b;
int pi[MAX];

void getpi(string a) {
	int j = 0;
	for (int i = 1; i<MAX; i++) {
		while (j != 0 && a[i] != a[j]) {
			j = pi[j - 1];
		}
		if (a[i] == a[j]) {
			pi[i] = ++j;
		}
	}
}

bool kmp(string a, string b) {
	int j = 0;
	for (int i = 0; i<(int)b.length(); i++) {
		while (j != 0 && b[i] != a[j])
			j = pi[j - 1];
		if (a[j] == b[i]) {
			if (j == MAX - 1)
				return true;
			else
				j++;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i<MAX; i++) {
		a += '0';
		b += '0';
	}
	for (int i = 0; i<n; i++) {
		cin >> id;
		a[id] = '1';
	}
	for (int i = 0; i<n; i++) {
		cin >> id;
		b[id] = '1';
	}
	getpi(a);
	(kmp(a, b + b)) ? cout << "possible" : cout << "impossible";
}
