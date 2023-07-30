#include <iostream>
#include <vector>
#include <algorithm>
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

	int time = 0;
	int times = 0;
	for (int i = 0; i < N; i++)
	{
		time += v[i];
		times += time;
	}
	cout << times << "\n";
	return 0;
}