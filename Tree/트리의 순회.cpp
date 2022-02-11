#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, pright;
int inorder[100001];
int postorder[100001];
stack<int> preorder;

void findPreorder(int left, int right) {
	if (left > right) return;
	if (pright <= 0) return;
	pright--;

	int i = right;
	while (i >= 0 && pright >= 0 && (inorder[i] != postorder[pright])) i--;

	findPreorder(i + 1, right);
	findPreorder(left, i - 1);

	preorder.push(inorder[i]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> inorder[i];
	for (int i = 0; i < n; i++) cin >> postorder[i];

	pright = n;
	findPreorder(0, n - 1);

	while (!preorder.empty()) {
		cout << preorder.top() << " ";
		preorder.pop();
	}

	return 0;
}