#include <iostream>
#include <queue>
using namespace std;

int N, num, result;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			if (pq.size() < N) {
				pq.push(num);
			}
			else if (num > pq.top()) {
				pq.pop();
				pq.push(num);
			}
		}
	}

	result = pq.top();
	cout << result << endl;
	return 0;
}