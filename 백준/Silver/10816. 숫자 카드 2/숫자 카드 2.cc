#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	cin >> M;
	int key;
	for (int i = 0; i < M; i++)
	{
		cin >> key;
		cout << upper_bound(A.begin(), A.end(), key) - lower_bound(A.begin(), A.end(), key) << " ";
	}
	cout << endl;
}