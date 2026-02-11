/*#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream cin ("fenceplan.in");
    ofstream cout ("fenceplan.out");
    int N, M;
    cin >> N >> M;
    int cows[N][2];
    for (int i = 0; i < N; i++) {
        cin >> cows[i][0] >> cows[i][1];
    }
    vector<int> connections[N];
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        connections[a-1].push_back(b-1);
        connections[b-1].push_back(a-1);
    }
    int visited[N] = {0};
    long ans = 10e9;
    
    for (int i = 0; i < N; i++) {
        if (visited[i] == 1) {
            continue;
        } 
        int max_x = 0, max_y = 0, min_x = 10e8, min_y = 10e8;
        vector<int> group = {};
        group.push_back(i);
        while (group.size() > 0) {
            int index = group[group.size()-1];
            group.pop_back();
            max_x = max(max_x, cows[index][0]);
            min_x = min(min_x, cows[index][0]);
            max_y = max(max_y, cows[index][1]);
            min_y = min(min_y, cows[index][1]);
            visited[index] = 1;
            for (auto cow : connections[index]) {
                if (visited[cow] == 0) {
                    group.push_back(cow);
                }
            } 
            
        }
        ans = min(ans, (long) 2*(max_x - min_x + max_y - min_y));
    } 
    cout << ans;
}*/
