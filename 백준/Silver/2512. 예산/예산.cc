#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> city;

int binarySearch() {
	int begin = 0;
	int end = city[N - 1];
	int budget = 0;

	while (begin <= end) {
		int mid = (begin + end) / 2; // 중간값
		int total = 0;
		for (int i = 0; i < N; i++)
		{
			total += min(city[i], mid); // 작은값부터 큰값 다 더하는데
			// 중간값보다 큰 원소는 중간값을 더함
		}
		if (total <= M) { // 그게 M 이하다
			budget = mid; // 중간값을 예산으로 저장
			begin = mid + 1; // 시작값 +1 하여 반복
		}
		else { // M 넘는다
			end = mid - 1; // 끝값 -1 하여 반복
		}
	}

	return budget;
}

int main() {
	cin >> N;
	city.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> city[i];
	}
	sort(city.begin(), city.end());

	cin >> M;
	cout << binarySearch();
	return 0;
}