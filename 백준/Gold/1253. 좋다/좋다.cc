#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[2001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(A, A + N);
	
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int isGood = A[i];
		int start = 0;
		int end = N - 1;
		while (start < end) {
			if (start == i) {
				start++;
				continue;
			}
			if (end == i) {
				end--;
				continue;
			}
			int sum = A[start] + A[end];
			if (sum == isGood) {
				cnt++;
				break;
			}
			else if (sum > isGood) {
				end--;
			}
			else if (sum < isGood) {
				start++;
			}
		}
	}

	cout << cnt << endl;
	return 0;
}