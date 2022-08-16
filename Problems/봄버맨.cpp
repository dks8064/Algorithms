#include <iostream>
using namespace std;

int R, C, N;
char map[3][201][201];
int dir[4] = {-1, 0, 1, 0};

void printMap(int n) {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) cout << map[n][i][j];
        cout << endl;
    }
}

void bomb(int n) {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(map[n][i][j] == 'O') {
                map[n+1][i][j] = '.';
                for(int d=0; d<4; d++) {
                    int dx = i+dir[d], dy = j+dir[3-d];
                    if(dx<0 || dy<0 || dx>R-1 || dy>C-1) continue;
                    map[n+1][dx][dy] = '.';
                }
            }
        }
    }
}

int main() {

    cin >> R >> C >> N;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> map[0][i][j];
            map[1][i][j] = map[2][i][j] = 'O';
        }
    }

    if(N == 1) printMap(0);
    else if(N%2 == 0) printMap(1);
    else if(N%4 == 3) {
        bomb(0);
        printMap(1);
    } else {
        bomb(0);
        bomb(1);
        printMap(2);
    }

    return 0;
}