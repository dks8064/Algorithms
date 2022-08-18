#include <iostream>
#include <cstring>
using namespace std;

int N, M;
string s;
int map[52][52];
bool visited[52][52];
int dir[4] = {-1, 0, 1, 0};

void dfs(int x, int y) {
    if(visited[x][y]) return;
    visited[x][y] = true;

    for(int d=0; d<4; d++) {
        int dx = x+dir[d], dy = y+dir[3-d];
        if(dx < 0  || dy < 0 || dx > N+1 || dy > M+1) continue;
        if(map[dx][dy] != map[x][y]) continue;
        dfs(dx, dy);
    }
}

int main() {
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> s;
        for(int j=1; j<=M; j++) map[i][j] = s[j-1] - '0';
    }

    int cnt = 0;

    for(int h=0; h<=9; h++) {
        memset(visited, false, sizeof(visited));
        dfs(0,0);

        for(int i=0; i<=N+1; i++) {
            for(int j=0; j<=M+1; j++) {
                if(map[i][j] == h) {
                    if(!visited[i][j]) cnt++;
                    map[i][j]++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}