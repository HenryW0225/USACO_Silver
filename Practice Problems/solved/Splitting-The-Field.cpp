#include <iostream>
#include <array>
#include <algorithm>
#include <fstream>
using namespace std;

typedef long long ll;

int main() {
    ifstream cin("split.in");
    ofstream cout("split.out");
    ll N, a, b, original;
    ll ans = 10e17;
    cin >> N;
    pair<ll, ll> cows[N];
    ll cowsUp[N], cowsDown[N];
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        cows[i] = make_pair(a, b);
    }
    
    sort(cows, cows + N);
    original = cows[N-1].first - cows[0].first;
    
    ll smallest = 10e9, largest = 0;
    for (int i = 0; i < N; i++) {
        smallest = min(smallest, cows[i].second);
        largest = max(largest, cows[i].second);
        cowsUp[i] = (largest - smallest) * (cows[i].first - cows[0].first);
    } 

    smallest = 10e9;
    largest = 0;
    for (int i = N-1; i > -1; i--) {
        smallest = min(smallest, cows[i].second);
        largest = max(largest, cows[i].second);
        cowsDown[i] = (largest - smallest) * (cows[N-1].first - cows[i].first);
    } 

    for (int i = 0; i < N-1; i++) {
        ans = min(ans, cowsUp[i] + cowsDown[i + 1]);
    }

    sort(cows, cows + N, [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
        if (a.second != b.second)
            return a.second < b.second;
            return a.first < b.first;
    });
    original *= cows[N-1].second - cows[0].second;
    ans = min(ans, original);

    smallest = 10e9;
    largest = 0;
    for (int i = 0; i < N; i++) {
        smallest = min(smallest, cows[i].first);
        largest = max(largest, cows[i].first);
        cowsUp[i] = (largest - smallest) * (cows[i].second - cows[0].second);
    } 
    
    smallest = 10e9;
    largest = 0;
    for (int i = N-1; i > -1; i--) {
        smallest = min(smallest, cows[i].first);
        largest = max(largest, cows[i].first);
        cowsDown[i] = (largest - smallest) * (cows[N-1].second - cows[i].second);
    }   

    for (int i = 0; i < N-1; i++) {
        ans = min(ans, cowsUp[i] + cowsDown[i+1]);        
    } 

    cout << original - ans;
}
