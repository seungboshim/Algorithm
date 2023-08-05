#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		v.clear();
		for (int j = 0; j < N; j++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		
		sort(v.begin(), v.end());

		int cnt = 1;
		int minVal = v[0].second;
		for (int j = 1; j < N; j++) {
			if (v[j].second < minVal) {
				minVal = v[j].second;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}