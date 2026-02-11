#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    ifstream cin("diamond.in");
    ofstream cout("diamond.out");
    int N, K;
    cin >> N >> K;
    int diamonds[N];
    for (int i = 0; i < N; i++) {
        cin >> diamonds[i];
    } sort(diamonds, diamonds + N);
    int first_start = 0, first_end = 0, second_start = 1, second_end = 1, prev_best = 1, ans = 0;
    while (second_start != N-2) {
        second_start += 1;
        while (second_end + 1 < N) {
            if (diamonds[second_end + 1] - diamonds[second_start] <= K) {
                second_end += 1;
                continue;
            } break;
        }
        first_end += 1;
        while(diamonds[first_end] - diamonds[first_start] > K) {
            first_start += 1;
        } prev_best = max(prev_best, first_end - first_start + 1);
        ans = max(ans, prev_best + second_end - second_start + 1);
    } cout << ans;
}
