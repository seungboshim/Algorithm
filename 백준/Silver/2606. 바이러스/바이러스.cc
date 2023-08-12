#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
vector<vector<int>> net;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	net.resize(N + 1);

	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		net[x].push_back(y);
		net[y].push_back(x);
	}
	
	int cnt = 0;

	vector<bool> visited;
	visited.resize(N + 1, false);

	queue<int> q;
	q.push(1); // 시작 pc
	visited[1] = true;
	vector<int> copy;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < net[curr].size(); i++)
		{
			int next = net[curr][i];
			if (visited[next] == false) {
				copy.resize(q.size(), 0);
				queue<int> q_copy = q;
				while (!q_copy.empty()) {
					copy.push_back(q_copy.front());
					q_copy.pop();
				}

				if (find(copy.begin(), copy.end(), next) == copy.end()) {
					q.push(next);
					visited[next] = true;
					cnt++;
				}
			}
		}
	}

	cout << cnt << "\n";
	return 0;
}