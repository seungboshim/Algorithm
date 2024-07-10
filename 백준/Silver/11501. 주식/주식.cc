#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stock;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        stock.resize(N, 0); // 벡터 초기화
        for (int i = 0; i < N; i++) {
            cin >> stock[i];
        }

        long long totalProfit = 0;
        int maxVal = stock[N-1]; // 최대값 저장
        for (int i = N-1; i >= 0; i--) { // 뒤에서부터 시작
            if (stock[i] < maxVal) {
                int profit = maxVal - stock[i];
                totalProfit += profit;
                // 지금 값 < 최대값 이면 매도 ㄱㄱ (실제로는 "산다")
            } else { 
                maxVal = stock[i];
                // 아니면 최대값 갱신 (실제로는 "가만히있는다")
            }
        }
        cout << totalProfit << '\n';
    }
}