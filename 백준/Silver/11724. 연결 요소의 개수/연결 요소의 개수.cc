#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int v) {
    stack<int> s;
    s.push(v);
    
    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        if (!visited[curr]) {
            visited[curr] = true;

            sort(graph[curr].begin(), graph[curr].end());

            for (int i = graph[curr].size() - 1; i >= 0; i--)
            {
                int k = graph[curr][i];

                if (!visited[k]) {
                    s.push(k);
                }
            }
            
        }
    }
}

void checkCycle(int& count, int v) {

    if (!visited[v]) {
        dfs(v);
        count++;
    }
}

int main() {

    cin >> N >> M;
    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int count = 0;

    for (int i = 1; i <= N; i++)
    {
        checkCycle(count, i);
    }

    cout << count << endl;
    return 0;
    
}