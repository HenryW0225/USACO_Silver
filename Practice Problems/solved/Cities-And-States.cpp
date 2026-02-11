#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream cin ("citystate.in");
  ofstream cout ("citystate.out");
  int n;
  string a, b;
  map<string, int> citystate;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    a = a.substr(0, 2);
    if (a != b) {
      if (citystate.find(a+b) != citystate.end()) {
        citystate[a+b] += 1;
      } else {
        citystate[a+b] = 1;
      }
    }
  } int ans = 0;
  for (auto x : citystate) {
    string other = x.first.substr(2) + x.first.substr(0, 2);
    if (citystate.find(other) != citystate.end()) {
      ans += citystate[x.first]*citystate[other];
    }
  } cout << ans/2;
}
