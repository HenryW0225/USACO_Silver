#include <iostream>
#include <array>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<int>> adj;
vector<char> type;
vector<int> group;
int number;

void dfs(int cur, int prev) {
    group[cur] = number;
    for (auto it : adj[cur]) {
        if (type[it] == type[cur] && it != prev) {
            dfs(it, cur);
        }
    }
}

int main() {
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    int N, M, a, b;
    char c;
    cin >> N >> M;
    adj = vector<vector<int>>(N);
    type = vector<char>(N);
    group = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> type[i];
    }

    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    number = 1;
    for (int i = 0; i < N; i++) {
        if (group[i] == 0) {
            dfs(i, i);
            number++;
        }
    }
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (group[a-1] == group[b-1] && type[a-1] != c) {
            cout << 0;
        } else {
            cout << 1;
        }
    }
}

/*#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

int main() {
    //ifstream cin("milkvisits.in");
    //ofstream cout("milkvisits.out");
    int N, M, a, b;
    char c;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    vector<char> type;

    for (int i = 0; i < N; i++) {
        cin >> c;
        type.push_back(c);
    }

    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        bool ans = false;
        queue<pair<int, int>> cows;
        cows.push({a-1, a-1});
        while (!cows.empty()) {
            if (cows.front().first == b-1) {
                ans = true;
                if (type[b-1] == c) {
                    cout << 1;
                } else {
                    cout << 0;
                }
                break;
            }
            if (type[cows.front().first] == c) {
                cows.pop();
                continue;
            }
            for (auto it : adj[cows.front().first]) {
                if (it == cows.front().second) {
                    continue;
                }
                cows.push({it, cows.front().first});
            }
            cows.pop();
        }
        if (!ans) {
            cout << 1;
        }
    }
}*/