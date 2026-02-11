/*#include <iostream>
#include <array>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    //ifstream cin("moocast.in");
    //ofstream cout("moocast.out");
    int N;
    int cows[N][3];
    for (int i = 0; i < N; i++) {
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }
    vector<int> connections[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            } 
            if ((cows[j][0] - cows[i][0])*(cows[j][0] - cows[i][0]) + (cows[j][1] - cows[i][1])*(cows[j][1] - cows[i][1]) <= cows[i][2]) {
                connections[i].push_back(j);
            }
        }
    }
    vector<int> current_cows;
    int visited[N];
    int count;
    for (int i = 0; i < N; i++) {
        count = 1;
        for (int j = 0; j < N; j++) {
            visited[j] = 0;
        }
        current_cows = {i};
        while (current_cows.size() != 0)
    }
}*/
