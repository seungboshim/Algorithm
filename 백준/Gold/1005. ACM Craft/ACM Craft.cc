#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, K, W;
vector<int> D;
vector<vector<int>> v;
vector<int> dp; // dp[i]는 건물 i까지 짓기 위한 최소시간
vector<int> indegree;
int result;

void BFS() {
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0) { // 시작 건물들을 큐에
            q.push(i);
            dp[i] = D[i];
        }
    }
    while (!q.empty()) {
        int curr = q.front(); // 시작건물이 curr일 때
        q.pop();

        for (int i = 0; i < v[curr].size(); i++) {
            int next = v[curr][i]; // 다음 갈 건물
            if (next > 0) { // next==0 이면 끝 건물이라 계산 ㄴㄴ
                dp[next] = max(dp[next], dp[curr] + D[next]); // 점화식
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> K; // 건물 갯수 N, 연결수 K
        D.resize(N + 1);
        dp.resize(N + 1);
        indegree.resize(N + 1, 0);
        v.resize(N + 1);
        for (int j = 1; j <= N; j++)
        {
            cin >> D[j]; // 건설시간 D
        }
        for (int k = 1; k <= K; k++)
        {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y); // 건물 연결상태 v (단방향)
            indegree[y]++; // y 건물로 진입할 수 있는 건물수 (진입차수)
        }
        cin >> W;
        BFS();
        cout << dp[W] << "\n";

        D.clear();
        v.clear();
        dp.clear();
    }

    return 0;
}