#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}

	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, string>> v;
	string s;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		int len = s.length();
		v.push_back(make_pair(len, s));
	}
	sort(v.begin(), v.end(), cmp);

	vector<pair<int, string>> newV;
	newV.push_back(v[0]);

	for (int i = 1; i < N; i++)
	{
		if (v[i].second != v[i - 1].second) {
			newV.push_back(v[i]);
		}
	}

	for (int i = 0; i < newV.size(); i++)
	{
		cout << newV[i].second << "\n";
	}
	return 0;
}