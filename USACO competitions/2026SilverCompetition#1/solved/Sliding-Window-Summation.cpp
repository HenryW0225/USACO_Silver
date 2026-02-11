#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int T, N, K;
    string information;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> K;
        cin >> information;

        int worse = 0, best = 0, smallestDifference = 1000000, parity = 0;
        
        for (int i = 0; i < K; i++) {
            int current0 = 0, current1 = 1;
            int sum0 = 0, sum1 = 1;

            
            for (int j = 0; i + j * K + 1 < N - K + 1; j++) {
                if (information[i + j * K] != information[i + j * K + 1]) {
                    current0 = 1 - current0;
                    current1 = 1 - current1;
                }
                sum0 += current0;
                sum1 += current1;
            }

            if (sum1 >= sum0) {
                parity++;
            }
            best += max(sum0, sum1);
            worse += min(sum0, sum1);
            smallestDifference = min(smallestDifference, abs(sum0 - sum1));
        }

        //cout << best << " " << worse << " " << smallestDifference << " " << parity << endl;
        int temp = information[0] - '0';
        if (temp == (K - parity)%2) {
            cout << worse;
        } else {
            cout << worse + smallestDifference;
        }

        cout << " ";

        
        if (temp == parity%2) {
            //cout << " HI";
            cout << best << endl;
        } else {
            cout << best - smallestDifference << endl;
        }


    }
}