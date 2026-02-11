/*#include <bits/stdc++.h>
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