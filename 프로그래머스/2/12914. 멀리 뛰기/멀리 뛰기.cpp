#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    // dp 같은디..
    long long dp[2001];
    dp[0] = 0;
    dp[1] = 1; // 1
    dp[2] = dp[1]+1; // 11 2
    dp[3] = dp[2]+dp[1]; // 111 21 12
    dp[4] = dp[3]+dp[2]; // 1111 211 121 112 22
    
    for (int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }

    long long answer = dp[n];
    return answer;
}