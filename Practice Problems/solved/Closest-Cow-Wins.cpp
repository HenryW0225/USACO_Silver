#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ll K, M, N, a, b;
    cin >> K >> M >> N;
    pair<ll, ll> positions[K + M + 2];
    vector<ll> answer;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        positions[i] = make_pair(a, b);
    }
    for (int i = K; i < K+M; i++) {
        cin >> a;
        positions[i] = make_pair(a, -1);
    }
    positions[K + M] = make_pair(-10e9 - 1, -1); // start position
    positions[K + M + 1] = make_pair(2 * 10e9 + 1, -1); // end position
    sort(positions, positions + K + M + 2);

    /*cout << endl << endl;
    cout << "positions" << endl;
    for (auto it : positions) {
        cout << it.first << " " << it.second << endl;
    } cout << endl;*/

    ll intervalSum = 0, startIndex = 0, endIndex = 1, l, r, ans, current, limitL, limitR;
    while (startIndex != K+M+1) {
        while (positions[endIndex].second != -1) {
            intervalSum += positions[endIndex].second;
            endIndex++;
        }
        
        //cout << "INTERVAL" << endl;
        //cout << startIndex << " " << endIndex << " " << intervalSum << endl;


        ans = 0;
        current = 0;
        l = startIndex + 1;
        r = startIndex + 1;
        while (endIndex - startIndex != 1) {
            limitL = 2 * positions[l].first - positions[startIndex].first;
            limitR = 2 * positions[r].first - positions[endIndex].first;
            //cout << l << " " << r << endl;
            while (limitL - limitR > 0 && r < endIndex) {
                current += positions[r].second;
                ans = max(current, ans);
                r++;
                limitR = 2 * positions[r].first - positions[endIndex].first;
            }
            if (r == endIndex) {
                break;
            }
            //limitR = 2 * positions[r].first - positions[endIndex].first;
            while (limitL - limitR <= 0) {
                current -= positions[l].second;
                l++;
                limitL = 2 * positions[l].first - positions[startIndex].first;
            }
        }

        //cout << ans << " " << endl << endl << endl;
        if (ans != 0) {
            answer.push_back(ans);
        }
        if (intervalSum - ans != 0) {
            answer.push_back(intervalSum - ans);
        }
        startIndex = endIndex;
        endIndex++;
        intervalSum = 0;
    }

    ans = 0;
    sort(answer.begin(), answer.end());

    /*for (auto it : answer) {
        cout << it << " ";
    } cout << endl;*/

    for (int i = answer.size() - 1; i > answer.size() - 1 - N; i--) {
        if (i > -1) {
            ans += answer[i];
        }
    }
    cout << ans;
}