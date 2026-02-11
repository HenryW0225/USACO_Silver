#include <iostream>
#include <algorithm>
#include <fstream>
#include <array>
#include <map>
using namespace std;

int main() {
    ifstream cin ("measurement.in");
    ofstream cout ("measurement.out");
    int N, G, a, b, c, ans = 0, before;
    cin >> N >> G;
    tuple<int, int, int> log[N];
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        log[i] = make_tuple(a, b, c);
    }
    sort(log, log + N);

    map<int, int> cows;
    map<int, int> milk;
    milk[0] = N + 1;

    for (int i = 0; i < N; i++) {
        before = cows[get<1>(log[i])];
        cows[get<1>(log[i])] += get<2>(log[i]);
        
        bool prev = milk.rbegin()->first == before;
        int count = milk.rbegin()->second;

        milk[before] -= 1;
        if (milk[before] == 0) {
            milk.erase(before);
        }
        milk[cows[get<1>(log[i])]] += 1;

        bool current = milk.rbegin()->first == cows[get<1>(log[i])];
        if (prev) {
            if (count == 1 && current && milk.rbegin()->second == 1) {
                continue;
            }
            ans++;
        } else if (current) {
            ans++;
        }
    } 
    cout << ans;
}

/*#include <iostream>
#include <algorithm>
#include <fstream>
#include <array>
#include <map>
using namespace std;

int main() {
    ifstream cin ("measurement.in");
    ofstream cout ("measurement.out");
    int N, G, a, b, c, ans = 0, before;
    cin >> N >> G;
    tuple<int, int, int> log[N];
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        log[i] = make_tuple(a, b, c);
    }
    sort(log, log + N);

    cout << endl;
    for (auto it : log) {
        cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
    }

    map<int, int> cows;
    map<int, int> milk;
    bool prev;
    milk[0] = N + 1;

    for (int i = 0; i < N; i++) {
        prev = false;
        before = cows[get<1>(log[i])];
        cows[get<1>(log[i])] += get<2>(log[i]);
        
        auto key = milk.rbegin();
        if (before == key->first) {
            if (key->second > 1) {
                ans++;
            } else {
                prev = true;
            }
        } else if (cows[get<1>(log[i])] >= key->first) {
            ans++;
        }

        milk[before] -= 1;
        if (milk[before] == 0) {
            milk.erase(before);
        }
        milk[cows[get<1>(log[i])]] += 1;

        key = milk.rbegin();
        
        if (prev && (key->first != cows[get<1>(log[i])] || key->second > 1)) {
            ans++;
        }


    } 
    cout << ans;
}*/