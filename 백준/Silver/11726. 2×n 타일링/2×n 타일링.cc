#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll dp[1001];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    if (n > 3) {
        for (int i = 4; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] = dp[i]%10007;
        }
        cout << dp[n] << endl;
    } else {
        cout << dp[n] << endl;
    }
    return 0;
}