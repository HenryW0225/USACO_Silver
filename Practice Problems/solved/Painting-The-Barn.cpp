#include <iostream>
#include <fstream>
#include <array>
using namespace std;

int main() {
    ifstream cin("paintbarn.in");
    ofstream cout("paintbarn.out");
    int N, K, x1, y1, x2, y2, ans = 0;
    cin >> N >> K;
    int barn[1002][1002] = {0};
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        barn[x2][y2] += 1;
        barn[x1][y2] -= 1;
        barn[x2][y1] -= 1;
        barn[x1][y1] += 1;
    } for (int i = 1000; i > 0; i--) {
        for (int j = 1000; j > 0; j--) {
            barn[i][j] += barn[i][j+1] + barn[i+1][j] - barn[i+1][j+1];
            if (barn[i][j] == K) {
                ans++;
            }
        } 
    } cout << ans;
}
