#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    int books[N];
    for (int i = 0; i < N; i++) {
        cin >> books[i];
    } int start = 0, end = 0, sum = 0, ans = 0, current = 0;
    while (end < N) {
        if (sum + books[end] <= T) {
            current += 1;
            sum += books[end];
            end += 1;
        } else {
            current -= 1;
            sum -= books[start];
            start += 1;
        } ans = max(ans, current);
    } cout << ans;
} 
