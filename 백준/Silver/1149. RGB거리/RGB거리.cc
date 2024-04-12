#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int paint[1001][3];
int dp[3]; // 마지막 집의 R,G,B 선택시 저장될 색

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> paint[i][j];
        }
    }

    dp[0] = paint[0][0]; // 첫 집을 R
    dp[1] = paint[0][1]; // G
    dp[2] = paint[0][2]; // B
    
    for (int i = 1; i < N; i++)
    {
        int red = paint[i][0];
        int green = paint[i][1];
        int blue = paint[i][2];

        int pickR = min(dp[1]+red, dp[2]+red); // GR, BR
        int pickG = min(dp[0]+green, dp[2]+green); // RG, BG
        int pickB = min(dp[0]+blue, dp[1]+blue); // RB, GB

        dp[0] = pickR;
        dp[1] = pickG;
        dp[2] = pickB;
    }
    
    sort(dp, dp+3);
    cout << dp[0] << endl;
    return 0;
}