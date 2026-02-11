#include <iostream>
#include <array>
#include <fstream>
#include <map>
using namespace std;

// A = 0, G = 1, C = 2, T = 3;

int main() {
  ifstream cin ("cownomics.in");
  ofstream cout ("cownomics.out");
  int N, M, ans = 0;
  cin >> N >> M;
  char genomes[1000][50];
  for (int i = 0; i < 2*N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> genomes[i][j];
    }
  } map<char, int> values = {{'A', 0}, {'G', 1}, {'C', 2}, {'T', 3}};
  for (int i = 0; i < M-2; i++) {
    for (int j = i+1; j < M-1; j++) {
      for (int k = j+1; k < M; k++) {
        int count1 = 0;
        int temp1[64] = {0};
        int temp2[64] = {0};
        for (int l = 0; l < N; l++) {
          temp1[values[genomes[l][i]]*16+values[genomes[l][j]]*4+values[genomes[l][k]]] = 1;
        } for (int l = N; l < 2*N; l++) {
          temp2[values[genomes[l][i]]*16+values[genomes[l][j]]*4+values[genomes[l][k]]] = 1;
        } for (int i = 0; i < 64; i++) {
          if (temp1[i] == 0 or temp2[i] == 0) {
            continue;
          } else {
            count1 = 1;
            break;
          }
        } if (count1 == 0) {
          ans += 1;
        }
      }
    }
  } cout << ans;
}
