



/*#include <iostream>
#include <array>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int main() {
    ll T, N, a, b;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        cin >> N;
        pair<ll, ll> jobs[N];
        map<ll, ll> amounts{};
        map<ll, ll> completed{};
        set<ll> times{};
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            jobs[i] = make_pair(a, b);
            times.insert(b);
            amounts[b] += 1;
        }
        sort(jobs, jobs + N);
        
        ll ans = 0, index = 0, current = 0, best = -1;

        while (index < N) {
            if (times.size() == 0) {
                index = N;
            }
            else if (jobs[index].first >= current) {
                ans++;
                best = *times.begin();
                current += best;
                amounts[best] -= 1;
                completed[best] += 1;
                if (amounts[best] == 0) {
                    times.erase(best);
                }
            }
            else {
                if (completed[jobs[index].second] > 0) {
                    completed[jobs[index].second] -= 1;
                } else {
                    amounts[jobs[index].second] -= 1;
                    if (amounts[jobs[index].second] == 0) {
                        times.erase(jobs[index].second);
                    }   
                }
                index++;
            }
        }
        cout << ans << endl;
    }
}*/
