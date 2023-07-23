#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int maxval = 0;

int main() {
	cin >> N >> M;
	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	maxval = *max_element(v.begin(), v.end());

	int low = maxval;
	int high = maxval * N;

	while (low < high) {
		int mid = (low + high) / 2;
		int cnt = 0;
		int balance = mid;

		for (int i = 0; i < N; i++)
		{
			if (v[i] > balance) {
				cnt++;
				balance = mid;
			}
			balance -= v[i];
		}

		if (cnt < M)
			high = mid;
		else 
			low = mid + 1;
	}
	cout << high << "\n";
	return 0;
}