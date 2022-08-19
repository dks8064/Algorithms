#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, A, B;
bool switches[101];
pair<int, bool> students[101];

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) cin >> switches[i];
    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> A >> B;
        students[i] = {B, A==1?true:false};
    }

    for(int i=0; i<M; i++) {
        int cur = students[i].first;
        // ³²ÇÐ»ý
        if(students[i].second) {
            int number = students[i].first;
            while(cur <= N) {
                switches[cur] = !switches[cur];
                cur += number;
            }
        } else {
            switches[cur] = !switches[cur];
            int number = 1;
            while(cur-number>=1 && cur+number<=N 
                && switches[cur-number] == switches[cur+number]) {
                switches[cur-number] = !switches[cur-number];
                switches[cur+number] = !switches[cur+number];
                number++;
            }
        }
    }

    for(int i=1; i<=N; i++) {
        cout << switches[i] << " ";
        if(i%20 == 0) cout << endl;
    }

    return 0;
}
