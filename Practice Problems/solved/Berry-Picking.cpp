#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ifstream cin("berries.in");
    ofstream cout("berries.out");
    int N, K, ans = 0;
    cin >> N >> K;
    int berries[N];
    for (int i = 0; i < N; i++) {
        cin >> berries[i];
    } sort(berries, berries + N);
    vector<int> bessie;
    vector<int> elsie;
    for (int i = 0; i < K/2; i++) {
        if (N - 1 - i < 0) {
            break;
        } elsie.push_back(berries[N - 1 - i]);
        if (N - 1 - K/2 - i < 0) {
            break;
        } bessie.push_back(berries[N - 1 - K/2 - i]);
        ans += berries[N - 1 - K/2 - i];
    } sort(bessie.begin(), bessie.end());
    sort(elsie.begin(), elsie.end());
    int smallest_index = 0, largest_index = K/2 - 1;
    while(floor(elsie[K/2 - 1]/2) >= bessie[largest_index]) {
        if (elsie[0] < floor(elsie[K/2 - 1]/2)) {
            bessie.push_back(elsie[0]);
            elsie[0] = floor(elsie[K/2 - 1]/2);
            elsie[K/2 - 1] -= elsie[0];
        } else {
            bessie.push_back(floor(elsie[K/2 - 1]/2));
            elsie[K/2-1] -= bessie[largest_index + 1];
        }
        ans -= bessie[smallest_index];
        smallest_index += 1;
        largest_index += 1;
        ans += bessie[largest_index];
        sort(elsie.begin(), elsie.end());
    } cout << ans;
}




#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> temp;
int mod = 0;

bool modsort(int p, int q) {
    return p%mod < q%mod;
}

int main() {
    ifstream cin("berries.in");
    ofstream cout("berries.out");
    int N, K, ans = 0, total, best = 0;
    cin >> N >> K;
    int berries[N];
    for (int i = 0; i < N; i++) {
        cin >> berries[i];
        temp.push_back(berries[i]);
    } sort(berries, berries + N);
    for (int i = 1; i < berries[N-1] + 1; i++) {
        total = 0;
        mod = i;
        ans = 0;
        for (int j = N-1; j > -1; j--) {
            total += berries[j]/mod;
            if (berries[j]/mod == 0) {
                break;
            } 
        }
        ans += min(max(total-K/2, 0), K/2)*mod;
        //cout << mod << " " << total << " " << ans << endl;
        if (total < K) {
            sort(temp.begin(), temp.end(), modsort);
            //for (int i = 0; i < N; i++) {
            //   cout << temp[i] << " ";
            //} cout << endl;
        }for (int j = N-1-max(K/2 - total, 0); j > N-1-(K-total); j--) {
            if (j < 0) {
                break;
            } ans += temp[j]%mod;
        } best = max(ans, best);
        //cout << ans << " " << best << endl;
    } cout << best;
}
