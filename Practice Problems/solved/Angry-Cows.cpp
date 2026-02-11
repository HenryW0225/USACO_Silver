#include <iostream>
#include <array>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("angry.in");
    ofstream cout("angry.out");
    int N, K;
    cin >> N >> K;
    int haybales[N];
    for (int i = 0; i < N; i++) {
        cin >> haybales[i];
    }
    sort(haybales, haybales + N);
    int largest = (haybales[N-1] - haybales[0] + 1)/(2*K) + 1;
    int p = largest/2;
    int count = 0;
    int range = -1;
    while (true) {
        int temp = largest - p;
        count = 0;
        range = -1;
        for (int i = 0; i < N; i++) {
            if (haybales[i] <= range) {
                continue;
            } else {
                count += 1;
                range = haybales[i] + 2*temp;
            }
        }
        if (count > K) {
            if (p == 1) {
                break;
            }
            p = max(p/2, 1);
        } 
        else {
            largest = temp;
            p = max(p/2, 1);
        }
    } cout << largest;
}
