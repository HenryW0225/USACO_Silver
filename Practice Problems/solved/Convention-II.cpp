#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <queue>
using namespace std;


typedef pair<int, int> Point;

bool special_sort(Point p, Point q) {
    if (p.first == q.first) {
        return p.second > q.second;
    } return p.first < q.first;
}

int main() {
    ifstream cin("convention2.in");
    ofstream cout("convention2.out");
    int N, ans = 0;
    cin >> N;
    int times[N];
    int visits[N];
    Point arrival[N];
    priority_queue<int> seniors;
    for (int i = 0; i < N; i++) {
        cin >> visits[N-1-i] >> times[N-1-i];
        arrival[i] = make_pair(visits[N-1-i], N-i);
    } 
    
    //cout << endl;
    sort(arrival, arrival + N, special_sort);
    /*for (int i = 0; i < N; i++) {
        cout << arrival[i].first << " " << arrival[i].second << endl;
    } for (int i = 0; i < N; i++) {
        cout << times[i] << " ";
    } cout << endl;
    for (int i = 0; i < N; i++) {
        cout << visits[i] << " ";
    } cout << endl;*/
    
    
    int current_time = arrival[0].first;
    int current = arrival[0].second-1;
    int temp = 1;
    for (int i = 0; i < N; i++) {
        current_time += times[current];
        //cout << current_time << " " << current << endl;
        if (seniors.size() != 0) {
            seniors.pop();
        } 
        while (current_time >= arrival[temp].first) {
            seniors.push(arrival[temp].second);
            if (temp == N - 1) {
                break;
            } 
            temp += 1;
        } ans = max(ans, current_time - visits[current] - times[current]);
        //cout << ans << endl;
        if (seniors.size() != 0) {
            current = seniors.top() - 1;
        } else {
            current = temp;
        }
        //cout << current << endl;
        //ans = max(ans, current_time - times[arrival[current].second - 1]);
    } cout << ans;
    
}



#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <queue>
using namespace std;


typedef pair<int, int> Point;

bool special_sort(Point p, Point q) {
    if (p.first == q.first) {
        return p.second > q.second;
    } return p.first < q.first;
}

int main() {
    ifstream cin("convention2.in");
    ofstream cout("convention2.out");
    int N, ans = 0;
    cin >> N;
    int times[N];
    int visits[N];
    Point arrival[N];
    priority_queue<int> seniors;
    for (int i = 0; i < N; i++) {
        cin >> visits[N-1-i] >> times[N-1-i];
        arrival[i] = make_pair(visits[N-1-i], N-i);
    } 
    
    //cout << endl;
    sort(arrival, arrival + N, special_sort);
    /*for (int i = 0; i < N; i++) {
        cout << arrival[i].first << " " << arrival[i].second << endl;
    } for (int i = 0; i < N; i++) {
        cout << times[i] << " ";
    } cout << endl;
    for (int i = 0; i < N; i++) {
        cout << visits[i] << " ";
    } cout << endl;*/
    
    
    int current_time = arrival[0].first;
    int current = arrival[0].second-1;
    int temp = 1;
    for (int i = 0; i < N; i++) {
        current_time += times[current];
        //cout << current_time << " " << current << endl;
        if (seniors.size() != 0) {
            seniors.pop();
        } 
        while (current_time >= arrival[temp].first) {
            seniors.push(arrival[temp].second);
            if (temp == N - 1) {
                break;
            } 
            temp += 1;
        } ans = max(ans, current_time - visits[current] - times[current]);
        //cout << ans << endl;
        if (seniors.size() != 0) {
            current = seniors.top() - 1;
        } else {
            current = temp;
            current_time = visits[current];
        }
        //cout << current << endl;
        //ans = max(ans, current_time - times[arrival[current].second - 1]);
    } cout << ans;
}






#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> Point;

bool special_sort(Point p, Point q) {
    if (p.first == q.first) {
        return p.second > q.second;
    } return p.first < q.first;
}

int main() {
    ifstream cin("convention2.in");
    ofstream cout("convention2.out");
    int N, ans = 0;
    cin >> N;
    int times[N];
    int visits[N];
    Point arrival[N];
    priority_queue<int> seniors;
    for (int i = 0; i < N; i++) {
        cin >> visits[N-1-i] >> times[N-1-i];
        arrival[i] = make_pair(visits[N-1-i], N-i-1);
    } 

    sort(arrival, arrival + N, special_sort);
    int current_time = 0;
    int current = 0;
    int temp = 0;
    for (int i = 0; i < N; i++) {
        if (seniors.size() == 0) {
            current = arrival[temp].second;
            current_time = visits[arrival[temp].second];
            temp += 1;
        } else {
            current = seniors.top();
            seniors.pop();
        }
        current_time += times[current];
        while (current_time >= arrival[temp].first) {
            seniors.push(arrival[temp].second);
            if (temp == N - 1) {
                break;
            } 
            temp += 1;
        } ans = max(ans, current_time - visits[current] - times[current]);
    } cout << ans;
}
