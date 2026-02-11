#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> adjF;
vector<vector<int>> adjR;
vector<bool> visited;

void dfs(int index, bool direction) {
    if (direction) {
        for (auto it : adjF[index]) {
            if (!visited[it]) {
                visited[it] = true;
                dfs(it, direction);
            }
        }
    } else {
        for (auto it : adjR[index]) {
            if (!visited[it]) {
                visited[it] = true;
                dfs(it, direction);
            }
        }
    }
}


int main() {
    int a, b;
    cin >> N >> M;
    visited = vector<bool>(N);
    adjF = vector<vector<int>>(N);
    adjR = vector<vector<int>>(N);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adjF[a - 1].push_back(b - 1);
        adjR[b - 1].push_back(a - 1);
    }

    visited[0] = true;
    dfs(0, true);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i + 1 << endl;
            return 0;
        }
    }

    visited = vector<bool>(N);
    visited[0] = true;
    dfs(0, false);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << i+1 << " " << 1 << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<bool> visited;
vector<bool> complete;
vector<vector<int>> connections;
vector<vector<int>> pikachu;
vector<vector<int>> adj;

void dfs(int start, int index) {
    connections[start].push_back(index);
    if (complete[index] || complete[start]) {
        complete[start] = true;
        return;
    }
    for (auto it : adj[index]) {
        if (!visited[it]) {
            visited[it] = true;
            dfs(start, it);
        }
    }
}


int main() {
    int a, b, index;
    cin >> N >> M;
    complete = vector<bool>(N);
    adj = vector<vector<int>>(N);
    connections = vector<vector<int>>(N);
    pikachu = vector<vector<int>>(N);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        pikachu[b - 1].push_back(a - 1);
    }

    bool ans = true;
    for (int i = N-1; i > -1; i--) {
        if (complete[i]) {
            for (auto it : pikachu[i]) {
                complete[it] = true;
            }
            continue;
        }
        visited = vector<bool>(N);
        visited[i] = true;
        
        dfs(i, i);
        if (complete[i] || (int) connections[i].size() == N) {
            complete[i] = true;
            for (auto it : pikachu[i]) {
                complete[it] = true;
            }
            continue;
        }
        ans = false;
        index = i;
        break;
    }


    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        sort(connections[index].begin(), connections[index].end());
        for (int i = 0; i < (int) connections[index].size(); i++) {
            if (connections[index][i] != i) {
                cout << index + 1 << " " << i + 1 << endl;
                return 0;
            }
        }
        cout << index + 1 << " " << connections[index].size() + 1 << endl; 
    }
} */