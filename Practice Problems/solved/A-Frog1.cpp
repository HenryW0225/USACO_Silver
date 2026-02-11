#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int N; 
    cin >> N;
    int heights[N];
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    int cost[N];
    cost[0] = 0;
    cost[1] = abs(heights[1] - heights[0]);
    for (int i = 2; i < N; i++) {
        cost[i] = min(cost[i-1] + abs(heights[i] - heights[i-1]), cost[i-2] + abs(heights[i] - heights[i-2]));
    }
    cout << cost[N-1];
}