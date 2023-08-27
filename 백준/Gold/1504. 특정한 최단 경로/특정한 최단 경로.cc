#include <iostream>
#include <vector>
using namespace std;

#define INF 999999999

int N, E;
int weight[801][801];
bool S[801];
int Dist[801];

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			weight[i][j] = INF;
			weight[j][i] = INF;
		}
	}
}

void dijkstra(int v) {
	for (int i = 1; i <= N; i++)
	{
		S[i] = false;
		Dist[i] = weight[v][i];
	}
	S[v] = true;
	Dist[v] = 0;
	for (int i = 1; i <= N; i++)
	{
		int minDist = INF;
		int u = -1;

		for (int w = 1; w <= N; w++)
		{
			if (!S[w] && Dist[w] < minDist) {
				minDist = Dist[w];
				u = w;
			}
		}
		if (u == -1) break;
		S[u] = true;
		for (int w = 1; w <= N; w++)
		{
			if (S[w] == false) {
				if (Dist[w] > Dist[u] + weight[u][w]) {
					Dist[w] = Dist[u] + weight[u][w];
				}
			}
		}
	}
}

int main() {
	cin >> N >> E;
	init(); // weight 초기화
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		if (weight[a][b] > c) {
			weight[a][b] = c;
			weight[b][a] = c;
		}
	}

	int v1, v2;
	cin >> v1 >> v2;

	dijkstra(1); // Dist: 1 ~ 각 노드 최단거리
	int start_V1 = Dist[v1];
	int start_V2 = Dist[v2];
	if (start_V1 >= INF || start_V2 >= INF) {
		cout << -1 << '\n';
		return 0;
	}

	dijkstra(v1); // Dist: v1 ~ 각 노드 최단거리
	int V1_V2 = Dist[v2];
	int V1_N = Dist[N];

	dijkstra(v2); // Dist: v2 ~ 각 노드 최단거리
	int V2_V1 = Dist[v1];
	int V2_N = Dist[N];

	if (V1_V2 >= INF || V1_N >= INF || V2_V1 >= INF || V2_N >= INF) {
		cout << -1 << "\n";
		return 0;
	}

	int result = min(start_V1 + V1_V2 + V2_N, start_V2 + V2_V1 + V1_N);
	cout << result << "\n";
	
	return 0;
}