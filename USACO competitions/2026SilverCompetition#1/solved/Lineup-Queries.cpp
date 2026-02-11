#include <iostream>
#include <fstream>
using namespace std;

typedef long long ll;
int main() {
    //ifstream cin ("input.txt");
    //ofstream cout ("output.txt");
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int query;
        ll cow, position, time, current;
        cin >> query;
        if (query == 1) {
            cin >> cow >> time;
            if (2 * cow > time) {
                cout << cow << endl;
                continue;
            } 
            position = cow;
            current = 2 * cow - 1;
            while (current + position < time) {
                current = current + position + 1;
                position = current/2;
            } 
            cout << position - time + current << endl;
        }
        if (query == 2) {
            cin >> position >> time;
            if (position > time/2) {
                cout << position << endl;
                continue;
            }

            while ((time - 2 * position)%3 != 2 && time != 0) {
                time -= (time - 2 * position)/3 + 1;
                position = 0;
            }
            if (time == 0) {
                cout << 0 << endl;
            } else {
                cout << position + (time - 2 * position)/3 + 1 << endl;
            }
        }
    }

}