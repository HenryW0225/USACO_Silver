#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream cin ("planting.in");
    ofstream cout("planting.out");
    int N, x, y, sum;
    int max = 0;
    cin >> N;
    vector<vector<int>> connections(N);
    for (int i = 0; i < N-1; i++) {
        cin >> x >> y;
        x -= 1;
        y -= 1;
        connections[x].push_back(y);
        connections[y].push_back(x);
    } 
    for (int i = 0; i < N; i++) {
        sum = connections[i].size() + 1;
        if (sum > max) {
            max = sum;
        }
    } cout << max;
}
