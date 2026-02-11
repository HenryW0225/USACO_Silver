#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    //ifstream cin ("time.in");
    //ofstream cout ("time.out");
    int N, M, C;
    cin >> N >> M >> C;
    int cities[N];
    for (int i = 0; i < N; i++) {
        cin >> cities[i];
    }

    vector<int> connections[N];
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        connections[a-1].push_back(b-1);
    }
}