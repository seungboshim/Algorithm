#include <iostream>
#include <vector>
using namespace std;

int N, X;
vector<int> days;

int main() {
  cin >> N >> X;
  days.resize(N);
  for (int i = 0; i < N; i++)
  {
    cin >> days[i];
  }

  int sum = 0; // 현재 윈도우 방문자 합
  int result = 1; // 최대인 기간 갯수

  for (int i = 0; i < X; i++)
  {
    sum += days[i];
  }
  int maxSum = sum;
  

  for (int i = 0; i < N; i++)
  {
    if (i+X > N) break;
    // i=3, X=2, N=5
    // 0 1 2 3 4 -> 3 4

    sum = sum - days[i] + days[i+X];
    if (sum > maxSum) {
      maxSum = sum;
      result = 1;
    } else if (sum == maxSum) {
      result++;
    }
  }

  if (maxSum == 0) {
    cout << "SAD\n";
    return 0;
  }

  cout << maxSum << "\n" << result << "\n";
  return 0;
}