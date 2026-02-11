#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll N, Q, a, b, c;
    cin >> N >> Q;
    pair<ll, ll> values[2*N];
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        values[2*i] = make_pair(a-1, -c);
        values[2*i+1] = make_pair(b-1, c);
    }
    sort(values, values + 2*N);
    vector<tuple<ll, ll, ll>> positions;
    positions.push_back(make_tuple(10e9, 0, 0));
    ll amount, current = 0, sum = 0;

    for (int i = 2*N-1; i > -1; i--) {
        if (values[i].first < 0) {
            continue;
        }
        sum += values[i].second;
        while (i != 0 && values[i].first == values[i-1].first) {
            i--;
            sum += values[i].second;
        }
        amount = (get<0>(positions[positions.size()-1]) - values[i].first) * (current) + sum + get<1>(positions[positions.size()-1]);
        positions.push_back(make_tuple(values[i].first, amount, current));
        current += sum;
        sum = 0;

    }
    positions.push_back(make_tuple(-1, 0, current));
    reverse(positions.begin(), positions.end());

    ll left, right, middle, l, r, ans;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        b -= 1;
        left = 0;
        right = positions.size() - 1;
        while (left < right) {
            middle = (left+right)/2;
            if (get<0>(positions[middle]) >= a) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        l = left;

        left = 0;
        right = positions.size() - 1;
        while (left < right) {
            middle = (left+right+1)/2;
            if (get<0>(positions[middle]) <= b) {
                left = middle;
            } else {
                right = middle - 1;
            }
        }
        r = left;


        ans = get<1>(positions[l]) - get<1>(positions[r+1]);
        ans += (get<0>(positions[l]) - a) * get<2>(positions[l-1]);
        ans -= (get<0>(positions[r+1]) - b - 1) * get<2>(positions[r]); 
        cout << ans << endl;
        
    }
}