import sys
input = sys.stdin.readline

[N, K] = list(map(int,input().strip().split(" ")))
visited = [False for _ in range(100001)]
visited[N] = True

queue = [[N,0]] # 현재 위치, 이동 횟수

while(len(queue) > 0):
  [curr,time] = queue.pop(0)
  # print(curr,time)

  if curr == K:
    print(time)
    break

  dx = [-1, 1, curr]
  for x in dx:
    next = curr+x
    if next<0 or 100000<next:
      continue

    if not visited[next]:
      queue.append([next, time+1])
      visited[next] = True
