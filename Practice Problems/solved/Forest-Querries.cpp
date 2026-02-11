#include <iostream>
#include <array>
using namespace std;

int main() {
    int N, Q, x1, x2, y1, y2;
    char temp;
    cin >> N >> Q;
    int forest[N+1][N+1];
    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < N+1; j++) {
            forest[i][j] = 0;
        }
    } for (int i = 1; i < N+1; i++) {
        for (int j = 1; j < N+1; j++) {
            cin >> temp;
            if (temp == '*') {
                forest[i][j] = forest[i-1][j] + forest[i][j-1] - forest[i-1][j-1] + 1;
            } else {
                forest[i][j] = forest[i-1][j] + forest[i][j-1] - forest[i-1][j-1];
            }
        }
    } 
    for (int i = 0; i < Q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << forest[x2][y2] - forest[x2][y1-1] - forest[x1-1][y2] + forest[x1-1][y1-1] << endl;
    }
}
