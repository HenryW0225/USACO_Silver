#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <iterator>
using namespace std;

int main() {
    typedef long long ll;
    ll N;
    cin >> N;
    ll a[N];
    ll b[N];
    vector<ll> aFirst[N];
    vector<ll> aSecond[N];
    vector<ll> aPositions[N];
    vector<ll> bFirst[N];
    vector<ll> bSecond[N];
    vector<ll> bPositions[N];

    ll middle = (N-1)/2;

    //cout << endl << middle << endl;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (i <= middle) {
            aFirst[a[i] - 1].push_back(i);
        } else {
            aSecond[a[i] - 1].push_back(N-1-i);
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        if (i <= middle) {
            bFirst[b[i] - 1].push_back(i);
        } else {
            bSecond[b[i] - 1].push_back(N-1-i);
        }
    }

    ll answer = 0;

    for (int i = 0; i < N; i++) {
        if (a[i] == b[i]) {
            answer += (long long) (1LL * i * (i+1))/2 + ((N-1-i) * (N-i))/2;
        }
    }
    
    //cout << answer << endl << endl;


    for (int i = 0; i < N; i++) {
        reverse(aSecond[i].begin(), aSecond[i].end());
        reverse(bSecond[i].begin(), bSecond[i].end());
        merge(aFirst[i].begin(), aFirst[i].end(),
               aSecond[i].begin(), aSecond[i].end(),
               back_inserter(aPositions[i]));
        merge(bFirst[i].begin(), bFirst[i].end(),
               bSecond[i].begin(), bSecond[i].end(),
               back_inserter(bPositions[i]));
        
        if (aPositions[i].size() == 0 or bPositions[i].size() == 0) {
            continue;
        }

        /*cout << i << endl;
        for (auto it : aPositions[i]) {
            cout << it << " ";
        } cout << endl;
        for (auto it : bPositions[i]) {
            cout << it << " ";
        } cout << endl << endl;*/

        ll sum = 0;
        ll index = aPositions[i].size() - 1;
        for (int j = 0; j < aPositions[i].size(); j++) {
            sum += (long long) aPositions[i][j] + 1;
        }

        for (int j = bPositions[i].size() - 1; j > -1; j--) {
            while (index > -1 && bPositions[i][j] < aPositions[i][index]) {
                sum -= (long long) aPositions[i][index] + 1;
                index--;
            }
            answer += (long long) sum + (aPositions[i].size() - 1 - index) * (bPositions[i][j] + 1);
        }
    }

    cout << answer;
}



/*#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
using namespace std;

int main() {
    int N, temp;
    cin >> N;
    int cows[N], checkups[N], freq[N];
    vector<int> list1[N], list2[N];
    set<int> observed;

    for (int i = 0; i < N; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> cows[i];
        list1[cows[i] - 1].push_back(i);
        freq[cows[i] - 1] = 1;
    }
    for (int i = 0; i < N; i++) {
        cin >> checkups[i];
        list2[checkups[i] - 1].push_back(i);
        if (freq[checkups[i] - 1] == 1) {
            observed.insert(checkups[i] - 1);
        }
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        if (cows[i] == checkups[i]) { 
            ans += (long long) N + (i * (i - 1))/2 + ((N - 1 - i) * (N - 2 - i))/2 - 1;
        }
    }
    //cout << ans << endl;
    for (auto index : observed) {
        //cout << endl << index << " ";

        vector<int> low;
        vector<int> high;
        for (int i = 0; i < size(list1[index]); i++) {
            if (list1[index][i] <= (N-1)/2) {
                low.push_back(list1[index][i]);
            } else {
                high.push_back(list1[index][i]);
            }
        } 

        int lower_bound = 0, upper_bound = size(list2[index]) - 1;
        int sum = 0;
        for (int i = 0; i < size(low); i++) {
            while (true) {
                
                if (lower_bound <= upper_bound && list2[index][lower_bound] <= (N-1)/2 && list2[index][lower_bound] + 1 < low[i] + 1) {
                    sum += list2[index][lower_bound] + 1;
                    lower_bound += 1;
                } else {
                    break;
                }
            }
            while (true) {
                if (lower_bound <= upper_bound && list2[index][upper_bound] > (N-1)/2 && N - list2[index][upper_bound] < low[i] + 1) {
                    sum += N - list2[index][upper_bound];
                    upper_bound -= 1;
                } else {
                    break;
                }
            }
            ans += (long long) sum + (upper_bound - lower_bound + 1) * (low[i] + 1);
        }

        lower_bound = 0;
        upper_bound = size(list2[index]) - 1;
        sum = 0;
        for (int i = 0; i < size(high); i++) {
            while (true) {
                if (lower_bound <= upper_bound && list2[index][lower_bound] <= (N-1)/2 && list2[index][lower_bound] + 1 < N - high[i]) {
                    sum += list2[index][lower_bound] + 1;
                    lower_bound += 1;
                } else {
                    break;
                }
            }
            while (true) {
                if (lower_bound <= upper_bound && list2[index][upper_bound] > (N-1)/2 && N - list2[index][upper_bound] < N - high[i]) {
                    sum += N - list2[index][upper_bound];
                    upper_bound -= 1;
                } else {
                    break;
                }
            }
            ans += (long long) sum + (upper_bound - lower_bound + 1) * (N - high[i]);
        }

    }
    cout << ans << endl;
} */
































/*#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int calculate(int a) {
    return a + ((a)*(a-1))/2;
}

int main() {
    int N, temp;
    cin >> N;
    long long ans = 0;
    pair<int, int> cows[N];
    pair<int, int> checkups[N];

    for (int i = 0; i < N; i++) {
        cin >> temp;
        cows[i] = make_pair(temp, i);
    }
    for (int i = 0; i < N; i++) {
        cin >> temp;
        checkups[i] = make_pair(temp, i);
    }

    sort(cows, cows + N);
    sort(checkups, checkups + N);

    for (int i = 0; i < N; i++) {
        cout << cows[i].first << " " << cows[i].second << " | ";
    } cout << endl;
    for (int i = 0; i < N; i++) {
        cout << checkups[i].first << " " << checkups[i].second << " | ";
    } cout << endl;

    int index1 = 0, index2 = 0, laststop = -1;

    while (index1 < N && index2 < N) {
        cout << index1 << " " << index2 << " " << cows[index1].first << " " << cows[index1].second << " " << cows[index2].first << " " << cows[index2].second << " " << ans << endl;

        if (cows[index1].first > checkups[index2].first) {
            index2++;
        } else if (cows[index1].first < checkups[index2].first) {
            index1++;
            if (laststop != -1) {
                index2 = laststop;
                laststop = -1;
            }
        } else {
            if (cows[index1].second == checkups[index2].second) {
                ans += (long long) calculate(cows[index1].second);
                ans += (long long) calculate(N - 1 - cows[index1].second);
                ans += (long long) min(cows[index1].second, N - 1 - cows[index1].second) + 1;
            } else if (cows[index1].second > checkups[index2].second) {
                ans += (long long) min(N - 1 - cows[index1].second, checkups[index2].second) + 1;
            } else {
                ans += (long long) min(cows[index1].second, N - 1 - checkups[index2].second) + 1;
            }
            if (laststop == -1) {
                laststop = index2;
            }
            if (index2 != N-1) {
                index2++;
            } else {
                index1++;
                if (laststop != -1) {
                    index2 = laststop;
                    laststop = -1;
                }
            }
            
        }
    }

    cout << ans;
}*/