#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> children[51];

int call(int n){
    vector<int> v;
    int ret = 0;
    int w = children[n].size() - 1;

    for(int c: children[n]) v.push_back(call(c));
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) ret = max(ret, v[i] + w--);

    return ret + 1;
}

int main(){
  cin >> N;
  
  int boss;
  for(int i = 0; i<N ; ++i){
    cin >> boss;
    if(i == 0) continue;
    children[boss].push_back(i);
  }

  cout << call(0) - 1;

  return 0;
}
