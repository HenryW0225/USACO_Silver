//not solved

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    ifstream cin ("moocast.in");
    ofstream cout ("moocast.out");
    int N;
    cin >> N;
    int cows[N][3];
    for (int i = 0; i < N; i++) {
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }
    vector<int> connections[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (pow(abs(cows[i][0] - cows[j][0]), 2) + pow(abs(cows[i][1] - cows[j][1]), 2) <= pow(cows[i][2], 2) && i != j) {
                connections[i].push_back(j);
            }
        }
    } 

    int ans = 0;

    for (int i = 0; i < N; i++) {
        deque<int> current = {};
        current.push_back(i);
        int visited[N];
        for (int j = 0; j < N; j++) {
            visited[j] = 0;
        }
        visited[i] = 1;
        int count = 0;
        while (current.size() > 0) {
            int index = current[0];
            count += 1;
            current.pop_front();
            for (int j = 0; j < connections[index].size(); j++) {
                if (visited[connections[index][j]] != 1) {
                    current.push_back(connections[index][j]);
                    visited[connections[index][j]] = 1;
                }
            }
        }
        ans = max(ans, count);
    } 
    cout << ans;
}