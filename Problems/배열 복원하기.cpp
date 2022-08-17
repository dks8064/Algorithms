#include<iostream>
using namespace std;

int H, W, X, Y;
int A[301][301];
int B[602][602];

int main() {
    cin >> H >> W >> X >> Y;
    for(int i=0; i<H+X; i++) {
        for(int j=0; j<W+Y; j++) cin >> B[i][j];
    }

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(i>=X && j>=Y) A[i][j] = B[i][j] - A[i-X][j-Y];
            else A[i][j] = B[i][j];
        }
    }

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) cout << A[i][j] << " ";
        cout << endl;
    }

    return 0;
}
