#include <iostream>
#include <vector>
using namespace std;

int arr[501][501];
int dp[501][501];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];
    
    dp[1][0] = dp[0][0] + arr[1][0];
    dp[1][1] = dp[0][0] + arr[1][1];
    
    // dp[2][0] = dp[1][0] + arr[2][0];
    // dp[2][1] = max(dp[1][0], dp[1][1]) + arr[2][1];
    // dp[2][2] = dp[1][1] + arr[2][2];

    // dp[3][0] = dp[2][0] + arr[3][0];
    // dp[3][1] = max(dp[2][0], dp[2][1]) + arr[3][1];
    // dp[3][2] = max(dp[2][1], dp[2][2]) + arr[3][2];
    // dp[3][3] = dp[2][2] + arr[3][3];

    for (int i = 2; i < n; i++)
    {
        dp[i][0] = dp[i-1][0] + arr[i][0];
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
        dp[i][i] = dp[i-1][i-1] + arr[i][i];
    }
    
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, dp[n-1][i]);
    }
    cout << result << "\n";
    return 0;
    
}