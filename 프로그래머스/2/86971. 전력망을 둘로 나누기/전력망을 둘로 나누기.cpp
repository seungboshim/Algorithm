#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> makeGraph(int n, vector<vector<int>> wires, int cutPoint) {
    vector<vector<int>> graph(n+1);
    for (int i=0; i<wires.size(); i++) {
        if (i == cutPoint) continue;
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }
    return graph;
}

int bfs(int n, int start, vector<vector<int>> graph) {
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        cnt++;

        for (int i=0; i<graph[curr].size(); i++) {
            int next = graph[curr][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    // [[1,2],[2,3],[3,4]] 
    
    for (int i=0; i<wires.size(); i++) {
        vector<vector<int>> newWires = makeGraph(n, wires, i); // 자른
        
        int left = bfs(n, 1, newWires); // 자른 섬 저장용
        int right = n - left; // 반대쪽
        
        int diff = abs(left-right);
        answer = min(answer, diff);
    }
    
    return answer;
}