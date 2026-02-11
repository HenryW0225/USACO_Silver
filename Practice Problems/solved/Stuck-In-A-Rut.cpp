#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int N, temp1, temp2;
    char temp;
    cin >> N;
    vector<tuple<int, int, int>> cowsE;
    vector<tuple<int, int, int>> cowsN;
    for (int i = 0; i < N; i++) {
        cin >> temp >> temp1 >> temp2;
        if (temp == 'E') {
            cowsE.push_back(make_tuple(temp2, temp1, i));
        }
        else {
            cowsN.push_back(make_tuple(temp1, temp2, i));
        }
    }
   
    sort(cowsE.begin(), cowsE.end());
    sort(cowsN.begin(), cowsN.end());
    for (int i = 0; i < cowsE.size(); i++) {
        temp1 = get<0>(cowsE[i]);
        get<0>(cowsE[i]) = get<1>(cowsE[i]);
        get<1>(cowsE[i]) = temp1;
    }
   
    /*cout << endl;
    for (auto it : cowsE) {
        cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
    }
    cout << endl;
    for (auto it : cowsN) {
        cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
    }*/
   
    int ex, ey, nx, ny;
    int blocked[N];
    int ans[N];
    for (int i = 0; i < N; i++) {
        blocked[i] = 0;
        ans[i] = 0;
    } 


    for (int i = 0; i < cowsE.size(); i++) {
        ex = get<0>(cowsE[i]);
        ey = get<1>(cowsE[i]);
        for (int j = 0; j < cowsN.size(); j++) {
            nx = get<0>(cowsN[j]);
            ny = get<1>(cowsN[j]);
            if (ex > nx || ey < ny || blocked[get<2>(cowsN[j])] == 1) {
                continue;
            }
           
            if (nx - ex == ey - ny) {
                continue;
            }
           
            if (nx - ex < ey - ny) {
                ans[get<2>(cowsE[i])] += ans[get<2>(cowsN[j])] + 1;
                blocked[get<2>(cowsN[j])] = 1;
            }
            else {
                ans[get<2>(cowsN[j])] += ans[get<2>(cowsE[i])] + 1;
                j = cowsN.size();
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
   
}