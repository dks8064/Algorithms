#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int dirX[4] = {0, 0, -1, 1};
int dirY[4] = {1, -1, 0, 0};
char map[7][7];
vector<pair<int, int>> teachers;
int N, K, X, Y, D, C;

bool check() {
    for(pair<int, int> t: teachers) {
        for(int d=0; d<4; d++) {
            int dx = t.first, dy = t.second;
            while(dx>=0&&dy>=0&&dx<N&&dy<N) {
                if(map[dx][dy] == 'O') break;
                if(map[dx][dy] == 'S') return false;
                dx += dirX[d];
                dy += dirY[d];
            }
        }
    }

    return true;
}

bool setStone(int n, int x, int y) {
    if(n == 3) return check();

    int j;
    for(int i=x; i<N; i++) {
        j = (i==x) ? y+1 : 0;
        for(; j<N; j++) {
            if(map[i][j] == 'X') {
                map[i][j] = 'O';
                if(setStone(n + 1, i , j)) return true;
                map[i][j] = 'X';
            }
        }
    }

    return false;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'T') teachers.push_back({i, j});
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j] == 'X') {
                map[i][j] = 'O';
                if(setStone(1, i , j)) {
                    cout << "YES";
                    return 0;
                }
                map[i][j] = 'X';
            }
        }
    }

    cout << "NO";
    return 0;
}