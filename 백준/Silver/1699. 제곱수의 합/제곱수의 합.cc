#include <iostream>
#include <cmath>
using namespace std;

int dp[100001]; // 각 n에 대한 최소제곱수 갯수

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        double k = sqrt(i);
        if (k == (int)k) { // i가 제곱수 일 때?
            dp[i] = 1;
            continue;
        }
        dp[i] = dp[i-1]+1;

        // N==13일 때?
        // (int)k = 3
        for (int j = (int)k; j > 0; j--) {
            dp[i] = min(dp[i], dp[j*j] + dp[i-j*j]);
        }
    }
    
    cout << dp[N] << endl;
}