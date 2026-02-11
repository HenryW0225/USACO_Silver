#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    ifstream cin("haybales.in");
    ofstream cout("haybales.out");
    int N, Q, x, y;
    cin >> N >> Q;
    int haybales[N];
    for (int i = 0; i < N; i++) {
        cin >> haybales[i];
    }
    sort(haybales, haybales + N);
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        cout << upper_bound(haybales, haybales + N, y) - lower_bound(haybales, haybales + N, x) << endl;
    }
}
