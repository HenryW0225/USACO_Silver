/*#include <iostream>
#include <array>
using namespace std;

int main() {
    long long N, max = -10e15;
    cin >> N;
    long long numbers[N+1] = {0};
    for (int i = 1; i < N+1; i++) {
        cin >> numbers[i];
        numbers[i] += numbers[i-1];
    } 
    for (int i = 1; i < N+1; i++) {
        if (max < numbers[i] - numbers[i-1]) {
            max = numbers[i] - numbers[i-1];
        } if (numbers[i-1] < numbers[i]) {
            numbers[i] = numbers[i-1];
        }
    } cout << max;
}
*/