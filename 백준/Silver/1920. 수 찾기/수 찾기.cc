#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;

int binarySearch(int key) {
	int end = A.size() - 1;
	int begin = 0;

	while (begin <= end) {
		int pivot = begin + (end - begin) / 2;

		if (A[pivot] == key) return 1;
		else if (A[pivot] < key) {
			begin = pivot + 1;
		}
		else if (A[pivot] > key) {
			end = pivot - 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
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
		cout << binarySearch(key) << '\n';
	}

	return 0;
}