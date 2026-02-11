#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>
#include <tuple>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007LL;

int main() {
    ifstream cin("triangles.in");
    ofstream cout("triangles.out");
    ll N, a, b, xCurrent = 0, yCurrent = 0, index = 0;
    cin >> N;
    ll counts[N][2];
    for (int i = 0; i < N; i++) {
        counts[i][0] = 0;
        counts[i][1] = 0;
    }
    tuple<ll, ll, ll> triangles[N];

    vector<vector<pair<ll, ll>>> xCoords;
    vector<vector<pair<ll, ll>>> yCoords;
    set<ll> xAppearances;
    set<ll> yAppearances;


    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        a += 10000;
        b += 10000;
        triangles[i] = make_tuple(a, b, i);
        
    }
  

    sort(triangles, triangles + N);
    while (index < N) {
        vector<pair<ll, ll>> temp;
        temp.push_back(make_pair(get<1>(triangles[index]), get<2>(triangles[index])));
        index++;
        while (index < N && get<0>(triangles[index]) == get<0>(triangles[index - 1])) {
            temp.push_back(make_pair(get<1>(triangles[index]), get<2>(triangles[index])));
            index++;
        }
        if (temp.size() > 1) {
            xCoords.push_back(temp);
            xCurrent++;
        }
    }

    sort(triangles, triangles + N, [](const tuple<ll, ll, ll> &a, const tuple<ll, ll, ll> &b) {
        if (get<1>(a) != get<1>(b))
            return get<1>(a) < get<1>(b);
            return get<0>(a) < get<0>(b);
    });
    index = 0;
    while (index < N) {
        vector<pair<ll, ll>> temp;
        temp.push_back(make_pair(get<0>(triangles[index]), get<2>(triangles[index])));
        index++;
        while (index < N && get<1>(triangles[index]) == get<1>(triangles[index - 1])) {
            temp.push_back(make_pair(get<0>(triangles[index]), get<2>(triangles[index])));
            index++;
        }
        if (temp.size() > 1) {
            yCoords.push_back(temp);
            yCurrent++;
        }
    }





    ll l, r, size, amount;
    for (int i = 0; i < xCurrent; i++) {
        sort(xCoords[i].begin(), xCoords[i].end());
        l = xCoords[i][0].first;
        r = 0;
        size = 1;
        for (int j = 1; j < xCoords[i].size(); j++) {
            r += xCoords[i][j].first - xCoords[i][0].first;
        }

        counts[xCoords[i][0].second][0] = r;

        for (int j = 1; j < xCoords[i].size(); j++) {
            r -= (xCoords[i].size() - size) * (xCoords[i][j].first - xCoords[i][j-1].first);
            counts[xCoords[i][j].second][0] = r + size * xCoords[i][j].first - l;
            l += xCoords[i][j].first;
            size++;
        }
    }

    for (int i = 0; i < yCurrent; i++) {
        sort(yCoords[i].begin(), yCoords[i].end());
        l = yCoords[i][0].first;
        r = 0;
        size = 1;
        for (int j = 1; j < yCoords[i].size(); j++) {
            r += yCoords[i][j].first - yCoords[i][0].first;
        }

        counts[yCoords[i][0].second][1] = r;

        for (int j = 1; j < yCoords[i].size(); j++) {
            r -= (yCoords[i].size() - size) * (yCoords[i][j].first - yCoords[i][j-1].first);
            counts[yCoords[i][j].second][1] = r + size * yCoords[i][j].first - l;
            l += yCoords[i][j].first;
            size++;
        }
    }
    
    ll ans = 0;

    for (int i = 0; i < N; i++) {
        ans = (ans + counts[i][0] * counts[i][1]) % MOD;
    }
    cout << ans;


}








/*#include <iostream>
#include <vector>
#include <array>
#include <fstream>
using namespace std;

int main() {
    //ifstream cin("triangles.in");
    //ofstream cout("triangles.out");
    int N, a, b, temp = -1; 
    cin >> N;
    typedef tuple<int, int, int> coordinate;
    coordinate post_x[N];
    coordinate post_y[N];
    int spot[N][2];
    vector<int> x_connection[N];
    vector<int> y_connection[N];
    for (int i = 0; i < N; i++) {
        cin >> spot[i][0] >> spot[i][1];
        post_x[i] = {spot[i][0], spot[i][1], i};
        post_y[i] = {spot[i][1], spot[i][0], i};
    } 
    
    sort(post_x, post_x + N);
    sort(post_y, post_y + N);
    for (int i = 0; i < N-1; i++) {
        if (i <= temp) {
            continue;
        }
        temp = i;
        while (get<0>(post_x[temp+1]) == get<0>(post_x[i])) {
            temp += 1;
        }
        if (temp > i) {
            for (int j = i; j < temp; j++) {
                for (int k = j+1; k < temp+1; k++) {
                    x_connection[get<2>(post_x[j])].push_back(get<2>(post_x[k]));
                    x_connection[get<2>(post_x[k])].push_back(get<2>(post_x[j]));
                }
            }
        }
    } temp = -1;
    for (int i = 0; i < N-1; i++) {
        if (i <= temp) {
            continue;
        } 
        temp = i;
        while (get<0>(post_y[temp+1]) == get<0>(post_y[i])) {
            temp += 1;
        }
        if (temp > i) {
            for (int j = i; j < temp; j++) {
                for (int k = j+1; k < temp+1; k++) {
                    y_connection[get<2>(post_y[j])].push_back(get<2>(post_y[k]));
                    y_connection[get<2>(post_y[k])].push_back(get<2>(post_y[j]));
                }
            }
        } 
    } 
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < x_connection[i].size(); j++) {
            for (int k = 0; k < y_connection[i].size(); k++) {
                answer += abs((spot[i][1] - spot[x_connection[i][j]][1]) * (spot[i][0] - spot[y_connection[i][k]][0]));
                answer = answer%1000000007;
            }
        }
    } cout << answer;
}
*/