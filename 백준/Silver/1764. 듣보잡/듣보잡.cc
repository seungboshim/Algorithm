#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	vector<string> v1(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v1[i];
	}

	unordered_set<string> v1_set(v1.begin(), v1.end());


	vector<string> v2(M);
	for (int i = 0; i < M; i++)
	{
		cin >> v2[i];
	}

	vector<string> v3;
	for (int i = 0; i < M; i++)
	{
		string val = v2[i];
		if (v1_set.find(val) != v1_set.end())
			v3.push_back(val);
	}

	sort(v3.begin(), v3.end());
	cout << v3.size() << "\n";
	for (string s : v3) {
		cout << s << "\n";
	}
	return 0;
}