#include <iostream>
#include <array>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("socdist.in");
    ofstream cout("socdist.out");
    int N, M;
    long long a, b;
    cin >> N >> M;
    pair<long long, long long> patches[M];
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        patches[i] = make_pair(a, b);
    }
    sort(patches, patches + M);
    long long length = patches[M-1].second - patches[0].first + 1;
    long long p = ((length - N)/(N-1) + 1)/2;
    length = 0;
    long long temp, count, current;
    while (true) {
        temp = length + p;
        current = -1;
        count = 0;
        for (int i = 0; i < M; i++) {
            if (current <= patches[i].first) {
                count += (patches[i].second - patches[i].first)/(temp) + 1;
                current = patches[i].first + (patches[i].second - patches[i].first)/(temp) * temp + temp;
            } else if (current > patches[i].first and current <= patches[i].second) {
                count += (patches[i].second - current)/(temp) + 1;
                current = current + (patches[i].second - current)/(temp) * temp + temp;
            }
        }
        if (count < N) {
            if (p == 1) {
                break;
            }
            p = max((long long) 1, p/2);
        } else {
            length = temp;
        }
    }
    cout << length;
}
