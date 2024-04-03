#include <iostream>
using namespace std;

int dp[12] = {0}; // i를 1, 2, 3으로 나타낼 수 있는 가짓수

void solve(int n) {
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
}

int main() {
    int T;
    cin >> T;

    dp[0] = 0;
    dp[1] = 1; // 1
    dp[2] = 2; // 1+1, 2
    dp[3] = 4; // 1+1+1, 1+2, 2+1, 3

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        if (n > 3) {
            solve(n);
            cout << dp[n] << endl;
        } else {
            cout << dp[n] << endl;
        }

    }
    return 0;
}