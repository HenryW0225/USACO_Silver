#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
using namespace std;


typedef pair<int, int> point;

bool ysort(point p, point q) {
    if (p.first == q.first) {
        return p.second > q.second;
    } return p.first < q.first;
}
int main() {
    ifstream cin ("mountains.in");
    ofstream cout ("mountains.out");
    int N, x, y, rightest = -1, ans = 0;
    cin >> N;
    point mountains[N];
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        mountains[i] = make_pair(x-y, x+y);
    } sort (mountains, mountains + N, ysort);
    for (int i = 0; i < N; i++) {
        if (rightest < mountains[i].second) {
            ans += 1;
            rightest = mountains[i].second;
        }
    } cout << ans;
}
