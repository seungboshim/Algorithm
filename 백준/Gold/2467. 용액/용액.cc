#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int begin = 0;
	int end = N - 1;
    int minval = abs(v[begin] + v[end]);
	int pair_begin = v[begin];
	int pair_end = v[end];

	while (begin < end) {
		int val = v[begin] + v[end];

		if (minval > abs(val)) {
			minval = abs(val);
			pair_begin = v[begin];
			pair_end = v[end];
		}

		if (val < 0) {
			begin++; 
		}
		else end--;
	}

	cout << pair_begin << " " << pair_end << "\n";
	return 0;
}