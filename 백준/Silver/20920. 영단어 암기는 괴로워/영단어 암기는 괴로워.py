import sys
from collections import defaultdict

input = sys.stdin.readline

[N, M] = list(map(int, input().split(' ')))

d = defaultdict(int)

for _ in range(N):
  word = input().strip()
  if len(word) < M: continue
  else:
    d[word] += 1

result = sorted(d.items(), key= lambda x: (-x[1], -len(x[0]), x[0]))

for key, value in result:
  print(key)