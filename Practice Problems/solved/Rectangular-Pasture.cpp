#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

typedef pair<int, int> Point;

bool ysort(Point p, Point q) { 
    return p.second < q.second; 
}

int main() {
    int N, x, y, higher, lower, high, low;
    long long ans;
    cin >> N;
    Point cow[N];
    ans = 2*N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        cow[i] = make_pair(x, y);
    } sort(cow, cow + N, ysort);
    for (int i = 0; i < N; i++) {
        cow[i].second = i+1;
    } sort(cow, cow + N);
    for (int i = 0; i < N; i++) {
        cow[i].first = i+1;
    } vector<vector<int>> location(2501, vector<int>(2501));
    for (int i = 0; i < N; i++) {
        location[cow[i].first][cow[i].second] = 1;
    } for (int i = 1; i < 2501; i++) {
        for (int j = 1; j < 2501; j++) {
            location[i][j] += location[i][j-1] + location[i-1][j] - location[i-1][j-1];
        }
    } 
    for (int i = 0; i < N-1; i++) {
        for (int j = i+2; j < N; j++) {
            high = max(cow[i].second, cow[j].second);
            low = min(cow[i].second, cow[j].second);
            higher = location[j+1][2500] - location[i][2500] - location[j+1][high] + location[i][high];
            lower = location[j+1][low-1] - location[i][low-1];
            ans += (long long) (higher + 1) * (lower + 1);
        }
    } cout << ans;
}
