import sys
import heapq
input = sys.stdin.readline

[N, D] = list(map(int, input().strip().split(' ')))
INF = 10001
graph = [[i-j for i in range(D+1)] for j in range(D+1)]

for _ in range(N):
  road = list(map(int, input().strip().split(' ')))
  [start, end, dist] = road
  if start>=0 and end<=D: 
    graph[start][end] = min(graph[start][end], dist)

def dijkstra(D):
  distance = [INF for _ in range(D+1)]
  distance[0] = 0 # 출발 노드
  pq = [(0, 0)] # 최소힙

  while (len(pq) > 0):
    curr, dist = heapq.heappop(pq)
    if distance[curr] < dist: continue
    for i in range(D+1):
      if graph[curr][i] >= 0:
        newDist = dist + graph[curr][i]
        if newDist < distance[i]:
          distance[i] = newDist
          heapq.heappush(pq, (i, newDist))
  return distance[D]

result = dijkstra(D)
print(result)