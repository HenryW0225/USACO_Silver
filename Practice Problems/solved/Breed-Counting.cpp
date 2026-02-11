/*#include <iostream>
#include <array>
#include <fstream>
using namespace std;


int main() {
    ifstream cin ("bcount.in");
    ofstream cout("bcount.out");
    int N, Q, temp, temp2;
    cin >> N >> Q;
    int H[N+1] = {0};
    int G[N+1] = {0};
    int J[N+1] = {0};
    for (int i = 1; i < N+1; i++) {
        cin >> temp;
        H[i] = H[i-1];
        G[i] = G[i-1];
        J[i] = J[i-1];
        if (temp == 1) {
            H[i] += 1;
        } else if (temp == 2) {
            G[i] += 1;
        } else {
            J[i] += 1;
        }
    } for (int i = 0; i < Q; i++) {
        cin >> temp >> temp2;
        cout << H[temp2] - H[temp-1] << " " << G[temp2] - G[temp-1] << " " << J[temp2] - J[temp-1] << endl;
    }
}*/
