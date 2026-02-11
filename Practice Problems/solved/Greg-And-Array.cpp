/*#include <iostream>
#include <array>
using namespace std;

int main() {
    int N, M, K, temp1, temp2;
    cin >> N >> M >> K;
    long long number[N] = {0};
    long long additions[N+1] = {0};
    int operation[M][3] = {0};
    int amounts[M+1] = {0};
    for (int i = 0; i < N; i++) {
        cin >> number[i];
    } for (int i = 0; i < M; i++) {
        cin >> operation[i][0] >> operation[i][1] >> operation[i][2];
    } for (int i = 0; i < K; i++) {
        cin >> temp1 >> temp2;
        amounts[temp2] += 1;
        amounts[temp1 - 1] -= 1;
    }
    for (int i = M-1; i > 0; i--) {
        amounts[i] += amounts[i+1];
    } 
    for (int i = 0; i < M; i++) {
        additions[operation[i][0]-1] -= (long long) operation[i][2] * amounts[i+1];
        additions[operation[i][1]] += (long long) operation[i][2] * amounts[i+1];
    } 
    for (int i = N-1; i > 0; i--) {
        additions[i] += additions[i+1];
    } for (int i = 0; i < N; i++) {
        cout << number[i] + additions[i+1] << " "; 
    }
}*/