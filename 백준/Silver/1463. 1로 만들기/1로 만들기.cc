#include <iostream>
using namespace std;

int N;
int dp[1000001] = { 0 };

int main() {
	cin >> N;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) { // 2의배수
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0 && (dp[i] == 0 || dp[i] > dp[i / 3] + 1)) {
			dp[i] = dp[i / 3] + 1;
		}
	}

	cout << dp[N] << "\n";
	return 0;
}