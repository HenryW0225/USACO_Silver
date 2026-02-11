#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int T, N, M, temp;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        int numbers[2*N];
        for (int i = 0; i < N; i++) {
            cin >> temp;
            numbers[i] = temp%M;
        }
        sort(numbers, numbers + N);
        for (int i = 0; i < N; i++) {
            numbers[i+N] = numbers[i] + M;
        }
        ll prefix[2*N + 1];
        prefix[0] = 0;
        for (int i = 0; i < 2*N; i++) {
            prefix[i+1] = prefix[i] + (ll) numbers[i];
        }
        ll ans = 10e15;
        for (int i = 0; i < N; i++) {
            ans = min(ans, prefix[i + N] - prefix[i + (N+1)/2] - prefix[i + N/2] + prefix[i]);
        }
        cout << ans << endl;

        
    }
}