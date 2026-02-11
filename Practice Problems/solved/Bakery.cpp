#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    int T; 
    cin >> T;
    long long answers[T];

    for (int t = 0; t < T; t++) {
        long long N, C, M;
        cin >> N >> C >> M;
        long long orders[N][3];
        for (int i = 0; i < N; i++) {
            cin >> orders[i][0] >> orders[i][1] >> orders[i][2];
        }

        long long low = 0, high = C + M - 2, mid;
        while (low < high) {
            mid = low + (high - low)/2;
            long long lower_bound = max((long long) 1, C - mid), upper_bound = min((long long) C +  M - mid - 1, C);
            for (int i = 0; i < N; i++) {
                long long value = orders[i][2] - orders[i][1] * (C + M - mid);
                if (orders[i][0] == orders[i][1]) {
                    if (orders[i][0] * (C + M - mid) > orders[i][2]) {
                        low = mid + 1;
                        break;
                    }
                }
                else if (orders[i][0] > orders[i][1]) {
                    value = value/(orders[i][0] - orders[i][1]);
                    upper_bound = min(upper_bound, value);
                }
                else {
                    if (value%(orders[i][0] - orders[i][1]) == 0) {
                        lower_bound = max(lower_bound, value/(orders[i][0] - orders[i][1]));
                    } else {
                        lower_bound = max(lower_bound, value/(orders[i][0] - orders[i][1]) + 1);
                    }
                }
                if (i == N-1) {
                    if (upper_bound >= lower_bound) {
                        high = mid;
                    }
                    else {
                        low = mid + 1;
                    }
                }
            }
        } answers[t] = low;
    }
    for (int i = 0; i < T; i++) {
        cout << answers[i] << endl;
    }
}



/*#include <iostream>
#include <cmath>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    int T;
    cin >> T;
    long long answers[T];
    for (int t = 0; t < T; t++) {
        long long N, C, M;
        cin >> N >> C >> M;
        long long ans = (long long) INFINITY;
        answers[t] = ans;
        long long cows[N][3];
        for (int i = 0; i < N; i++) {
            cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
        }
        long long Clo = 1, Chi = C, Cmid;
        long long Mlo, Mhi, Mmid;
        while (Clo < Chi) {
            Cmid = Clo + (Chi - Clo + 1)/2;
           
            Mlo = 1;
            Mhi = M;


            cout << Cmid << " ";
            while (Mlo < Mhi) {
                Mmid = Mlo + (Mhi - Mlo + 1)/2;
                //cout << Mlo << " " << Mmid << " " << Mhi << endl;
                for (int i = 0; i < N; i++) {
                    if (cows[i][0] * Cmid + cows[i][1] * Mmid > cows[i][2]) {
                        Mhi = Mmid - 1;
                        break;
                    }
                    if (i == N-1) {
                        Mlo = Mmid;
                    }
                } 
            }
            cout << Mlo << endl;
            for (int i = 0; i < N; i++) {
                if (cows[i][0] * Cmid + cows[i][1] * Mlo > cows[i][2]) {
                    Chi = Cmid - 1;
                    break;
                }
                if (i == N-1) {
                    ans = min(ans, C - Cmid + M - Mlo);
                    Clo = Cmid;
                }
            } 
            cout << Clo << " " << Cmid << " " << Chi << " " << ans << endl;
        }
        cout << Clo << " ";
        Mlo = 1;
        Mhi = M;
        while (Mlo < Mhi) {
            Mmid = Mlo + (Mhi - Mlo + 1)/2;
            //cout << Mlo << " " << Mmid << " " << Mhi << endl;
            for (int i = 0; i < N; i++) {
                if (cows[i][0] * Clo + cows[i][1] * Mmid > cows[i][2]) {
                    Mhi = Mmid - 1;
                    break;
                }
                if (i == N-1) {
                    Mlo = Mmid;
                }
            } 
        } cout << Mlo << endl;
        //answers[t] = ans;
        answers[t] = min(ans, C - Clo + M - Mlo);
    }
    for (int i = 0; i < T; i++) {
        cout << answers[i] << endl;
    }
}*/



