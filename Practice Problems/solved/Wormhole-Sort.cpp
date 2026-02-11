#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> positions;                                                                                                                                  
vector<int> cows;
vector<int> spots;
vector<bool> visited;
int width;

void dfs(int index) {
    cows.push_back(positions[index]);
    spots.push_back(index);
    for (auto it : adj[index]) {
        if (it.second >= width && !visited[it.first]) {
            visited[it.first] = true;
            dfs(it.first);
        }
    }
}

int main() {
    ifstream cin ("wormsort.in");
    ofstream cout ("wormsort.out");
    int N, M, a, b, c;
    cin >> N >> M;
    adj = vector<vector<pair<int, int>>>(N);
    positions = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> a;
        positions[i] = a-1;
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1, c});
        adj[b-1].push_back({a-1, c});
    }
    int low = 0, high = 1000000001;
    bool possible = true;
    while (low < high) {
        possible = true;
        width = (low + high + 1)/2;
        visited = vector<bool>(N);
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                cows.clear();
                spots.clear();
                dfs(i);
                sort(cows.begin(), cows.end());
                sort(spots.begin(), spots.end());
                for (int i = 0; i < cows.size(); i++) {
                    if (cows[i] != spots[i]) {
                        possible = false;
                        break;
                    }
                }
            }
        }
        if (possible) {
            low = width;
        } else {
            high = width - 1;
        }
    }
    if (high == 1000000001) {
        cout << -1;
    } else {
        cout << low;
    }
}









































//not solved

/*#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
vector<pair<int, int>> connections[100000];
int visited[100000];

int dfs(int index, int target, int min_width) {
    if (index == target) {
        return min_width;
    }
    visited[index] = 1;
    int best = 0;
    for (int i = 0; i < connections[index].size(); i++) {
        if (visited[connections[index][i].first] == 0) {
            best = max(best, dfs(connections[index][i].first, target, min(min_width, connections[index][i].second)));
        }
    }
    visited[index] = 0;
    return best;
}

int main() {
    ifstream cin ("wormsort.in");
    ofstream cout ("wormsort.out");
    int M;
    cin >> N >> M;
    int cows[N];
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
        cows[i] -= 1;
    }
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        connections[a-1].push_back(make_pair(b-1, c));
        connections[b-1].push_back(make_pair(a-1, c));
    }

    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (cows[i] == i) {
            continue;
        }
        for (int j = 0; j < N; j++) {
            visited[j] = 0;
        }
        
        ans = min(ans, dfs(i, cows[i], INT_MAX));
    }
    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }
}*/