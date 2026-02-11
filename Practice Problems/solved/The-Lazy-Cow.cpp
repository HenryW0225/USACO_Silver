/*#include <iostream>
#include <fstream>
#include <array>
#include<algorithm>
#include <cstdlib>
using namespace std;


int main() {
    ifstream cin("lazy.in");
    ofstream cout("lazy.out");
    int N, K, x, y;
    int ans = 0;
    cin >> N >> K;
    int field[2*N-1][2*N-1];
    for (int i = 0; i < 2*N-1; i++) {
        for (int j = 0; j < 2*N-1; j++) {
            field[i][j] = -1;
        }
    } 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i+j][abs(N-i-j-1) + 2*(i - max(0, i+j+1-N))];
        }
    } 
    int prefix[2*N][2*N] = {0};
    for (int i = 0; i < 2*N; i++) {
        for (int j = 0; j < 2*N; j++) {
            prefix[i][j] = 0;
        }
    }
    for (int i = 1; i < 2*N; i++) {
        for (int j = 1; j < 2*N; j++) {
            prefix[i][j] = max(0, field[i-1][j-1]) + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    } 
    for (int i = 1; i < 2*N; i++) {
        for (int j = 1; j < 2*N; j++) {
            if (field[i-1][j-1] == -1) {
                continue;
            } ans = max(ans, prefix[min(2*N-1, i+K)][min(2*N-1, j+K)] + prefix[max(0, i-K-1)][max(0, j-K-1)] - prefix[min(2*N-1, i+K)][max(0, j-K-1)] - prefix[max(0, i-K-1)][min(2*N-1, j+K)]); 
        }
    } cout << ans;
}

#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    ifstream cin("lazy.in");
    ofstream cout("lazy.out");
    int N, K, temp;
    long track = 0;
    long ans = 0;
    cin >> N >> K;
    int field[N][N+1] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N+1; j++) {
            cin >> temp;
            field[i][j] = field[i][j-1] + temp;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            track = 0;
            temp = 0;
            if (i-K < 0) {
                temp += K-i;
            }
            for (int k = max(0, i - K); k <= i; k++) {
                track += field[k][min(N, j+temp+1)] - field[k][max(0, j-temp)];
                temp += 1;
            } temp -= 1;
            for (int k = i+1; k <= min(N-1, i+K); k++) {
                temp -= 1;
                track += field[k][min(N, j+temp+1)] - field[k][max(0, j-temp)];
            } 
            ans = max(ans, track); 
        } 
    } cout << ans;
}
*/