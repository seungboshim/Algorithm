#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int>> graph;

void DFS() {
	vector<bool> visited;
	visited.resize(N + 1, false);

	stack<int> s;
	s.push(V);

	while (!s.empty()) {
		int curr = s.top();
		s.pop();

		if (visited[curr] == false) {
			visited[curr] = true;
			cout << curr << " ";

			sort(graph[curr].begin(), graph[curr].end());

			for (int i = graph[curr].size() - 1; i >= 0 ; i--)
			{
				int k = graph[curr][i];
				if (visited[k] == false) {
					s.push(k);
				}
			}
		}
	}
}

void BFS() {
	vector<bool> visited;
	visited.resize(N + 1, false);

	queue<int> q;
	q.push(V);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (visited[curr] == false) {
			visited[curr] = true;
			cout << curr << " ";

			sort(graph[curr].begin(), graph[curr].end());

			for (int i = 0; i < graph[curr].size(); i++)
			{
				int k = graph[curr][i];
				if (visited[k] == false) {
					q.push(k);
				}
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	graph.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS();
	cout << endl;
	BFS();
	return 0;
}