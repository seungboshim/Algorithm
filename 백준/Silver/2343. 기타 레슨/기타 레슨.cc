#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int low, high;

int blueray() {
	while (low <= high) {
		int mid = (low + high) / 2;
		int cnt = 0;
		int sum = 0;

		for (int i = 0; i < N; i++)
		{
			if (sum + v[i] > mid) { 
				cnt++;
				sum = 0;
			}
			sum += v[i];
		}
		if (sum > 0) cnt++; 

		if (cnt <= M) { 
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return low;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> N >> M;
	high = 0;

	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		high += v[i];
	}
	low = *max_element(v.begin(), v.end());
	
	cout << blueray();
	return 0;
}