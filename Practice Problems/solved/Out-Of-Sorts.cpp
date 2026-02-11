#include <iostream>
#include <array>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    ifstream cin ("sort.in");
    ofstream cout ("sort.out");
    int N, temp;
    cin >> N;
    pair<int, int> cows[N];
    for (int i = 0; i < N; i++) {
        cin >> temp;
        cows[i] = make_pair(temp, i);
    }
    sort(cows, cows + N);
    int ans = 1;

    for (int i = 0; i < N; i++) {
        ans = max(ans, cows[i].second - i + 1);
    }
    cout << ans;
    
}



/* #include <iostream>
#include <array>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    //ifstream cin ("sort.in");
    //ofstream cout ("sort.out");
    int N;
    cin >> N;
    int cows[N];
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    bool sorted = false;
    int count = 0, temp;
    while (!sorted) {
        count += 1;
        sorted = true;
        for (int i = 0; i < N-1; i++) {
            if (cows[i] > cows[i+1]) {
                temp = cows[i];
                cows[i] = cows[i+1];
                cows[i+1] = temp;
                sorted = false;
            }
        }
    }
    cout << count;
} */