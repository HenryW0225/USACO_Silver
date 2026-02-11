#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
using namespace std;


int main() {
    ifstream cin("lemonade.in");
    ofstream cout("lemonade.out");
    int N;
    cin >> N;
    int cows[N];
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    } sort(cows, cows + N);
    int answer = 0;
    for (int i = N-1; i > -1; i--) {
        if (cows[i] >= answer) {
            answer += 1;
        }
    } cout << answer;
}
