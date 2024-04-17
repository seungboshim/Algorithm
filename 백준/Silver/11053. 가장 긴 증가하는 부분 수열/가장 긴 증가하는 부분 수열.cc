#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int A[1001];
vector<int> dp; // 자신을 포함한 지금까지의 증가수열 갯수

int main() {
    int N;
    cin >> N;

    dp.resize(N, 1);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    
    // 10 20 50 -> dp[2] = 3
    // 10 11 12 13 -> dp[6] = 4

    // int maxVal = A[0];
    // int maxIdx = 0;
    int result = dp[0]; // 최대 갯수 저장

    for (int i = 1; i < N; i++)
    {
        // if (A[i-1] < A[i]) { // 이전보다 큼
        //     dp[i] = dp[i-1]+1;
        //     if (maxVal < A[i]) {
        //         dp[i] = max(dp[i], dp[maxVal]+1);
        //         maxVal = A[i];
        //         maxIdx = i;
        //     }
        //     result = max(result, dp[i]);

        // } else { // 이전보다 작음
            // 처음부터 현재 것까지 탐색
            for (int j = 0; j < i; j++)
            {
                if (A[j] < A[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        // }
        result = max(result, dp[i]);
    }

    cout << result << "\n";

    return 0;
}