#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int main() {
    int T, N, K, a, b, c;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> K;
        int trees[N];
        vector<tuple<int, int, int, int>> endpoints;
        for (int i = 0; i < N; i++) {
            cin >> trees[i];
            endpoints.push_back(make_tuple(trees[i], 0, 0, 0));
        } sort(trees, trees + N);

        for (int i = 0; i < K; i++) {
            cin >> a >> b >> c;
            endpoints.push_back(make_tuple(a, -1, b, upper_bound(trees, trees + N, b) - lower_bound(trees, trees + N, a) - c));
        }
        sort(endpoints.begin(), endpoints.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int ans = 0;
        for (int i = 0; i < N + K; i++) {
            if (get<1>(endpoints[i]) == 0) {
                while (!pq.empty() && get<0>(endpoints[i]) > pq.top().second) {
                    pq.pop();
                }
                if (pq.empty() || pq.top().first > ans) {
                    ans++;
                }
            } else {
                pq.push(make_pair(ans + get<3>(endpoints[i]), get<2>(endpoints[i])));
            }
        }
        cout << ans << endl;
    }
}


/*#include <iostream>
#include <array>
#include <algorithm>
#include <queue>
#include <tuple>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int T, a, b, c, count;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, K;
        cin >> N >> K;
        pair<int, int> points[N + 2 * K];
        int intervals[K][2];
        for (int i = 0; i < N; i++) {
            cin >> a;
            points[i] = make_pair(a, 0);
        }
        for (int i = 0; i < K; i++) {
            cin >> a >> intervals[i][1] >> b;
            intervals[i][0] = -b;
            points[N + 2 * i] = make_pair(a, - i - 1);
            points[N + 2 * i + 1] = make_pair(intervals[i][1], i + 1);
        }
        sort(points, points + N + 2 * K);

        count = 0;
        for (int i = 0; i < N + 2 * K; i++) {
            if (points[i].second == 0) {
                count++;
            } else if (points[i].second < 0) {
                intervals[-points[i].second- 1][0] -= count;
            } else {
                intervals[points[i].second - 1][0] += count;
            }
        }

        cout << endl << endl;
        cout << "points" << endl;
        for (auto it : points) {
            cout << it.first << " " << it.second << endl;
        } cout << endl << endl;

        cout << "intervals" << endl;
        for (int i = 0; i < K; i++) {
            cout << intervals[i][0] << " " << intervals[i][1] << endl;
        } cout << endl << endl;

        count = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        for (int i = 0; i < N + 2 * K; i++) {
            if (points[i].second == 0) {
                if (pq.empty()) {
                    count++;
                    continue;
                }
                if (get<0>(pq.top()) == 0) {
                    continue;
                }
                count++;
                a = get<0>(pq.top());
                b = get<1>(pq.top());
                c = get<2>(pq.top());
                intervals[c][0] = count;
                pq.pop();
                pq.push(make_tuple(a-1, b, c));
            } 
            else if (points[i].second < 0) {
                pq.push(make_tuple(intervals[-points[i].second - 1][0], intervals[-points[i].second - 1][1], -points[i].second - 1));
                intervals[-points[i].second - 1][0] = count;
            } 
            else {
                if (!pq.empty() && get<2>(pq.top()) == points[i].second - 1) {
                    pq.pop();
                    while(!pq.empty() && get<1>(pq.top()) <= points[i].first) {
                        pq.pop();
                    }
                    if (pq.empty()) {
                        continue;
                    }
                    a = get<0>(pq.top());
                    b = get<1>(pq.top());
                    c = get<2>(pq.top());
                    pq.pop();
                    pq.push(make_tuple(a + intervals[c][0] - count, b, c));
                }
            }
        }

        cout << count << endl;
    }
} */