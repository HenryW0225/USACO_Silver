#include <iostream>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <vector>
using namespace std;

int G, N;
vector<tuple<long long, long long, long long>> gardens;
vector<tuple<long long, long long, long long>> alibi;

bool make(int location1, int location2) {
    long long distance = (get<1>(alibi[location1]) - get<1>(gardens[location2])) * (get<1>(alibi[location1]) - get<1>(gardens[location2])) + (get<2>(alibi[location1]) - get<2>(gardens[location2])) * (get<2>(alibi[location1]) - get<2>(gardens[location2]));
    if (distance > (get<0>(gardens[location2]) - get<0>(alibi[location1])) * (get<0>(gardens[location2]) - get<0>(alibi[location1]))) {
        return false;
    }
    return true;
}
bool get(int location1, int location2) {
    long long distance = (get<1>(alibi[location1]) - get<1>(gardens[location2])) * (get<1>(alibi[location1]) - get<1>(gardens[location2])) + (get<2>(alibi[location1]) - get<2>(gardens[location2])) * (get<2>(alibi[location1]) - get<2>(gardens[location2]));
    if (distance > (get<0>(alibi[location1]) - get<0>(gardens[location2])) * (get<0>(alibi[location1]) - get<0>(gardens[location2]))) {
        return false;
    }
    return true;
}

int main() {
    long long a, b, c;
    cin >> G >> N;

    for (int i = 0; i < G; i++) {
        cin >> a >> b >> c;
        gardens.push_back(make_tuple(c, a, b));
    }
    sort(gardens.begin(), gardens.end());

    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        alibi.push_back(make_tuple(c, a, b));
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (get<0>(alibi[i]) < get<0>(gardens[0])) {
            if (!make(i, 0)) {
                ans++;
            }
        } 
        else if (get<0>(alibi[i]) >= get<0>(gardens[G-1])) {
            if (!get(i, G-1)) {
                ans++;
            }
        } 
        else {
            int low = 0, high = G-1;
            while (low < high) {
		        int mid = low + (high - low)/2;
		        if (get<0>(alibi[i]) < get<0>(gardens[mid])) {
			        high = mid;
		        } else {
			        low = mid + 1;
		        }
	        }
            if (!make(i, low) or !get(i, low-1)) {
                ans++;
            }
        }
    }
    cout << ans;
}