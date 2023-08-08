#include <iostream>
#include <vector>
using namespace std;

int N;
int dp[1000001] = { 0 };
int memo[1000001] = { 0 };
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	dp[2] = 1;
	dp[3] = 1;
	memo[2] = 1;
	memo[3] = 1;
	memo[1] = 0;

	for (int i = 4; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		memo[i] = i - 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) { // 2의배수
			dp[i] = dp[i / 2] + 1;
			memo[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			memo[i] = i / 3;
		}
	}

	cout << dp[N] << "\n";

	while (N > 0) {
		cout << N << " ";
		N = memo[N];
	}

	cout << flush;
	return 0;
}