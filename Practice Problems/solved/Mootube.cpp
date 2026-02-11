#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<pair<int, int>>> adj;
int K, ans;

void dfs(int cur, int prev) {
    ans++;
    for (auto it : adj[cur]) {
        if (it.first != prev && it.second >= K) {
            dfs(it.first, cur);
        }
    }
}

int main() {
    ifstream cin ("mootube.in");
    ofstream cout ("mootube.out");
    int N, Q, a, b, c;
    cin >> N >> Q;
    adj.resize(N);
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b >> c;
        adj[a-1].push_back(make_pair(b-1, c));
        adj[b-1].push_back(make_pair(a-1, c));
    }

    int video = 0;
    for (int i = 0; i < Q; i++) {
        cin >> K >> video;
        ans = -1;
        video -= 1;
        dfs(video, video);
        cout << ans << endl;
    }
}