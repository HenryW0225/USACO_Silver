#include <iostream>
#include <array>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int T, N, a, b, current, count;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string ans = "Yes";
        cin >> N;
        pair<int, int> balls[N];
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            balls[i] = make_pair(a, b);
        }
        sort(balls, balls + N);
       
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        pq.push(balls[0].second);
        current = balls[0].first;

        for (int i = 1; i < N; i++) {
            count = 0;
            while (!pq.empty() && current + count < balls[i].first) {
                if (pq.top() >= current + count) {
                    pq.pop();
                    count++;
                } else {
                    ans = "No";
                    i = N-1;
                    break;
                }
            }
            pq.push(balls[i].second);
            current = balls[i].first;
        }
        //cout << ans << endl;
        count = 0;
        while (!pq.empty()) {
            if (pq.top() >= current + count) {
                pq.pop();
                count++;
            } else {
                ans = "No";
                break;
            }
        }

        cout << ans << endl;
    }
}