#include <iostream>
#include <array>
using namespace std;

int main() {
    int t, N;
    cin >> t;
    for (int m = 0; m < t; m++) {
        cin >> N;
        int ans = 0;
        int sights[N];
        int lower_bound[N];
        int upper_bound[N];
        for (int i = 0; i < N; i++) {
            cin >> sights[i];
            lower_bound[i] = sights[i] + i + 1;
            upper_bound[i] = sights[i] - i - 1;
        } for (int i = 0; i < N-1; i++) {
            if (lower_bound[i] > lower_bound[i+1]) {
                lower_bound[i+1] = lower_bound[i];
            }
        } for (int i = N-1; i > 0; i--) {
            if (upper_bound[i] > upper_bound[i-1]) {
                upper_bound[i-1] = upper_bound[i];
            }
        } for (int i = 1; i < N-1; i++) {
            if (ans < sights[i] + lower_bound[i-1] + upper_bound[i+1]) {
                ans = sights[i] + lower_bound[i-1] + upper_bound[i+1];
            }
        } cout << ans << endl;
    }
}
