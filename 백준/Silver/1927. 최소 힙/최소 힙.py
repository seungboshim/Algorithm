import sys
import heapq
input = sys.stdin.readline

N = int(input())
pq = []

for _ in range(N):
  value = int(input())
  if value == 0:
    if len(pq) > 0:
      print(heapq.heappop(pq))
    else: print(0)
  else:
    heapq.heappush(pq,value)