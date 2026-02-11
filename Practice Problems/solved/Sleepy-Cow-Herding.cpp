#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    ifstream cin("herding.in");
    ofstream cout("herding.out");
    int N;
    cin >> N;
    long long cows[N];
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    } sort(cows, cows + N);
    int start = 0, end = 0, ans = 1;
    while (end < N and start < N) {
        while (cows[end + 1] - cows[start] <= (long long) N-1) {
            end += 1;
        } ans = max(ans, end - start + 1); 
        start += 1;
    }
    if (ans == N-1 and cows[1] - cows[0] != (long long) 2 and cows[N-1] - cows[N-2] != (long long) 2) {
        cout << 2 << endl;
    } else {
        cout << N - ans << endl;
    }
    long long count = 0;
    for (int i = 0; i < N-1; i++) {
        count += cows[i+1] - cows[i] - 1;
    } 
    count -= min(cows[1] - cows[0] - 1, cows[N-1] - cows[N-2] - 1);
    cout << count;
}
