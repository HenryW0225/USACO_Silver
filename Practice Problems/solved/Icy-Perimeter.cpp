#include <iostream>
#include <array>
#include <fstream>
using namespace std;

int N, area, perimeter;
char ice[1000][1000];
bool visited[1000][1000];
pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


void floodfill(int i, int j) {
    int count = 0, x, y;
    area++;
    for (int t = 0; t < 4; t++) {
        x = i + directions[t].first;
        y = j + directions[t].second;
        if (x < 0 || x >= N || y < 0 || y >= N) {
            count++;
            continue;
        }
        if (ice[x][y] == '#') {
            if (!visited[x][y]) {
                visited[i + directions[t].first][j + directions[t].second] = true;
                floodfill(i + directions[t].first, j + directions[t].second);
            }
        } else {
            count++;
        }
    }
    perimeter += count;
}

int main() {
    ifstream cin("perimeter.in");
    ofstream cout("perimeter.out");
    int bestA = 0, bestP = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ice[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ice[i][j] == '#' && !visited[i][j]) {
                visited[i][j] = true;
                perimeter = 0;
                area = 0;
                floodfill(i, j);
                if (area > bestA) {
                    bestA = area;
                    bestP = perimeter;
                } else if (area == bestA) {
                    bestP = min(bestP, perimeter);
                }
            }
        }
    }
    cout << bestA << " " << bestP << endl;
}