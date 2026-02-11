#include <iostream>
#include <fstream>
#include <array>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ifstream cin ("helpcross.in");
    ofstream cout ("helpcross.out");

    int C, N, a, b;
    cin >> C >> N;
    pair<int, int> animals[C+N];
    for (int i = 0; i < C; i++) {
        cin >> a;
        animals[i] = make_pair(a, 1000000001);
    }
    for (int i = C; i < C + N; i++) {
        cin >> a >> b;
        animals[i] = make_pair(a, b);
    }
    sort(animals, animals + C + N);
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    /*cout << endl;
    for (auto it : animals) {
        cout << it.first << " " << it.second << endl;
    } cout << endl; */

    int ans = 0;
    for (int i = 0; i < C + N; i++) {
        if (animals[i].second == 1000000001) {
            while (!pq.empty()) {
                if (pq.top() >= animals[i].first) {
                    ans++;
                    pq.pop();
                    break;
                } 
                pq.pop();
            }
        } else {
            pq.push(animals[i].second);
        }
    }
    cout << ans;

}