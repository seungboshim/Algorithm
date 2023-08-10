#include <iostream>
using namespace std;

int room[17][17] = { 0 };
int dir[290] = { 0 };
int dp[17][17][3] = { 0 };

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> room[i][j];
        }
    }

    dir[1] = 1; // 첫 파이프는 가로(0)로 놓임
    dp[1][2][0] = 1; // (1,2)를 끝점으로 가로로 놓인 시작 파이프

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int idx = (i - 1) * N + j;
            if (room[i][j] != 1) { // 벽 아닌 칸에서
                if (room[i][j + 1] != 1) { // 가로로 놓을 수 있을때
                    dir[idx] |= 1 << 0; // 001
                }
                if (room[i + 1][j] != 1) { // 세로로 놓을 수 있을때
                    dir[idx] |= 1 << 1; // 010
                }
                if (room[i][j + 1] != 1 && room[i + 1][j] != 1 && room[i + 1][j + 1] != 1) { // 대각선
                    dir[idx] |= 1 << 2; // 100
                }
            }


            if (dir[idx] == 1 || dir[idx] == 3 || dir[idx] == 7) { // 가로로 놓기
                dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2];
            }
            if (dir[idx] == 2 || dir[idx] == 3 || dir[idx] == 7) { // 세로로 놓기
                dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2];
            }
            if (dir[idx] == 4 || dir[idx] == 6 || dir[idx] == 7) { // 대각선
                dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            }
        }
    }

    int result = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    cout << result << "\n";
    return 0;
}
