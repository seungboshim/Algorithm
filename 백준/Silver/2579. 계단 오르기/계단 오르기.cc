#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int floor[301] = {0};
    int dp[301] = {0};

    for (int i = 1; i <= N; i++)
    {
        cin >> floor[i];
    }

    dp[1] = floor[1];
    dp[2] = dp[1] + floor[2];
    dp[3] = max(floor[1]+floor[3], floor[2]+floor[3]);
    //dp[4] = max(floor[1]+floor[2]+floor[4], floor[1]+floor[3]+floor[4]);
    //dp[5] = max(dp[3]+floor[5], dp[2]+floor[4]+floor[5]);

    for (int i = 4; i <= N; i++)
    {
        dp[i] = max(dp[i-2]+floor[i], dp[i-3]+floor[i-1]+floor[i]);
    }

    cout << dp[N];
    
}