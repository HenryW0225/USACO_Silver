#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    ifstream cin ("rental.in");
    ofstream cout ("rental.out");
    int N, M, R, x, y, stoppages = -1, temp;
    long long ans = 0, addition = 0;
    cin >> N >> M >> R;
    int beststores = M-1;
    int cows[N];
    int rents[R];
    pair<int, int> stores[M];
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    } 
    
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        stores[i] = make_pair(y, x);
    }
    
    for (int i = 0; i < R; i++) {
        cin >> rents[i];
    } 
    
    sort(cows, cows + N);
    sort(stores, stores + M);
    sort(rents, rents + R);

    for (int i = N-1; i > -1; i--) {
        addition = 0;
        while (cows[i] > 0 and beststores >= 0) {
            temp = min(cows[i], stores[beststores].second);
            addition += (long long) temp * stores[beststores].first;
            cows[i] -= temp;
            stores[beststores].second -= temp;
            if (stores[beststores].second == 0) {
                beststores -= 1;
            }
        } 
        if (i > R-1 or addition > (long long) rents[R - 1 - i]) {
            ans += addition;
        } else {
            stoppages = i;
            break;
        } 
    } 
    for (int i = 0; i < stoppages + 1; i++) {
        ans += (long long) rents[R-1-i];
    }
    cout << ans;
}
