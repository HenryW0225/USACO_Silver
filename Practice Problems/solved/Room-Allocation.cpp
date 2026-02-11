#include <iostream>
#include <array>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N, a, b;
    cin >> N;
    pair<pair<int, int>, int> guests[N];
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        guests[i].first = make_pair(a, b);
        guests[i].second = i;
    }
    sort(guests, guests + N);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int answers[N];
    int maxSize = 0, room;
    
    for (int i = 0; i < N; i++) {
        if (pq.empty() || pq.top().first >= guests[i].first.first) {
            maxSize++;
            pq.push(make_pair(guests[i].first.second, maxSize));
            answers[guests[i].second] = maxSize;
        }
        else {
            room = pq.top().second;
            pq.pop();
            pq.push(make_pair(guests[i].first.second, room));
            answers[guests[i].second] = room;
        }
    }

    cout << maxSize << endl;
    for (auto it : answers) {
        cout << it << " ";
    }
}