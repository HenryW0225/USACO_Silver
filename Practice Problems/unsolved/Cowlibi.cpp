#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    int G, N;
    cin >> G >> N;
    pair<int, int> times[G];
    int other_time[G];
    int locations[G][2];
    for (int i = 0; i < G; i++) {
        cin >> locations[i][0] >> locations[i][1] >> other_time[i];
        times[i] = make_pair(other_time[i], i);
    }
    int excuses[N][3];
    for (int i = 0; i < N; i++) {
        cin >> excuses[i][0] >> excuses[i][1] >> excuses[i][2];
    }
    sort(times, times + G);
    sort(other_time, other_time + G);
    int count = 0;
    int index;
    for (int i = 0; i < N; i++) {
        if (excuses[i][2] <= times[0].first) {
            if (times[0].first - excuses[i][2] >= abs(locations[times[0].second][0] - excuses[i][0]) + abs(locations[times[0].second][1] - excuses[i][1])) {
                count += 1;
            }
            continue;
        } 
        else if (excuses[i][2] >= times[G-1].first) {
            if (excuses[i][2] - times[G-1].first >= abs(locations[times[G-1].second][0] - excuses[i][0]) + abs(locations[times[G-1].second][1] - excuses[i][1])) {
                count += 1;
            }
            continue;
        }
        index = lower_bound(other_time, other_time + G, excuses[i][2]) - other_time;
        if (excuses[i][2] - times[index-1].first >= abs(locations[times[index-1].second][0] - excuses[i][0]) + abs(locations[times[index-1].second][1] - excuses[i][1]) and times[index].first - excuses[i][2] >= abs(locations[times[index].second][0] - excuses[i][0]) + abs(locations[times[index].second][1] - excuses[i][1])) {
            count += 1;
        }
    }
    cout << count;
}
