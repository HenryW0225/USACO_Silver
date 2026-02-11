#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    ifstream cin("reststops.in");
    ofstream cout("reststops.out");
    int L, N, F, B, a, b, position = 0;
    cin >> L >> N >> F >> B;
    pair<int, int> reststops[N];
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        reststops[i] = make_pair(b, a);
    } sort(reststops, reststops + N);
    long long answer = 0;
   
    int index = N - 1;
    while (true) {
        answer += (long long) (reststops[index].second - position) * (F - B) * reststops[index].first;
        position = reststops[index].second;
        index = max(index - 1, 0);
        while (position >= reststops[index].second) {
            index -= 1;
            if (index == -1) {
                break;
            }
        }
        if (index == -1) {
            break;
        }
    } cout << answer;
}
