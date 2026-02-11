#include <iostream>
#include <fstream>
#include <vector>
#include <array>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<bool> visited;
int X, ans;

void dfs(int index) {
    ans++;
    for (auto it : adj[index]) {
        if  (!visited[it.first] && X >= it.second) {
            visited[it.first] = true;
            dfs(it.first);
        }
    }
}

int main() {
    ifstream cin("moocast.in");
    ofstream cout("moocast.out");
    int N;
    cin >> N;
    int cows[N][2];
    adj = vector<vector<pair<int, int>>>(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i][0] >> cows[i][1];
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            int distance = (cows[i][0] - cows[j][0]) * (cows[i][0] - cows[j][0]) + (cows[i][1] - cows[j][1]) * (cows[i][1] - cows[j][1]);
            adj[i].push_back({j, distance});
            adj[j].push_back({i, distance});
        }
    }
    int low = 0, high = 1250000001;

    while (low < high) {
        X = (low + high)/2;
        visited = vector<bool>(N);
        ans = 0;
        visited[0] = true;
        dfs(0);
        if (ans == N) {
            high = X;
        } else {
            low = X + 1;
        }
    } 
    cout << low;
}



/*#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ifstream cin ("moocast.in");
    ofstream cout ("moocast.out");
    int N;
    cin >> N;
    int cows[N][2];
    for (int i = 0; i < N; i++) {
        cin >> cows[i][0] >> cows[i][1];
    }

    int distances[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            distances[i][j] = pow(cows[i][0] - cows[j][0], 2) + pow(cows[i][1] - cows[j][1], 2);
        }
    }
    int ans = 10e6;
    int current = 0;
	for (int dif = 35356; dif > 0; dif /= 2) {
		while (current + dif <= 35356) { 
            int jump = current + dif;

            vector<int> connections[N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (distances[i][j] <= jump && i != j) {
                        connections[i].push_back(j);
                    }   
                }
            } 
            int best = 0;
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
                best = max(best, count);
            }
            if (best == N) {
                ans = min(ans, jump);
            }
            else {
                current += dif;
            }
        }
    }   
    cout << ans;
}*/