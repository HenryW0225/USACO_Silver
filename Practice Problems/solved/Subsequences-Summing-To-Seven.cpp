#include <iostream>
#include <array>
#include <fstream>
using namespace std;


int main() {
    ifstream cin ("div7.in");
    ofstream cout("div7.out");
    int N, temp, ans = 0;
    cin >> N;
    int cows[N+1];
    for (int i = 1; i < N+1; i++) {
        cin >> temp;
        cows[i] = (cows[i-1] + temp)%7;
    } for (int i = N-1; i > -1; i--) {
        for (int j = 1; j < N-i; j++) {
            if ((cows[j+i] - cows[j-1])%7 == 0) {
                ans = i+1;
                j = N;
                i = -1;
            }
        }
    } cout << ans;
}
