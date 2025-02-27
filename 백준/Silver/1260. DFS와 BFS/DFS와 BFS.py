import sys
input = sys.stdin.readline

[N, M, V] = list(map(int, input().strip().split(' ')))
graph = [[] for _ in range(N+1)]
for _ in range(M):
  [u, v] = list(map(int, input().strip().split(' ')))
  graph[u].append(v)
  graph[v].append(u)

def dfs(N, V, graph):
  stack = [V]
  visited = [False for _ in range(N+1)]
  result = []
  while(len(stack) > 0):
    curr = stack.pop()
    if not visited[curr]:
      visited[curr] = True
      result.append(curr)
    for node in reversed(sorted(graph[curr])):
      if not visited[node]:
        stack.append(node)
  
  result = list(map(str, result))
  return result

def bfs(N, V, graph):
  queue = [V]
  visited = [False for _ in range(N+1)]
  result = []

  while(len(queue) > 0):
    curr = queue.pop(0)
    if not visited[curr]:
      visited[curr] = True
      result.append(curr)
    for node in sorted(graph[curr]):
      if not visited[node]:
        queue.append(node)
  
  result = list(map(str, result))
  return result

print(' '.join(dfs(N,V,graph)))
print(' '.join(bfs(N,V,graph)))