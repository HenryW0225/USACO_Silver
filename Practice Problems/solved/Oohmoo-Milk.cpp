#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007LL;

int main() {
    //ifstream cin ("unsolved/input.in");
    //ofstream cout ("unsolved/output.out");
    ll N, D, A, B, temp, ans = 0;
    cin >> N >> D >> A >> B;
    vector<ll> milk;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        milk.push_back(temp);
    }
    sort(milk.begin(), milk.end());
    ll bl = N - B, br = N - B, il = N - A, ir = N - 1, num = milk[N-B], r = 0;
    while (bl > il && milk[bl-1] == num) {
        bl--;
    }
    while (br < ir && milk[br + 1] == num) {
        br++;
    }

    //cout << "bl: " << bl << " br: " << br << " num: " << num << endl;

    /*for (int i = il; i <= ir; i++) {
        cout << milk[i] <<  " "; 
    } cout << endl << endl << endl;*/

    ll day = 0;
    ll dl, dr, dc, borderSize, intersection;
    while (day < D) {
        borderSize = br - bl + 1;
        intersection = N - B - bl;

        //cout << endl << day << endl;
        //cout << "borderSize: " << borderSize << " intersection: " <<  intersection << endl;

        if (bl > il) {
            //dl = ((num - milk[bl - 1] - day - 1) * borderSize + r + 1)/(borderSize - intersection);
            long double temp1 = (long double) ((num - milk[bl - 1] - day - 1) * borderSize + r + 1);
            long double temp2 = (long double) (borderSize - intersection);
            dl = (ll) ceil(temp1/temp2);
        } 
        else {
            dl = 10e9+1;
        }

        if (br < ir && intersection != 0) {
            long double temp1 = (long double) (milk[br + 1] - num - 1) * borderSize + 1 - r;
            long double temp2 = (long double) (intersection);
            dr = (ll) ceil(temp1/temp2);
        }
        else {
            dr = 10e9+1;
        }

        //cout << "dl: " << dl << " dr: " << dr << endl;
        
        
        if (day + dl > D && day + dr > D) {
            break;
        }
        
        dc = min(dl, dr);
        num += (intersection * dc + r)/borderSize;
        r = (intersection * dc + r)%borderSize;
        day += dc;

        if (dc == dr) {
            while (br < ir && milk[br + 1] == num + (ll) ceil((long double) r/ (long double) borderSize)) {
                br++;
                r++;
                borderSize++;
            }
        } 
        if (dc == dl) {
            while (bl > il && milk[bl - 1] + day == num) {
                bl--;
            }
        } 
        //cout << "bl: " << bl << " br: " << br << " num: " << num << " r: " << r << endl;
    }

    dc = D - day;
    num += (intersection * dc + r)/borderSize;
    r = (intersection * dc + r)%borderSize;
    borderSize = br - bl + 1;

    for (int i = 0; i < il; i++) {
        ans = (ans + milk[i] * milk[i]) % MOD;
    }
    //cout << ans << endl;
    for (int i = il; i < bl; i++) {
        milk[i] += D;
        ans = (ans + milk[i] * milk[i]) % MOD;
    }
    //cout << ans << endl;
    for (int i = br + 1; i < N; i++) {
        ans = (ans + milk[i] * milk[i]) % MOD;
    }
    //cout << ans << endl;
    for (int i = 0; i < borderSize - r; i++) {
        ans = (ans + num * num) % MOD;
    }
    //cout << ans << endl;
    num += 1;
    for (int i = 0; i < r; i++) {
        ans = (ans + num * num) % MOD;
    }

    cout << ans;
}

/*

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    typedef long long ll;
    const ll MOD = 1000000007LL;
    ll N, D, A, B, temp;
    cin >> N >> D >> A >> B;
    vector<ll> milk;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        milk.push_back(temp);
    }
    sort(milk.begin(), milk.end());
    vector<ll> amounts(milk.end() - A, milk.end());
    
    ll ans = 0;
    for (int i = 0; i < milk.size() - A; i++) {
        ans += (milk[i] * milk[i]) % MOD;
    }

    ll sum = 0;
    for (int i = 0; i < amounts.size(); i++) {
        sum += amounts[i];
    }
    sum += D * (A - B);
    ll base = sum/A;
    ll mod = sum%A;
    ll ans1 = (base * base) % MOD;
    ans1 = (ans1 * (A - mod)) % MOD;

    ll ans2 = ((base + 1) * (base + 1)) % MOD;
    ans2 = (ans2 * mod) % MOD;
    cout << (ans + ans1 + ans2) % MOD;

}

*/