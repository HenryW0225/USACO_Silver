#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int M, N, middle, ans = 0;
vector<vector<int>> course;
vector<vector<bool>> visited;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool check(int i, int j, int prevI, int prevJ) {
    if (i < 0 || i >= M || j < 0 || j >= N || visited[i][j]) {
        return false;
    }
    if (abs(abs(course[i][j]) - abs(course[prevI][prevJ])) > middle) {
        return false;
    }
    return true;
}

void floodfill(int i, int j) {
    if (course[i][j] < 0) {
        ans++;
    }
    for (int t = 0; t < 4; t++) {
        if (check(i + directions[t].first, j + directions[t].second, i, j)) {
            visited[i + directions[t].first][j + directions[t].second] = true;
            floodfill(i + directions[t].first, j + directions[t].second);
        }
    }
}



int main() {
    ifstream cin ("ccski.in");
    ofstream cout ("ccski.out");
    int a, b;
    cin >> M >> N;
    course = vector<vector<int>>(M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a;
            course[i].push_back(a + 1);
        }
    }

    int start = 0, end = 0, amount = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a;
            if (a == 1) {
                course[i][j] *= -1;
                start = i;
                end = j;
                amount++;
            }
        }
    }

    int low = 0, high = 1000000000;
    while (low < high) {
        middle = (low + high)/2;
        ans = 0;
        visited = vector<vector<bool>>(M, vector<bool>(N, false));
        visited[start][end] = true;
        floodfill(start, end);
        if (ans == amount) {
            high = middle;
        }
        else {
            low = middle + 1;
        }
    }
    cout << low << endl;
}