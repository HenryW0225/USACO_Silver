#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> graph;
vector<bool> visited;
bool contradiction = false;

void dfs(int index) {
    for (auto it : adj[index]) {
        if (graph[it.first] == 0) {
            graph[it.first] = graph[index] * it.second;
        } else if (graph[it.first] != graph[index] * it.second) {
            contradiction = true;
        }
        if (!visited[it.first]) {
            visited[it.first] = true;
            dfs(it.first);
        }
    }
}

int main() {
    ifstream cin("revegetate.in");
    ofstream cout("revegetate.out");
    int N, M, a, b;
    char c; 
    cin >> N >> M;
    adj = vector<vector<pair<int, int>>>(N);
    graph = vector<int>(N);
    visited = vector<bool>(N);

    for (int i = 0; i < M; i++) {
        cin >> c >> a >> b;
        if (c == 'S') {
            adj[a-1].push_back(make_pair(b-1, 1));
            adj[b-1].push_back(make_pair(a-1, 1));
        } else {
            adj[a-1].push_back(make_pair(b-1, -1));
            adj[b-1].push_back(make_pair(a-1, -1));
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            ans++;
            visited[i] = true;
            graph[i] = 1;
            dfs(i);
        }
    }

    if (contradiction || ans == 0) {
        cout << 0;
    } else {
        cout << 1;
        for (int i = 0; i < ans; i++) {
            cout << 0;
        }
    }
}