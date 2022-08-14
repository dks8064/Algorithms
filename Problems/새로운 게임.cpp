#include<iostream>
#include <queue>
#include <stack>
using namespace std;

int dirX[4] = {0, 0, -1, 1};
int dirY[4] = {1, -1, 0, 0};
pair<int, queue<int>> map[13][13];
pair<pair<int, int>, int> chess[10];
int N, K, X, Y, D, C;

int main() {

    cin >> N >> K;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> C;
            map[i][j] = {C, {}};
        }
    }
    for(int i=0; i<K; i++) {
        cin >> X >> Y >> D;
        chess[i] = {{X-1, Y-1}, D-1};
        map[X-1][Y-1].second.push(i);
    }

    int cnt = 0;
    while(cnt++ <= 1000) {
        for(int i=0; i<K; i++) {
            bool isBlue = false;
            int cx = chess[i].first.first;
            int cy = chess[i].first.second;

            // 맨 아래
            if(map[cx][cy].second.front() != i) continue;

            int qSize = map[cx][cy].second.size();
            int dir = chess[i].second;
            int dx = cx + dirX[dir];
            int dy = cy + dirY[dir];
            
            // 파란색
            if(dx < 0 || dy < 0 || dx > N-1 || dy > N-1 || map[dx][dy].first == 2) {
                dir = (dir%2 == 0)? dir+1 : dir-1;
                dx = cx + dirX[dir];
                dy = cy + dirY[dir];
                // 방향만 바꾸기
                if(dx < 0 || dy < 0 || dx > N-1 || dy > N-1 || map[dx][dy].first == 2) {
                    dx = chess[i].first.first;
                    dy = chess[i].first.second;
                    isBlue = true;
                }
            }

            // 빨간색일 때, 역순으로
            if(!isBlue && (map[dx][dy].first == 1)) {
                stack<int> reverse;
                for(int j=0; j<qSize; j++) {
                    int next = map[cx][cy].second.front();
                    map[cx][cy].second.pop();
                    reverse.push(next);
                }
                for(int j=0; j<qSize; j++) {
                    int next = reverse.top();
                    reverse.pop();
                    map[cx][cy].second.push(next);
                }
            }

            chess[i].second = dir;
            for(int j=0; j<qSize; j++) {
                int next = map[cx][cy].second.front();
                map[cx][cy].second.pop();

                chess[next].first.first = dx;
                chess[next].first.second = dy;
                map[dx][dy].second.push(next);
            }

            if(map[dx][dy].second.size() >= 4) {
                cout << cnt;
                return 0;
            }
        }
    }

    cout << -1;

    return 0;
}