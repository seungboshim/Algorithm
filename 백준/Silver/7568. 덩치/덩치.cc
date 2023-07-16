#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (2 > n || n > 50) {
		cout << "input value error!" << endl;
		return 0;
	}
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (10 > x || x > 200 || 10 > y || y > 200) {
			cout << "input value error!" << endl;
			break;
		}
		v.push_back(pair<int, int>(x, y));
	}

	vector<int> rank(n, 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				// i번째가 j번쨰 사람보다 덩치가 작다
				rank[i]++; // i번째의 rank를 +1
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << rank[i] << " ";
	}

	return 0;
}