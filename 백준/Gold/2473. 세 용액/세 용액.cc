#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

ll N;
ll minVal = 3000000001;
vector<ll> v;

int main() {
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	ll left = 0;
	ll mid = left + 1;
	ll right = N - 1;

	ll tuple_left = v[left];
	ll tuple_mid = v[mid];
	ll tuple_right = v[right];

	for (int i = 0; i < N - 2; i++)
	{
		left = i;
		mid = left + 1;
		right = N - 1;

		while (left < mid && mid < right) {
			ll val = v[left] + v[mid] + v[right];

			if (minVal > abs(val)) { // 혼합 특성값의 최소값 갱신
				minVal = abs(val);
				tuple_left = v[left];
				tuple_mid = v[mid];
				tuple_right = v[right];
			}

			if (val < 0) {
				mid++;
			}
			else {
				right--;
			}
		}
	}


	cout << tuple_left << " " << tuple_mid << " " << tuple_right << "\n";
	return 0;
}