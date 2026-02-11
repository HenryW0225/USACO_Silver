#include <fstream>
#include <iostream>
#include <vector>
#include <array>
using namespace std;

int N, M;
int ans = 0;
vector<pair<int, int>> barn[100][100];
int visited[100][100] = {0};
int a, b, c, d;

bool check(int x, int y) {
    if (x < 0 or y < 0 or x > N-1 or y > N-1) {
        return false;
    }
    if (visited[x][y] != 1) {
        return false;
    }
    return true;
}

void floodfill(int x, int y) {
    visited[x][y] = 2;
    for (auto it : barn[x][y]) {
        if ((visited[it.first][it.second]) == 0) {
            visited[it.first][it.second] = 1;
        }
    }
    if (check(x-1, y)) {
        floodfill(x-1, y);
    }
    if (check(x+1, y)) {
        floodfill(x+1, y);
    }
    if (check(x, y-1)) {
        floodfill(x, y-1);
    }
    if (check(x, y+1)) {
        floodfill(x, y+1);
    }
}

bool finished() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 2) {
                if (check(i-1, j)) {
                    a = i-1;
                    b = j;
                    return false;
                }
                if (check(i+1, j)) {
                    a = i+1;
                    b = j;
                    return false;
                }
                if (check(i, j-1)) {
                    a = i;
                    b = j-1;
                    return false;
                }
                if (check(i, j+1)) {
                    a = i;
                    b = j+1;
                    return false;
                }
            }
        }
    } 
    return true;
}

int main() {
    ifstream cin("lightson.in");
    ofstream cout("lightson.out");
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c >> d;
        barn[a-1][b-1].push_back(make_pair(c-1, d-1));
    }
    floodfill(0, 0);
    while (!finished()) {
        floodfill(a, b);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] != 0) {
                ans += 1;
            }
        }
    } cout << ans;
}
